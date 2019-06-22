#include "Matriz.h"
#include "MatrizConcurrente.h"
#include <random>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include<sys/time.h>
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
    struct timeval start{};
    struct timeval finish{};
    long compTime; double Time_2;
    MatrizConcurrente<int> m11(10,10); MatrizConcurrente<int> m21(10,10); MatrizConcurrente<int> m31(10,10);
    m11.print_matriz(); m21.print_matriz();

    gettimeofday(&start, nullptr);
    m31 = m11*m21;
    gettimeofday(&finish, nullptr);

    compTime=(finish.tv_sec - start.tv_sec)*1000000.0;
    compTime=compTime+(finish.tv_usec - start.tv_usec);
    Time_2=(double)compTime;
    std::cout << "El tiempo que se demoro usando hilos fue "<< (double)Time_2/1000000.0 <<" Secs \n";
    std::cout << std::endl;
    m31.print_matriz();

    return 0;
}