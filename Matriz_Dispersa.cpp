//
// Created by ALONSO on 29/08/2019.
//

#include "Matriz_Dispersa.h"

Matriz_Dispersa::Matriz_Dispersa(int nFilas, int nColumas) : n_filas(nFilas), n_columas(nColumas){
    srand(time(NULL));
    filas = new int[n_filas];
    columnas = new int[n_columas];
    int aleatorio = 1+(rand()%50);
    long long int dispersion = n_filas*n_columas*aleatorio/100;
    datos = new TipoDato[dispersion];
}

void Matriz_Dispersa::Rellenar_Datos() {
    for (int i = 0; i < dispersion; ++i) {
        datos[i] = 1+(rand()%50);
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








