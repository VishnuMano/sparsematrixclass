#include <iostream>
#include <Eigen/SparseCore>
#include "./include/SRLE_Lib.hpp"

Eigen::SparseMatrix<T> generateMatrix(int numRows, int numCols, int sparsity, uint64_t seed){
    //generate a random sparse matrix
    rng randMatrixGen = rng(seed);

    Eigen::SparseMatrix<T> myMatrix(numRows, numCols);
    myMatrix.reserve(Eigen::VectorXi::Constant(numRows, numCols));

    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            if(randMatrixGen.draw<int>(i,j, sparsity)){
                myMatrix.insert(i, j) = 10 * randMatrixGen.uniform<double>(j);
            }
        }
    }
    return myMatrix;
}

int main() {

    int numRows = 100;
    int numCols = 100;
    int sparsity = 20;
    uint64_t seed = 5645646546;
    generateMatrix(numRows, numCols, sparsity, seed);

    return 1;
}