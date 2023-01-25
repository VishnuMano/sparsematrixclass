//create an iterator struct
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iterator>
#include <cstddef>
#include <fstream>

using namespace std;

//template<typename T> <- return what user wants https://en.cppreference.com/w/cpp/language/partial_specialization
template<typename T>
class const_array_iterator {
    //todo:
    //clean the vocabulary
    private:
        uint32_t magicByteSize; //= params[0];
        uint32_t rowType;       //= params[1];
        uint32_t nRows;         //= params[2];
        uint32_t colType;       //= params[3];
        uint32_t nCols;         //= params[4];
        uint32_t valueWidth;    //= params[5];
        uint32_t oldIndexType;  //= params[6]; 
               
        int newIndexWidth; //basically how many bytes we read, NOT ACTUALLY THE TYPE
        char* end;
        char* fileData;
        char* arrayPointer;
        uint64_t index = 0;
        T value;
    public:
      
      

   const_array_iterator(const char* filePath) {

        //set up the iterator
        readFile(filePath);

        //read first 28 bytes of fileData put it into params -> metadata
        uint32_t params[7];
        memcpy(&params, arrayPointer, 32); //28 is subject to change depending on magic bytes
        arrayPointer+=32; //first delimitor is 4 bytes
        cout << "Params" << endl;
        magicByteSize = params[0];
        rowType       = params[1];
        nRows         = params[2];
        colType       = params[3];
        nCols         = params[4];
        oldIndexType  = params[6];

        cout << "First round" << endl;
        memcpy(&valueWidth, arrayPointer, 1);
        arrayPointer++;
        cout << "value Width " << (int)valueWidth << endl;
        memcpy(&value, arrayPointer, valueWidth);
        arrayPointer += valueWidth;
        memcpy(&newIndexWidth, arrayPointer, 1);
        arrayPointer++; //this should make it point to first index
        
        cout << "value: " << value << endl;
        cout << "newIndexWidth: " << newIndexWidth << endl;

        // for debugging
        for(int i = 0; i < 7; i++) {
            cout << params[i] << endl;
        }


    }//end of constructor


    //todo make this return type T 
    T& operator * () {return value;}; 
    

    template<Typename T> 
    const uint64_t operator++() { 
        //TODO template metaprogramming
        //todo through an exception if we request something smaller than the size of the index

        T newIndex = 0; 
        //memcpy(&newIndex, arrayPointer, newIndexWidth);
        newIndex = &arrayPointer[0];
        
        arrayPointer += newIndexWidth;


        if(newIndex == 0 && index != 0){ //change that
            
            memcpy(&valueWidth, arrayPointer, 1);
            arrayPointer++;

            memcpy(&value, arrayPointer, valueWidth);
            arrayPointer += valueWidth; 

            // memcpy(&newIndexWidth, arrayPointer, 1);
            newIndexWidth = &arrayPointer[0];
            arrayPointer++;

            switch (newIndexWidth){
                case 1:
                    T = uint8_t;
                case 2:
                    T = uint16_t;
                case 4:
                    T = uint32_t;
                case 8:
                    T = uint64_t;
                default:
                    cerr << "New index width is invalid\nFile encoded wrong!"

            }


            
            cout << endl << "value: " << value << endl;
            cout << "newIndexWidth: " << newIndexWidth << endl;
            
            memset(&index, 0, 8);
            memcpy(&index, arrayPointer, newIndexWidth);
            
        }

        return index += newIndex;

    }


    // equality operator
    operator bool() {
        // cout << "end " << &end << endl;
        // cout << "arr " << &arrayPointer << endl;
        return end >= arrayPointer;} //change to not equal at the end


    // reads in the file and stores it in a char* 
    inline void readFile(string filePath){ 
        ifstream fileStream;
        fileStream.open(filePath, ios::binary | ios::out);
        
        fileStream.seekg(0, ios::end);
        int sizeOfFile = fileStream.tellg();
        fileData = (char*)malloc(sizeof(char*)*sizeOfFile);

        fileStream.seekg(0, ios::beg);
        fileStream.read(fileData, sizeOfFile);
        
        fileStream.close();

        arrayPointer = fileData;
        end = fileData + sizeOfFile;
        }
};