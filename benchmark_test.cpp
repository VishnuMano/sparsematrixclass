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
            // Calculates Duration
            micro_duration = stop - start;
            // double milli_duration = micro_duration * 0.001;
            // std::cout << micro_duration << " microseconds\n";
            // std::cout << milli_duration << " milliseconds\n";
        }

        long long accessTime()
        {
            return micro_duration;
        }
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
        long long micro_duration;
};

void action()
{
    for (size_t i = 0; i < 10; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            std::cout << "Hello" << std::endl;
        }   
    }
}

int main()
{
    // // Adding to Array Then Writing to File
    // int trials = 2;
    // long long time_list[trials];
    // for (size_t a = 0; a < trials; ++a)
    // {
    //     {
    //         Timer time;
    //         action();
    //         time_list[a] = time.accessTime();
    //     }
    // }
    // std::ofstream outfile ("times.txt");
    // for (long long time : time_list)
    // {
    //     outfile << time << std::endl;
    // }
    // outfile.close();


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
    std::ofstream outfile ("times.txt");
    for (size_t a = 0; a < 100; ++a)
    {
        {
            Timer time;
            for (size_t i = 0; i < matrix.cols(); ++i)
            {
                for (Eigen::SparseMatrix<double>::InnerIterator it(matrix, i); it; ++it)
                {
                    colsums[i] += it.value();
                }
            }
            outfile << time.accessTime() << std::endl;
        }
    }
    outfile.close();
    for (std::vector<double>::iterator it = colsums.begin(); it != colsums.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}