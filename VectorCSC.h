#pragma once
#include <vector>
#include <iostream>

template<typename T>
class VectorCSC
{
public:
   using value_type = std::pair<T,T>;
   using pointer = value_type*;
   using reference = value_type&;
private:
   size_t mSize;

public:
   
   std::vector<std::pair<T, T>> mSparseStore; // Vector to Store Indices & Values in a pair
   VectorCSC(std::vector<int>& aStandard)
   {
      mSize = aStandard.size();
      int counter = 0;
      for (std::vector<int>::const_iterator iter = aStandard.begin(); iter != aStandard.end(); iter++)
      {
         if (*iter != 0)
         {
            mSparseStore.push_back(std::make_pair(counter, *iter));
         }
         counter++;
      }
   }

   size_t Size() const {return mSparseStore.size(); }
   void display()
   {
      std::cout << "index -> value" << std::endl;
      for (size_t i = 0; i < mSparseStore.size(); i++)
      {
         std::cout << mSparseStore.at(i).first << " -> " << mSparseStore.at(i).second << std::endl;
      }
   }

   struct Iterator
   {
      

      Iterator(pointer ptr) : m_ptr(ptr) {}

      reference operator*() const { return *m_ptr; }
      pointer operator->() { return m_ptr; }

      // Prefix increment
      Iterator& operator++() { m_ptr++; return *this; }

      // Postfix increment
      Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
      friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
      friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
   private:

      pointer m_ptr;
   };
   Iterator begin() { return Iterator(&mSparseStore[0]); }
   Iterator end() { return Iterator(&mSparseStore[0] + Size() ); } // an invalid location
};