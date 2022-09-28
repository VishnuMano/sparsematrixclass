#include <iostream>
#include "VectorCSC.h"


int main()
{
   std::vector<int> sample = {1,0,5,0,4,2,4,0,0,7};
   VectorCSC<uint16_t> vcsc(sample);
   for (VectorCSC<uint16_t>::Iterator it = vcsc.begin(); it != vcsc.end(); ++it)
   {
      std::cout << (*it).second << " at " << (*it).first << std::endl;
   }
}