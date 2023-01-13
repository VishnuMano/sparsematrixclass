#include <iostream>
#include <Eigen/Sparse>

using namespace Eigen;

int main()
{
    SparseMatrix<std::complex<double>, ColMajor> m(1000, 1000);
    for (size_t i = 0; i < m.cols(); i++)
    {
        for (size_t j = 0; j < m.rows(); j++)
        {
            m.insert(j, i) = 0;
        }
    }
}