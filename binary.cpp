#include <iostream>

using namespace std;

int countOnes(unsigned int a)
{
    unsigned int count = a - ((a >> 1) & 3681400539 /*033333333333*/) - ((a >> 2) & 1227133513 /*011111111111*/);
    return ((count + (count >> 3)) & 3340530119 /*030707070707*/) % 63;
}

int main()
{
    int num = 14; // 1110
    cout << countOnes(num);
}