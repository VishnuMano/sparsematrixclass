#ifndef SMC_H
#define SMC_H

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include "srle.h"


namespace smc
{
    class VectorCSC
    {
        private:
            
        public:
            std::vector<int> mContainerI; // Vector to Store Indices
            std::vector<int> mContainerX; // Vector to Store Values

            VectorCSC(std::vector<int>& aStandard)
            {
                int counter = 0;
                mContainerI.reserve(aStandard.size());
                mContainerX.reserve(aStandard.size());
                
                for (std::vector<int>::const_iterator iter = aStandard.begin(); iter != aStandard.end(); iter++)
                {
                    if (*iter != 0)
                    {
                        mContainerI.push_back(counter);
                        mContainerX.push_back(*iter);
                    }
                    counter++;
                }
                mContainerI.shrink_to_fit();
                mContainerX.shrink_to_fit();
            }
        
            class iterator
            {
                private:
                    const VectorCSC& mRef;
                    int mPos;
                public:
                    iterator(VectorCSC& aRef, int aPos) : mRef(aRef), mPos(aPos) {}
                    iterator operator ++ ()
                    {
                        mPos++;
                        return *this;
                    }

                    iterator operator ++ (int index)
                    {
                        iterator& tmp = *this;
                        ++(*this);
                        return tmp;
                    }

                    const bool operator != (const iterator& other)
                    {
                        return mPos != other.mPos;
                    }

                    const int& operator* ()
                    {
                        return mRef.mContainerX.at(mPos);
                    }
                    
                    int val()
                    {
                        return mRef.mContainerX.at(mPos); 
                    }
            };

            iterator begin()
            {
                return iterator(*this, 0);
            }

            iterator end()
            {
                return iterator(*this, mContainerX.size());
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

}

#endif