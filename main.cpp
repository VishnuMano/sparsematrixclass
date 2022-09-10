#include <iostream>
#include <vector>
#include <tuple>
#include "vectorcsc.h"

int main()
{
    std::vector<int> sample = {1,0,0,1,3,2,0,0,0,0,0,2};
    smc::VectorCSC test(sample);
    auto[veci, vecx] = test.getCSC();
    for (auto elem : veci)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    for (auto elem : vecx)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}