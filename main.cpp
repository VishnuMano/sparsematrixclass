#include "smc.h"
#include <fstream>

int main()
{
    std::cout << "CSC: " << std::endl;
    std::vector<int> src = {1, 0, 1, 2, 0, 0, 0, 1, 0, 2, 1, 0, 0, 1};
    smc::CSC csc(src);
    for(smc::CSC::iterator iter = csc.begin(); iter != csc.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl << "SRLE: " << std::endl;
    smc::SRLE srle(src);
    // std::ofstream ofs;
    // ofs.open("storage.txt");
    // ofs << "int" << " ";
    // for (smc::SRLE::iterator iter = srle.begin(); iter != srle.end(); ++iter)
    // {
    //     ofs << *iter << " ";
    // }
    
}