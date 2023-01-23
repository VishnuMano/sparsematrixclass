// g++ -std=c++17  -I /Users/vishnumano/Folders/home/coding/sparsematrixclass/eigen-git-mirror benchmark_final.cpp -o a

#include <iostream>
#include <vector>
#include <fstream>
#include <Eigen/SparseCore>

class Timer
{
    public:
        Timer() 
        {
            // Starting time
            std::chrono::steady_clock::time_point m_StartTimepoint = std::chrono::high_resolution_clock::now();
        }

        ~ Timer()
        {
            // Deconstructor calls Stop Function
            Stop();
        }

        void Stop()
        {
            // Ending time
            std::chrono::steady_clock::time_point endTimepoint = std::chrono::high_resolution_clock::now();
            // Casts Start/Stop to Microseconds
            long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
            long long stop = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
            // Calculates Duration in Microseconds
            micro_duration = stop - start;
        }

        long long accessTime()
        {
            return micro_duration;
        }
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
        long long micro_duration;
};

int main()
{
    Eigen::SparseMatrix<double> matrix(3, 5);
    matrix.insert(0, 0) = 0;
    matrix.insert(0, 1) = 0;
    matrix.insert(0, 2) = 1;
    matrix.insert(0, 3) = 0;
    matrix.insert(0, 4) = 3;
    matrix.insert(1, 0) = 3;
    matrix.insert(1, 1) = 2;
    matrix.insert(1, 2) = 0;
    matrix.insert(1, 3) = 1;
    matrix.insert(1, 4) = 0;
    matrix.insert(2, 0) = 0;
    matrix.insert(2, 1) = 1;
    matrix.insert(2, 2) = 0;
    matrix.insert(2, 3) = 0;
    matrix.insert(2, 4) = 0;
    matrix.makeCompressed();
    /*
        0, 0, 1, 0, 3,
        3, 2, 0, 1, 0,
        0, 1, 0, 0, 0;
    */
    std::vector<double> colsums(matrix.cols());
    // Writing Directly to File
    std::ofstream outfile ("times1.txt");
    
    for (size_t a = 0; a < 100; ++a)
    {
        {
            Timer timer;
            for (size_t i = 0; i < matrix.cols(); ++i)
            {
                for (Eigen::SparseMatrix<double>::InnerIterator it(matrix, i); it; ++it)
                {
                    colsums[i] += it.value();
                }
            }
            outfile << timer.accessTime() << std::endl;
        }
    }
    outfile.close();
    for (std::vector<double>::iterator it = colsums.begin(); it != colsums.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}