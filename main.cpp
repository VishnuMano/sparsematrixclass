#include "smc.h"

int main()
{
    std::vector<int> src = {1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 2};
    smc::VectorCSC demoCSC(src);
    smc::VectorSRLE demoSRLE(demoCSC);
    demoSRLE.display();
}