#include <iostream>
#include <vector>

namespace smc
{
    class VectorSparse
    {
        private:
            std::vector<int> mStorage;
        public:
            void insert(int aValue)
            {
                mStorage.push_back(aValue);
            }
            void insertAt(int aIndex, int aValue)
            {
                mStorage.at(aIndex) = aValue;
            }
            void remove()
            {
                mStorage.pop_back();
            }
            void removeAt(int aIndex)
            {
                mStorage.erase(mStorage.begin() + aIndex);
            }
            int getElement(int aIndex)
            {
                return mStorage.at(aIndex);
            }
            int getSize()
            {
                return 0;
            }
            void print()
            {
                for (std::vector<int>::iterator iter = mStorage.begin(); iter != mStorage.end(); iter++)
                {
                    std::cout << *iter << " | ";
                }
                std::cout << std::endl;
            }
    };
}

int main()
{
    smc::VectorSparse vector1;
    vector1.insert(1);
    vector1.insert(0);
    vector1.insert(0);
    vector1.insert(1);
    vector1.insert(2);
    vector1.insert(0);
    vector1.insert(0);
    vector1.insert(1);
    vector1.insert(0);
    vector1.insert(1);
    vector1.insert(0);
    vector1.insert(0);
    vector1.insert(0);
    vector1.insert(2);
    vector1.insert(0);
    vector1.insert(0);
    vector1.insert(1);

    vector1.print();
}