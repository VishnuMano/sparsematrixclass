#include <iostream>
#include <vector>

namespace research {
    class Vector
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

            void input(int aSize)
            {
                int a;
                for (size_t i = 0; i < aSize; i++)
                {
                    std::cin >> a;
                    mStorage.push_back(a);
                }
                
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

            int size()
            {
                return mStorage.size();
            }
    };

    class Matrix
    {
        private:
            std::vector< std::vector<int> > mStorage;
        protected:

        public:
            void push(int aRow, int aCol, int aValue)
            {
                if (aRow >= mStorage.size())
                {
                    do
                    {
                        mStorage.push_back(std::vector<int>());
                    } while (mStorage.size() < aRow);
                }
                std::vector<int>& rowContainer = mStorage.at(aRow);

                if (aCol >= rowContainer.size())
                {
                    do
                    {
                        rowContainer.push_back(0);
                    } while (rowContainer.size() <= aCol);
                }
                rowContainer.at(aCol) = aValue;
            }
            
            void print()
            {
                for (std::vector< std::vector<int> >::iterator iter = mStorage.begin(); iter != mStorage.end(); iter++)
                {
                    for (std::vector<int>::iterator elementiter = (*iter).begin(); elementiter != (*iter).end(); elementiter++)
                    {
                        std::cout << *elementiter << " ";
                    }
                    std::cout << std::endl;
                }
                
            }
    };

    class cscVector
    {
        private:
            std::vector<int> i;
            std::vector<int> x;
        public:
            cscVector(Vector aStdVect)
            {
                for (size_t a = 0; a < aStdVect.size(); a++)
                {
                    if (aStdVect.get(a) != 0)
                    {
                        i.push_back(a);
                        x.push_back(aStdVect.get(a));
                    }
                }
            }
            void printVect()
            {
                std::cout << "i: " << std::endl;
                for (size_t a = 0; a < i.size(); a++)
                {
                    std::cout << i.at(a) << " ";
                }
                std::cout << std::endl << "x: " << std::endl;
                for (size_t a = 0; a < x.size(); a++)
                {
                    std::cout << x.at(a) << " ";
                }
                std::cout << std::endl;
            }
    };
}
int main()
{
    research::Vector vect1;
    vect1.push(0, 5);
    vect1.push(1, 3);
    vect1.push(2, 11);
    vect1.input(17);

    research::cscVector csc1(vect1);
    csc1.printVect();
}