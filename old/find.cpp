#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> container = {-1, 0, 1, 10, -2, 3, 7, 8, -3, 5, 12};

    sort(container.begin(), container.end());
    for (size_t i = 0; i < container.size(); i++)
    {
        cout << container.at(i) << endl;
    }
    cout << endl;
    int currVal;
    int target = 6;
    for (size_t i = 0; i < container.size(); i++)
    {
        if(container.at(i) < 0)
        {
            currVal = -1 * container.at(i);
        }
        if(container.at(i) == target)
        {
            cout << "Index: " << target << " Value: " << currVal << endl;
            break;
        }
    }
    
}