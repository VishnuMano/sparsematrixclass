#include <iostream>
#include <vector>
#include <fstream>

class Timer
{
    public:
        Timer() 
        {
            // Stores starting time
            std::chrono::steady_clock::time_point m_StartTimepoint = std::chrono::high_resolution_clock::now();
        }

        ~ Timer()
        {
            // Deconstructor calls Stop Function
            Stop();
        }

        void Stop()
        {
            // Stores ending time
            std::chrono::steady_clock::time_point endTimepoint = std::chrono::high_resolution_clock::now();
            // Casts Start/Stop to Microseconds
            long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
            long long stop = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
            // Calculates Duration
            micro_duration = stop - start;
            double milli_duration = micro_duration * 0.001;
            std::cout << micro_duration << " microseconds\n";
            std::cout << milli_duration << " milliseconds\n";
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
    std::ofstream outfile ("times.txt");
    for (size_t a = 0; a < 101; ++a)
    {
        {
            Timer time;
            std::cout << "------------- " << a << " --------------" << std::endl;
            action();
            outfile << time.accessTime() << std::endl;
        }
    }
    outfile.close();
}