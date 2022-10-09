#ifndef SMC_H
#define SMC_H

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include "csc.h"


namespace smc
{    
    class VectorSRLE
    {
        private:
            std::vector<int> srleI;
            std::vector<int> srleJ;
            std::vector<int> srleX;
        public:
            VectorSRLE(VectorCSC aCSC)
            {
                std::map<int, std::vector<int>> temp;
                int ctr = 0;
                for (auto item : aCSC.mContainerX)
                {
                    temp[item].push_back(aCSC.mContainerI.at(ctr++));
                }
                for (auto item : temp)
                {
                    srleX.push_back(item.first);
                    srleJ.push_back(srleI.size());
                    for (auto it = item.second.begin(); it != item.second.end(); it++)
                    {
                        srleI.push_back(*it);
                    }
                }
            }
            void display()
            {
                std::cout << "--------x---------" << std::endl;
                for (std::vector<int>::iterator it = srleX.begin(); it != srleX.end(); it++)
                {
                    std::cout << *it << " ";
                }
                std::cout << std::endl << "--------j---------" << std::endl;
                for (std::vector<int>::iterator it = srleJ.begin(); it != srleJ.end(); it++)
                {
                    std::cout << *it << " ";
                }
                std::cout << std::endl << "--------i---------" << std::endl;
                for (std::vector<int>::iterator it = srleI.begin(); it != srleI.end(); it++)
                {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
            }
    };
}

#endif