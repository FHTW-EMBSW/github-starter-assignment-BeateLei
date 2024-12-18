#include "../inc/pascal.h"

#include <iostream>
#include <iomanip>

std::vector<std::vector<int>> createTriangle(int n) {
    if (n > MAX_SIZE){
        return std::vector<std::vector<int>>();
    }

    std::vector<std::vector<int>> triangle(n);

    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}


void printTriangle(const std::vector<std::vector<int>>& triangle) {
    int n = triangle.size();
    int maxWidth = (n - 1) * 3; 

    for (int i = 0; i < n; ++i) {
        int padding = (maxWidth - i * 3);
        std::cout << std::string(padding, ' ');
        for (const auto& elem : triangle[i]) {
            std::cout << std::setw(3) << std::setfill('0') << elem << "   ";
        }
        std::cout << std::endl;
    }
}