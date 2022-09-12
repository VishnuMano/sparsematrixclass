#ifndef SMC_H
#define SMC_H

#include <vector>
#include <tuple>
#include <iostream>

#include <algorithm>

namespace smc
{
    class VectorCSC
    {
        private:
            std::vector<int> mContainerI; // Vector to Store Indices
            std::vector<int> mContainerX; // Vector to Store Values
            size_t mSize;
        public:
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
            std::vector<int> i;
            std::vector<int> j;
            std::vector<int> x;
        public:
            VectorSRLE(std::vector<int> aStandard)
            {   
                for(std::vector<int>::iterator iter = aStandard.begin(); iter != aStandard.end(); iter++)
                {
                    if (std::count(x.begin(), x.end(), *iter))
                    {
                        continue;
                    }
                    if(*iter != 0)
                    {
                        x.push_back(*iter);
                    }
                }
            }
            void display()
            {
                for (std::vector<int>::iterator iter = x.begin(); iter != x.end(); iter++)
                {
                    std::cout << *iter << " ";
                }
                
            }
    };
}

#endif