#ifndef SMC_H
#define SMC_H

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>

namespace smc
{
    class VectorCSC
    {
        private:
            size_t mSize;

        public:
            std::vector<int> mContainerI; // Vector to Store Indices
            std::vector<int> mContainerX; // Vector to Store Values
            VectorCSC(std::vector<int>& aStandard)
            {
                mSize = aStandard.size();
                int counter = 0;
                for (std::vector<int>::const_iterator iter = aStandard.begin(); iter != aStandard.end(); iter++)
                {
                    if (*iter != 0)
                    {
                        mContainerI.push_back(counter);
                        mContainerX.push_back(*iter);
                    }
                    counter++;
                }
            }
            class iterator 
            {
                private:
                    int& mPtr;
                    int mPos;
                public:
                    iterator(int& pPtr, int pPos) 
                    {
                        mPtr = pPtr;
                        mPos = pPos;
                    };
            };
            iterator begin ()

            void display()
            {
                std::cout << "index -> value" << std::endl;
                for (size_t i = 0; i < mContainerX.size(); i++)
                {
                    std::cout << mContainerI.at(i) << " -> " << mContainerX.at(i) << std::endl;
                }          
            }

            // Return I and X Vectors
            std::tuple<const std::vector<int>&, const std::vector<int>&> getCSC() const
            {
                return {mContainerI, mContainerX}; 
            }
    };

    class VectorSRLE
    {
        private:
            std::vector<int> srleI;
            std::vector<int> srleJ;
            std::vector<int> srleX;
        public:
            VectorSRLE(VectorCSC aCSC)
            {
                std::map<int, std::vector<int>> temp;
                int ctr = 0;
                for (auto item : aCSC.mContainerX)
                {
                    temp[item].push_back(aCSC.mContainerI.at(ctr++));
                }
                for (auto item : temp)
                {
                    srleX.push_back(item.first);
                    srleJ.push_back(srleI.size());
                    for (auto it = item.second.begin(); it != item.second.end(); it++)
                    {
                        srleI.push_back(*it);
                    }
                }
            }
            void display()
            {
                std::cout << "--------x---------" << std::endl;
                for (std::vector<int>::iterator it = srleX.begin(); it != srleX.end(); it++)
                {
                    std::cout << *it << " ";
                }
                std::cout << std::endl << "--------j---------" << std::endl;
                for (std::vector<int>::iterator it = srleJ.begin(); it != srleJ.end(); it++)
                {
                    std::cout << *it << " ";
                }
                std::cout << std::endl << "--------i---------" << std::endl;
                for (std::vector<int>::iterator it = srleI.begin(); it != srleI.end(); it++)
                {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
            }
    };
}

#endif