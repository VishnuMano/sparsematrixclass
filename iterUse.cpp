#include <bits/stdc++.h>

using namespace std;

int main()
{
    // vector<int> values = { 1, 2, 3, 4, 5 };
    // for (int value : values)
    // {
    //     cout << value << endl;
    // }
    
    // for (vector<int>::iterator it = values.begin(); it != values.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    unordered_map<string, int> map;
    map["Vishnu"] = 17;
    map["Krishna"] = 13;

    for (unordered_map<string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        cout << (*it).first << " -> " << (*it).second << endl;
    }
    
}