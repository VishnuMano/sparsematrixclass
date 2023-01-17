#include <iostream>
#include <cstdlib>
#include <Eigen/SparseCore>
#include <random>

Eigen::SparseMatrix<double> generateSM(int rows, int cols)
{
    Eigen::SparseMatrix<double> sm(rows, cols);
    
    for (size_t i = 0; i < sm.rows(); ++i)
    {
        for (size_t j = 0; j < sm.cols(); ++j)
        {
            sm.insert(i, j) = rand() % 10;
        }
    }
    return sm;
}

void printMatrix(Eigen::SparseMatrix<double> p_sm)
{
    for (size_t i = 0; i < p_sm.rows(); ++i)
    {
        for (size_t j = 0; j < p_sm.cols(); ++j)
        {
            std::cout << p_sm.coeff(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::default_random_engine gen;
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    int rows = 100;
    int cols = 100;
    std::vector<Eigen::Triplet<double>> tripletList;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            typedef Eigen::Triplet<double> T;
            auto v = dist(gen);
            if (v < 0.1)
            {
                tripletList.push_back(T(v, i, j));
            }
            
        }
        
    }
    Eigen::SparseMatrix<double> sm(rows, cols);
    sm.setFromTriplets(tripletList.begin(), tripletList.end());
    printMatrix(sm);
}