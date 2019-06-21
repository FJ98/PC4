// Created by felix on 6/19/2019.
#ifndef CODE_MATRIZCONCURRENTE_H
#define CODE_MATRIZCONCURRENTE_H

#include <iostream>
static const int THREADS_NUMBER = 4;
using namespace std;

template <typename T>
class Matriz2{
    int filas;
    int columnas;
    T** matriz;
    int thread_id;
public:
    Matriz2():filas{0}, columnas{0}, thread_id{0} {};
    Matriz2(T filas, T columnas):filas{filas}, columnas{columnas}, thread_id{0} {
        matriz = new T *[filas];
        for (int i = 0; i < filas; ++i){
            matriz[i] = new T[columnas];
        }
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                matriz[i][j] = rand()%3 + 1;
            }
        }
    }

    T get (int i, int j) { return matriz[i][j]; }
    T get_filas () { return filas; }
    T get_columnas () { return columnas; }
    T get_thread_id () { return thread_id; }
    void set(int pos_fila, int pos_columna, T valor){
        matriz[pos_fila][pos_columna] = valor;
    }

    Matriz2 operator+(Matriz2 other) const{
        Matriz2<T> temp(filas,columnas);
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j)
                temp.set(i,j,matriz[i][j] + other.get(i,j));
        }
        return temp;
    }

    Matriz2 operator*(Matriz2 other) const{
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < other.columnas; ++j){
                for (int k = 0; k < columnas; ++k) {
                    other.matriz[i][j] += matriz[i][k] * other.matriz[k][j];
                }
            }
        }
        return other;
    }
    Matriz2 & operator= (Matriz2 other) {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                matriz[i][j] = other.matriz[i][j];
            }
        }
    }

    bool igual_dimension(Matriz2 other){
        return ((filas == other.get_filas()) && (columnas == other.get_columnas()));
    }

    void print_matriz(){
        for (int i = 0; i < filas; ++i){
            for (int j = 0; j < columnas; ++j)
                cout << matriz[i][j] << "\t";
            cout<<endl;
        } cout<<endl;
    }
};




#endif //CODE_MATRIZCONCURRENTE_H
