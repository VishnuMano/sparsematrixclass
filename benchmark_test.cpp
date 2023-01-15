#include <iostream>
#include <Eigen/Sparse>
#include <vector>

int main()
{
    Eigen::SparseMatrix<double> matrix(3, 5);
    matrix.insert(0, 0) = 0;
    matrix.insert(0, 1) = 0;
    matrix.insert(0, 2) = 1;
    matrix.insert(0, 3) = 0;
    matrix.insert(0, 4) = 3;
    matrix.insert(1, 0) = 3;
    matrix.insert(1, 1) = 2;
    matrix.insert(1, 2) = 0;
    matrix.insert(1, 3) = 1;
    matrix.insert(1, 4) = 0;
    matrix.insert(2, 0) = 0;
    matrix.insert(2, 1) = 1;
    matrix.insert(2, 2) = 0;
    matrix.insert(2, 3) = 0;
    matrix.insert(2, 4) = 0;
    matrix.makeCompressed();
    /*
        0, 0, 1, 0, 3,
        3, 2, 0, 1, 0,
        0, 1, 0, 0, 0;
    */
    // std::cout << matrix.isCompressed();
    std::vector<double> colsums(matrix.cols());
    for (size_t i = 0; i < matrix.cols(); ++i)
    {
        for (Eigen::SparseMatrix<double>::InnerIterator it(matrix, i); it; ++it)
        {
            colsums[i] += it.value();
        }
    }
    for (std::vector<double>::iterator it = colsums.begin(); it != colsums.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

