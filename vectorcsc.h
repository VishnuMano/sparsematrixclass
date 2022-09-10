#ifndef VECTORCSC_H
#define VECTORCSC_H
#include <cstddef>
#include <vector>
#include <tuple>

namespace smc
{
    class VectorCSC
    {
        using StdVector = std::vector<int>;
        private:
            StdVector mContainerI; // Stores index from standard vectors
            StdVector mContainerX; // Stores non-zero values from standard vectors
            size_t mSize;
        public:
            // ctor
            VectorCSC(const StdVector& aStandard)
            {
                mSize = aStandard.size();
                int counter = 0;
                for (StdVector::const_iterator iter = aStandard.begin(); iter != aStandard.end(); iter++, counter++)
                {
                    if (*iter != 0)
                    {
                        mContainerX.push_back(*iter);
                        mContainerI.push_back(counter);
                    }
                }              
            }
            // Check with Dr. DeBruine
            // VectorCSC(const StdVector& aStandard)
            // {
            //     mSize = aStandard.size();
            //     int counter = 0;
            //     for (const auto val : aStandard)
            //     {
            //         if (val != 0)
            //         {
            //             mContainerX.push_back(val);
            //             mContainerI.push_back(counter);
            //         }
            //         counter++;
            //     }              
            // }
            
            // returning const ref to value and index vectors
            std::tuple<const StdVector&, const StdVector&> getCSC() const
            {
                return {mContainerI, mContainerX};
            };
    };
};

#endif