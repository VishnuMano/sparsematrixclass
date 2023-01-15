#include <iostream>
#include <Eigen/SparseCore>

class Timer
{
    public:
        Timer() 
        {
            m_StartTimepoint = std::chrono::high_resolution_clock::now();
        }

        ~ Timer()
        {
            Stop();
        }

        void Stop()
        {
            auto endTimepoint = std::chrono::high_resolution_clock::now();
            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
            auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
            auto micro_duration = stop - start;
            double milli_duration = micro_duration * 0.001;
            std::cout << micro_duration << " microseconds\n";
            std::cout << milli_duration << " milliseconds\n";
        }
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
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
    // std::cout << matrix.isCompressed();
    std::vector<double> colsums(matrix.cols());
    {
        Timer timer;
        for (size_t i = 0; i < matrix.cols(); ++i)
        {
            for (Eigen::SparseMatrix<double>::InnerIterator it(matrix, i); it; ++it)
            {
                colsums[i] += it.value();
            }
        }
    }
    for (std::vector<double>::iterator it = colsums.begin(); it != colsums.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}