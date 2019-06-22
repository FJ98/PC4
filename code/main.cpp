#include "Matriz.h"
#include "MatrizConcurrente.h"
#include <random>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include<sys/time.h>

using namespace std::chrono;

int main() {
    // NO CONCURRENTE
    Matriz<int> m1(1000,1000), m2(1000,1000), m3(1000,1000);
    m1.print_matriz(); m2.print_matriz();
    auto start = high_resolution_clock::now();
    m3 = m1*m2;
    auto stop = high_resolution_clock::now();


//----------------------------------------------

    // CONCURRENTE
    MatrizConcurrente<int> m11(1000,1000), m21(1000,1000), m31(1000,1000);
    m11.print_matriz(); m21.print_matriz();
    auto start = high_resolution_clock::now();
    m31 = m11*m21;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    m31.print_matriz();
    cout << "Time: " << duration.count() << endl;

    return 0;
}
