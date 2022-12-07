#include <iostream>

using namespace std;

int countOnes(unsigned int n)
{
    int count = 0;
    while(n)
    {
        count += n & 1u; // checks to see if last digit of binary is 1 and increments it to count
        n >>= 1; // removes last digit of binary by bitshifting right
    }
    return count;
}

int main()
{
    cout << countOnes(14); // 14 = 1110
}