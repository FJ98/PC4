#include "Matriz.h"
#include "MatrizConcurrente.h"
#include <random>
#include <thread>
#include <mutex>
//int const size = 4; mutex mtx[size][size]; thread myThread[size];
//static const long MATRIX_SIZE = 1000; static const int THREADS = 4; static const double N_EXECUTIONS = 1e3;
static const int THREADS = 4;

int main() {
    // NO CONCURRENTE Y NO PARALELA
    Matriz<int> m1(2,3); Matriz<int> m2(3,2); Matriz<int> m3(2,2);
    m3 = m1*m2;
    m1.print_matriz(); m2.print_matriz(); m3.print_matriz();
//----------------------------------------------
    // NO CONCURRENTE Y PARALELA
    /*Matriz2<int> mA(3,3); Matriz2<int> mB(3,3); Matriz2<int> mC(3,3);
    std::thread threads[THREADS];
    for (int i = 0; i < THREADS; ++i) {
        //threads[i] = std::thread(multiply_threading<int>, i, std::ref(mA), std::ref(mB), std::ref(mC));
    }
    for (auto & thread : threads) { thread.join(); }
    mC.print_matriz();*/
//---------------------------------------------------
    // CONCURRENTE Y NO PARALELA
    Matriz<int> m11(2,3), m21(3,2), m31(2,2);
    m31 = m11*m21;
    m11.print_matriz(); m21.print_matriz(); m31.print_matriz();
//---------------------------------------------------
    // CONCURRENTE Y PARALELA


    return 0;
}