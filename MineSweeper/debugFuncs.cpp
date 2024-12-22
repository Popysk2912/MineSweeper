#include "debugFuncs.h"

void debf::print2dVector(const std::vector<std::vector<int>>& vec) 
{
    for (const auto& row : vec) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}