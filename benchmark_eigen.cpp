#include <iostream>
#include <Eigen/SparseCore>

using Eigen::Matrix;
using namespace std;

class Timer
{
    public:
        Timer() 
        {
            m_StartTimepoint = chrono::high_resolution_clock::now();
        }

        ~ Timer()
        {
            Stop();
        }

        void Stop()
        {
            auto endTimepoint = chrono::high_resolution_clock::now();
            auto start = chrono::time_point_cast<chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
            auto stop = chrono::time_point_cast<chrono::microseconds>(endTimepoint).time_since_epoch().count();
            auto micro_duration = stop - start;
            double milli_duration = micro_duration * 0.001;
            cout << micro_duration << " microseconds\n";
            cout << milli_duration << " milliseconds\n";
        }
    private:
        chrono::time_point<chrono::high_resolution_clock> m_StartTimepoint;
};

int main()
{
    int columnSum;
    {
        Timer time;
        Eigen::SparseMatrix<int> m(3, 5);
        m.insert(0, 0) = 0;
        m.insert(0, 1) = 0;
        m.insert(0, 2) = 1;
        m.insert(0, 3) = 0;
        m.insert(0, 4) = 3;
        m.insert(1, 0) = 3;
        m.insert(1, 1) = 2;
        m.insert(1, 2) = 0;
        m.insert(1, 3) = 1;
        m.insert(1, 4) = 0;
        m.insert(2, 0) = 0;
        m.insert(2, 1) = 1;
        m.insert(2, 2) = 0;
        m.insert(2, 3) = 0;
        m.insert(2, 4) = 0;
        m.makeCompressed();
        /*  
            0, 0, 1, 0, 3,
            3, 2, 0, 1, 0,
            0, 1, 0, 0, 0;
        */
        Eigen::SparseMatrix<int> m_transposed = m.transpose();
        columnSum = m_transposed.sum();
    }
    std::cout << columnSum << std::endl;
}