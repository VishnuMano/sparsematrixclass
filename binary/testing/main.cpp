/*
17 - 10001
08 - 01000
04 - 00100
02 - 00010
01 - 00001
*/


#include <iostream>

using namespace std;

int oneCount(unsigned int a)
{
    unsigned int count = a - ((a >> 1) & 033333333333) - ((a >> 2) & 011111111111);
    return ((count + (count >> 3)) & 030707070707) % 63;
}

int main()
{
    cout << oneCount(0110) << endl;
    int test = 4;
    test >>= 1;
    cout << sizeof(test);
}


// 0110 = 6

// 0110 - 0011 - 0001
// 6 - 3 - 1


/*
11100 - 28 - 1x2^4 + 1x23 + 1x2^2 + 0x2^1 + 0x2^0
01110 - 14 - 0x2^4 + 1x23 + 1x2^2 + 1x2^1 + 0x2^0
00111 - 7  - 0x2^4 + 0x23 + 1x2^2 + 1x2^1 + 1x2^0
00011 - 3  - 0x2^4 + 0x23 + 0x2^2 + 1x2^1 + 1x2^0
00001 - 1  - 0x2^4 + 0x23 + 0x2^2 + 0x2^1 + 1x2^0
00000 - 0  - 0x2^4 + 0x23 + 0x2^2 + 0x2^1 + 0x2^0
*/