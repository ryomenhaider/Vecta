#include "include/vecta/linear_algebra/matrix.hpp"
#include <vector>

namespace vecta {

    namespace linear_algebra{
    
        class matrix
        {
            std::vector<double> add(const std::vector<double> A, const std::vector<double> B)
            {
                
            }

            double dot(const std::vector<double> A, const std::vector<double> B);
            
            std::vector<double> matmul(const std::vector<double> A, const std::vector<double> B);
            
            std::vector<double> inverse(const std::vector<double> A, const std::vector<double> B);

            std::vector<double> transpose(const std::vector<double> A, const std::vector<double> B);
        };
        
        
    }
}