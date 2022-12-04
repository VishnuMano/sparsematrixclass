#include <iostream>

using namespace std;

int main()
{
    int x = 6;  // 0110
    int y = 12; // 1100
    int z = 0;  // 0000
    
    z = x & y;
    cout << z << endl;
}