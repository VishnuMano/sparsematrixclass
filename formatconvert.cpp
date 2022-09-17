#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getUnique(vector<int> src)
{
    vector<int> final;
    sort(src.begin(), src.end());
    unique(src.begin(), src.end());
    for(int item : src)
    {
        cout << item << endl;
    }
    // return final;
}

int main()
{
    // vector<int> sample = {1, 0, 0, 2, 0, 0, 0, 3, 2, 0, 0, 2, 0, 1, 3, 0};
    vector<int> cscX = {1, 2, 3, 2, 2, 1, 3};
    vector<int> cscI = {0, 3, 7, 8, 11, 13, 14};

    getUnique(cscX);
    // for (int item : srleX)
    // {
    //     cout << item << endl;
    // }
    
}