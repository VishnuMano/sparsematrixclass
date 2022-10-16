#include "smc.h"

int main()
{
    std::vector<int> src = {1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 2};
    // smc::VectorCSC demoCSC(src);
    // for (smc::VectorCSC::iterator iter = demoCSC.begin(); iter != demoCSC.end(); ++iter)
    // {
    //     std::cout << *iter << std::endl;
    // }
    smc::VectorTRCSCNP demo(src);
    demo.display();
    // smc::VectorSRLE demoSRLE(demoCSC);
    // demoSRLE.display();
}