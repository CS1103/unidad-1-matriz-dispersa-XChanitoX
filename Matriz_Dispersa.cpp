//
// Created by Christian on 29/08/2019.
//

#include "Matriz_Dispersa.h"
#include "Definiciones.h"

Matriz_Dispersa::Matriz_Dispersa(const long int &n_filas, const long int &n_columnas) : n_filas(n_filas), n_columas(n_columnas){
    dispersion = 10+rand()%50;
    no_nulos = int((dispersion*n_filas*n_columnas)/100);
}

Matriz_Dispersa::~Matriz_Dispersa() {}

void Matriz_Dispersa::Rellenar_Datos() {
    //se asignan valores del 1 al 99 a la matriz
    for (int i=0;i<no_nulos;i++){
        vector_no_nulos.push_back(rand()%90);
        // se asignan las coordenadas
        vector_n_filas.push_back(rand() % (n_filas + 1));
        vector_n_columnas.push_back(rand() % (n_columnas + 1));
        // se busca que no se repitan
        for (int j=0;j<i;j++){
            if (vector_n_filas[i]==vector_n_filas[j]&&vector_n_columnas[i]==vector_n_columnas[j]){
                vector_n_filas[i]=rand()%(n_filas+1);
                vector_n_columnas[i]=rand()%(n_columnas+1);
            }
        }
    }
}

void Matriz_Dispersa::Imprimir_Matriz() {
    for (int i = 0; i < 5; ++i) {
        cout << datos[i] << endl;
    }
}

Matriz_Dispersa::~Matriz_Dispersa() {
    delete[] filas;
    delete[] columnas;
    delete[] datos;
}