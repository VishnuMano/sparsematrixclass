#include <iostream>

using namespace std;

int countOnes(unsigned int a)
{
    unsigned int count = a - ((a >> 1) & 033333333333) - ((a >> 2) & 011111111111);
    return ((count + (count >> 3)) & 030707070707) % 63;
}

int main()
{
    int num = 20758; // 0101000100010110
    cout << countOnes(num);
}