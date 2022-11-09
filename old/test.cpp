#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> test = {1, 3, 2,3};
    int val = *find(test.begin(), test.end(), 3);
    cout << val << endl;
}