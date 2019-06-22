#include "Matriz.h"
#include "MatrizConcurrente.h"
#include <random>
#include <thread>
#include <mutex>
//int const size = 4; mutex mtx[size][size]; thread myThread[size];
//static const long MATRIX_SIZE = 1000; static const int THREADS = 4; static const double N_EXECUTIONS = 1e3;
static const int THREADS = 4;

int main() {
    // NO CONCURRENTE
    /*Matriz<int> m1(2,3); Matriz<int> m2(3,2); Matriz<int> m3(2,2);
    m3 = m1*m2;
    m1.print_matriz(); m2.print_matriz(); m3.print_matriz();*/
//----------------------------------------------
    // NO CONCURRENTE
    MatrizConcurrente<int> m11(7,4); MatrizConcurrente<int> m21(4,7); MatrizConcurrente<int> m31(7,7);
    m11.print_matriz(); m21.print_matriz();
    m31 = m11*m21;
    m31.print_matriz();


    return 0;
}