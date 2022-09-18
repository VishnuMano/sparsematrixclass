#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> getUnique(vector<int> src)
{
    vector<int> final;
    sort(src.begin(), src.end());
    auto newEnd = unique(src.begin(), src.end());
    for (auto it = src.begin(); it != newEnd; it++)
    {
        final.push_back(*it);
    }
    return final;
}



int main()
{
    vector<int> sample = {1, 0, 0, 2, 0, 0, 0, 3, 2, 0, 0, 2, 0, 1, 3, 0};
    vector<int> cscX = {1, 2, 3, 2, 2, 1, 3};
    vector<int> cscI = {0, 3, 7, 8, 11, 13, 14};

    /*
        SRLE x: 1, 2, 3
        SRLE i: 0, 13, 3, 8, 11, 7, 14
        SRLE j: 0, 2, 5
    */
    
    // Convert from cscX to unique vals
    auto srleX = getUnique(cscX);

    
    // for(auto item : srleX)
    // {
    //     cout << item << " ";
    // }

    map<int, vector<int>> temp;
    // 1: <0, 13>
    int ctr = 0;
    for (auto item : cscX)
    {
        temp[item].push_back(cscI[ctr++]);
    }
    vector<int> srleI;
    vector<int> srleJ;
    for (auto item : temp)
    {
        srleJ.push_back(srleI.size());
        for (auto it = item.second.begin(); it != item.second.end(); it++)
        {
            srleI.push_back(*it);
        }
    }
    
    cout << "----------------srleI----------------" << endl;
    for (auto item : srleI)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "--------------srleJ------------------" << endl;
    for (auto item : srleJ)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "--------------------------------" << endl;
}