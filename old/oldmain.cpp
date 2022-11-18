#include "smc.h"

int main()
{
    std::vector<int> src = {1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 2, 3, 0, 0, 1, 1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 2, 3, 0, 0, 1, 1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 2, 3, 0, 0, 1, 1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 2, 3, 0, 0, 1, 1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 2, 3, 0, 0, 1, 1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 2, 3, 0, 0, 1};
    // smc::VectorCSC csc(src);
    // for (smc::VectorCSC::iterator iter = csc.begin(); iter != csc.end(); ++iter)
    // {
    //     std::cout << *iter << std::endl;
    // }
    smc::VectorTRCSCNP trcscnp(src);
    for (smc::VectorTRCSCNP::iterator iter = trcscnp.begin(); iter != trcscnp.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    
    // smc::VectorSRLE srle(demoCSC);
    // demoSRLE.display();
}