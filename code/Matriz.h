//
// Created by jeanlee on 19/06/19.
//

#ifndef CODE_MATRIZ_H
#define CODE_MATRIZ_H

template <typename T>
class Matriz{
    int filas;
    int columnas;
    T** matriz;
public:
    Matriz():filas{0}, columnas{0} {};
    Matriz(T filas, T columnas):filas{filas}, columnas{columnas} {
        matriz = new T* [filas];
        for (int i = 0; i < filas; ++i)
            matriz[i] = new T[columnas];
    }

    void set(int pos_fila, int pos_columna, T valor){
        matriz[pos_fila][pos_columna] = valor;
    }
    void print_matriz(){
        for (int i = 0; i < filas; ++i){
            for (int j = 0; j < columnas; ++j)
                cout << matriz[i][j] << "\t";
            cout<<endl;
        }
    }
};

#endif //CODE_MATRIZ_H
