// g++ -std=c++17  -I /Users/vishnumano/Folders/home/coding/sparsematrixclass/eigen-git-mirror benchmark_suite.cpp -o a

#include <iostream>
#include <vector>
#include <fstream>

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

    // Writing Directly to File
    std::ofstream outfile ("times.txt");
    for (size_t a = 0; a < 100; ++a)
    {
        {
            Timer time;
            action();
            outfile << time.accessTime() << std::endl;
        }
    }
    outfile.close();
}