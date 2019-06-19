#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> operator*(std::vector<int> matriz1, std::vector<int> matriz2){
    std::vector<int> matriz3;
    matriz3.reserve(matriz1.size());
    std::transform(matriz1.begin(), matriz1.end(), matriz2.begin(), std::back_inserter(matriz3), std::multiplies<>());
    return matriz3;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> v1 = {1,2,3,4};
    std::vector<int> v2 = {4,3,2,1};
    std::vector<int> v3;
    v3 = v1 * v2;
    for(auto & item: v3){
        for(auto & j: v3){
            std::cout << j << " ";
        }
        std::cout << item << std::endl;
    }




    return 0;
}