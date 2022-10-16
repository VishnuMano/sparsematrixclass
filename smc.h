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
                    VectorCSC& mRef;
                    size_t mPos = 0;
                public:
                    iterator(VectorCSC& aRef, size_t aPos): mRef(aRef), mPos(aPos) {}
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

    class VectorTRCSCNP
    {
        private:
            std::vector<int> mContainer;
            std::vector<int> mIndex;
        public:
            VectorTRCSCNP(std::vector<int> aRef)
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
            }
        
            class iterator
            {
                private:
                    VectorTRCSCNP& mRef;
                    int mPos;
                    int curVal = 0;
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
                    iterator(VectorTRCSCNP& aRef, int aPos, std::vector<int>& aIndex): mRef(aRef), mPos(aPos) {}
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


//     class VectorSRLE
//     {
//         private:
//             std::vector<int> srleI;
//             std::vector<int> srleJ;
//             std::vector<int> srleX;
//         public:
//             VectorSRLE(VectorCSC aCSC)
//             {
//                 std::map<int, std::vector<int>> temp;
//                 int ctr = 0;
//                 for (auto item : aCSC.mContainerX)
//                 {
//                     temp[item].push_back(aCSC.mContainerI.at(ctr++));
//                 }
//                 for (auto item : temp)
//                 {
//                     srleX.push_back(item.first);
//                     srleJ.push_back(srleI.size());
//                     for (auto it = item.second.begin(); it != item.second.end(); it++)
//                     {
//                         srleI.push_back(*it);
//                     }
//                 }
//             }
            
//             std::vector<int>& getSRLEI()
//             {
//                 return srleI;
//             }
//             std::vector<int>& getSRLEJ()
//             {
//                 return srleJ;
//             }
//             std::vector<int>& getSRLEX()
//             {
//                 return srleX;
//             }

//             void display()
//             {
//                 std::cout << "--------x---------" << std::endl;
//                 for (std::vector<int>::iterator it = srleX.begin(); it != srleX.end(); it++)
//                 {
//                     std::cout << *it << " ";
//                 }
//                 std::cout << std::endl << "--------j---------" << std::endl;
//                 for (std::vector<int>::iterator it = srleJ.begin(); it != srleJ.end(); it++)
//                 {
//                     std::cout << *it << " ";
//                 }
//                 std::cout << std::endl << "--------i---------" << std::endl;
//                 for (std::vector<int>::iterator it = srleI.begin(); it != srleI.end(); it++)
//                 {
//                     std::cout << *it << " ";
//                 }
//                 std::cout << std::endl;
//             }
//     };

//     class TRCSC
//     {
//         private:
//             std::vector<int> container;
//         public:
//             TRCSC(VectorSRLE& srle)
//             {
//                 std::vector<int> srleI = *(srle.getSRLEI());
//                 container.reserve(srle.getSRLEI)
//             }
//     };
}

#endif