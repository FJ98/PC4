
#include "Matriz.h"
#include <random>


int main() {
    Matriz<int> m1(3,4);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            m1.set(i,j,rand()%10);
        }
    }
    m1.print_matriz();

    return 0;
}