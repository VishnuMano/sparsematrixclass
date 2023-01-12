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
    Eigen::Matrix3i m_colsum;
    {
        Timer time;
        Eigen::Matrix<int, 3, 3> m;
        m << 0, 1, 2,
             3, 4, 5,
             6, 7, 8;
    
        std::cout << m.colwise().sum();
    }
    std::cout << m_colsum << std::endl;
}