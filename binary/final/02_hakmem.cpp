#include <iostream>

using namespace std;

int countOnes(unsigned int a)
{
    unsigned int count = a - ((a >> 1) & 3681400539) - ((a >> 2) & 1227133513); // 033333333333 011111111111 030707070707
    return ((count + (count >> 3)) & 3340530119) % 63;
}

int main()
{
    int num = 14; // 1110
    // cout << countOnes(num);
    int a = (5 & 5);
    cout << a;

}