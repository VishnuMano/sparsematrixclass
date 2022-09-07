#include <bits/stdc++.h>

namespace matrix
{
    class cscVector
    {
        private:
            std::vector<int> mStorage;
        protected:
            void checkBounds(int aCol)
            {
                if (aCol >= mStorage.size())
                {
                    throw std::out_of_range("Element column does not exist");
                }
            }
        public:
            void push(int aCol, int aValue)
            {
                if  
            }
    };

    class cscMatrix
    {

    };
}

int main()
{

}