#include <iostream>

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
    int value = 0;
    {
        Timer timer;
        for (size_t i = 0; i < 1000000; i++)
        {
			value += 2;
        }
    }

    cout << value << endl;
}
