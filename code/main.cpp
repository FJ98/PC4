#include "Matriz.h"
#include "MatrizConcurrente.h"
#include <random>

int main() {
    Matriz<int> m1(2,3);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            m1.set(i,j,rand()%4+1);
        }
    }
    m1.print_matriz();
    std::cout << std::endl;
    Matriz<int> m3(3,2);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            m3.set(i,j,rand()%4+1);
        }
    }
    m3.print_matriz();
    std::cout << std::endl;
    Matriz<int> mf(2,2);
    mf = m1* m3;
    mf.print_matriz();




    return 0;
}