#include <iostream>

using namespace std;

int main()
{
    int x = 6;  // 0110
    int y = 12; // 1100
    int z = 0;  // 0011
    
    // AND Operator
    z = x & y;  // 0100
    cout << z << endl;

    // OR Operator
    z = x | y;  // 1110
    cout << z << endl;

    // XOR Operator
    z = x ^ y;  // 1010
    cout << z << endl;
}