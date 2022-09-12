#include "smc.h"

int main()
{
    std::vector<int> sample = {1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 2};
    smc::VectorCSC test(sample);
    auto[test_i, test_x] = test.getCSC();
    for (std::vector<int>::const_iterator iter = test_i.begin(); iter != test_i.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    for (std::vector<int>::const_iterator iter = test_x.begin(); iter != test_x.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // test.display();

    smc::VectorSRLE fun(sample);
    fun.display();
}