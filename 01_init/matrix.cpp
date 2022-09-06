#include <bits/stdc++.h>

namespace research {
    class Vector
    {
        private:
            std::vector<int> mStorage;
        protected:
            // void checkBounds(int aCol)
            // {
            //     if (aCol >= mStorage.size())
            //     {
            //         throw std::out_of_range("Element column does not exist");
            //     }
            // }
        public:
            void push(int aCol, int aValue)
            {
                // Check if row exists
                if(aCol >= mStorage.size())
                {
                    do
                    {
                        mStorage.push_back(0);
                    } while (mStorage.size() < aCol);
                }
                mStorage.at(aCol) = aValue;
            }

            int get(int aCol)
            {
                return mStorage.at(aCol); 
            }

            void printVect()
            {
                for (std::vector<int>::iterator iter = mStorage.begin(); iter != mStorage.end(); iter++)
                {
                    std::cout << *iter << " ";
                }
                std::cout << std::endl;
            }
    };

    class Matrix
    {
        private:
            std::vector<std::vector<int>> mStorage;
        protected:

        public:
            void push(int aRow, int aCol, int value)
            {
                if (aRow >= mStorage.size())
                {
                    /* code */
                }
                
            }
    };
}
int main()
{
    research::Vector vect1;
    vect1.push(0, 5);
    vect1.push(1, 3);
    vect1.push(2, 11);
    vect1.printVect();
    std::cout << vect1.get(1) << std::endl;

    std::vector<std::vector<int>> test = { {1, 2, 3}, {4, 5, 6} };
    std::cout << test.size();
}