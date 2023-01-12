#ifndef SMC_H
#define SMC_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <typeinfo>

namespace smc {
    class CSC
    {
        private:
            std::vector<int> mContainerI;
            std::vector<int> mContainerX;
        public:
            CSC(std::vector<int>& aStandard)
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
                    CSC& mRef;
                    size_t mPos = 0;
                public:
                    iterator(CSC& aRef, size_t aPos): mRef(aRef), mPos(aPos) {}
                    iterator operator ++ ()
                    {
                        ++mPos;
                        return *this;
                    }

                    iterator operator ++ (int preincrement)
                    {
                        iterator temp = *this;
                        ++(*this);
                        return temp;
                    }

                    size_t operator * ()
                    {
                        return mRef.mContainerX.at(mPos);
                    }

                    bool operator != (const iterator &other) const
                    {
                        return mPos != other.mPos;
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

    class SRLE
    {
        private:
            std::vector<int> mContainer;
            std::vector<int> mIndex;
        public:
            SRLE(std::vector<int> aRef)
            {                
                std::map<int, std::vector<int>> Buckets;
                mContainer.reserve(aRef.size());
                size_t ctr = 0;
                for (auto item : aRef)
                {
                    if(item > 0)
                    {
                        Buckets[item].push_back(ctr);
                    }
                    ctr++;
                }

                for(auto &[key, val] : Buckets)
                {
                    mContainer.push_back(-1 * key);
                    for(auto item : val)
                    {
                        mContainer.push_back(item);
                        mIndex.push_back(item);
                    }
                }
                mContainer.shrink_to_fit();
                sort(mIndex.begin(), mIndex.end());
                
                // Output to storage
                std::ofstream ofs;
                ofs.open("storage.txt");
                for (std::map<int, std::vector<int>>::iterator iter = Buckets.begin(); iter != Buckets.end(); iter++)
                {
                    ofs << typeid(iter->first).name() << -1 * iter->first;
                    int temp;
                    for (auto item : iter->second)
                    {
                        if(item == 0)
                        {
                            temp = 0;
                            ofs << item;
                        }
                        else
                        {
                            ofs << item - temp;
                        }
                        temp = item;
                    }
                    temp = 0;
                    ofs << "_";
                }
            }
        
            class iterator // mPos iterates through an index vector, not a value vector
            {
                private:
                    SRLE& mRef;
                    int mPos;
                    int curVal = 0;
                    // Find Value For Given Index
                    int find(int target, std::vector<int> vect)
                    {
                        for (auto item : mRef.mContainer)
                        {
                            if (item < 0)
                            {
                                curVal = -1 * item;
                            }
                            if (item == target)
                            {
                                return curVal;
                            }
                        }
                        return -1;
                    }
                public:
                    iterator(SRLE& aRef, int aPos, std::vector<int>& aIndex): mRef(aRef), mPos(aPos) {}
                    iterator operator ++ ()
                    {
                        mPos++;
                        return *this;
                    }

                    iterator operator ++ (int postincrement)
                    {
                        iterator temp = *this;
                        ++(*this);
                        return temp;
                    }

                    int operator * ()
                    {
                        // Find the intended index
                        int target = mRef.mIndex.at(mPos);
                        return find(target, mRef.mContainer);
                    }

                    bool operator != (const iterator& other) const
                    {
                        return mPos != other.mPos;
                    }
            };

            iterator begin()
            {
                return iterator(*this, 0, mIndex);
            }

            iterator end()
            {
                return iterator(*this, mContainer.size() - 3, mIndex);
            }

            void display()
            {
                for (auto item : mContainer)
                {
                    std::cout << item << " ";
                }
            }
    };
}
#endif