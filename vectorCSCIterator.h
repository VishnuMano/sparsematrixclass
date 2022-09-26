#pragma once
#include <vector>
#include <iostream>

class VectorCSCIterator
{
public:
   using ValueType = int;
   using PointerType = ValueType*;
   using ReferenceType = ValueType&;
public:
   VectorCSCIterator(std::vector<int>& aContainerX, std::vector<int>& aContainerI) :mContainerX(aContainerX), mContainerI(aContainerI), mSize(0) {}
   VectorCSCIterator(size_t aSize) :mSize(aSize) {}
   int operator++()
   {
      mCurPos++;
      std::vector<int>::iterator it = std::find(mContainerI.begin(), mContainerI.end(), mCurPos) ;
      if(it != mContainerI.end())
      {
         auto dist = std::distance(mContainerI.begin(), it);
         return dist;
      }
      else return 0;

   }

   int operator++(int)
   {
      std::vector<int>::iterator it = std::find(mContainerI.begin(), mContainerI.end(), mCurPos);
      if (it != mContainerI.end())
      {
         auto dist = std::distance(mContainerI.begin(), it);
         mCurPos++;
         return dist;
      }
      else return 0;
   }

private:
   std::vector<int> mContainerI; // ref to Store Indices
   std::vector<int> mContainerX; // ref to Store Values
   size_t mSize;
   size_t mCurPos = 0;


};

