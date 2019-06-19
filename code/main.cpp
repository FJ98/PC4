#include "Matriz.h"
#include "MatrizConcurrente.h"
#include <random>

int main() {
    Matriz<int> m1(2,3);
    Matriz<int> m2(3,2);

    m1.print_matriz(); cout<<endl;
    m2.print_matriz();cout<<endl;

    Matriz<int> m3(2,2);
    m3 = m1*m2;
    m3.print_matriz();

    return 0;
}