// [[Rcpp::depends(RcppEigen)]]
// [[Rcpp::depends(RcppClock)]]
// #include <RcppEigen.h>
#include "include/SRLE_Lib.hpp"
#include <fstream>

//Functions
// void iteratorBenchmark(int numRows, int numCols, int sparsity, uint64_t seed);
template <typename T> Eigen::SparseMatrix<T> generateMatrix(int numRows, int numCols, int sparsity, uint64_t seed);

class Timer
{
    public:
        Timer() 
        {
            // Starting time
            std::chrono::steady_clock::time_point m_StartTimepoint = std::chrono::high_resolution_clock::now();
        }

        ~ Timer()
        {
            // Deconstructor calls Stop Function
            Stop();
        }

        void Stop()
        {
            // Ending time
            std::chrono::steady_clock::time_point endTimepoint = std::chrono::high_resolution_clock::now();
            // Casts Start/Stop to Microseconds
            long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
            long long stop = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
            // Calculates Duration in Microseconds
            micro_duration = stop - start;
        }

        long long accessTime()
        {
            return micro_duration;
        }
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
        long long micro_duration;
};


int main() {

    int numRows = 100;
    int numCols = 10;
    int sparsity = 20;
    uint64_t seed = 5645646546;
    generateMatrix<int>(numRows, numCols, sparsity, seed);

    return 1;
}

template <typename T>
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
    // ------------------------ benchmark algorithm ----------------------------------------

    // colsum time calculator
    std::ofstream outfile ("times.txt");
    vector<int> colsums(myMatrix.cols());
    for(int a = 0; a < 100; ++a)
    {
        Timer timer;
        for (size_t i = 0; i < myMatrix.cols(); i++)
        {
            for (size_t j = 0; j < myMatrix.rows(); j++)
            {
                colsums[i] += myMatrix.coeff(j, i);
            }
        }
        outfile << timer.accessTime() << ", ";
    }
    outfile.close();

    // matrix size calculator
    std::ofstream s_file ("size.txt");
    for (size_t i = 0; i < 100; i++)
    {
        s_file << numRows * numCols << ", ";
    }
    s_file.close();
    // ------------------------ print results ----------------------------------------
    for (size_t i = 0; i < myMatrix.cols(); i++)
    {
        std::cout << colsums[i] << std::endl;
    }
    
    return myMatrix;
}