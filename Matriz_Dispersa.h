//
// Created by ALONSO on 29/08/2019.
//

#ifndef MATRIZ_DISPERSA_MATRIZ_DISPERSA_H
#define MATRIZ_DISPERSA_MATRIZ_DISPERSA_H

#include "Definiciones.h"

class Matriz_Dispersa {
private:
    int n_filas, n_columas, dispersion;
    int* filas;
    int* columnas;
    TipoDato* datos;
public:
    Matriz_Dispersa(int nFilas, int nColumas);

    void Rellenar_Datos();

    void Imprimir_Matriz();

    virtual ~Matriz_Dispersa();


};


#endif //MATRIZ_DISPERSA_MATRIZ_DISPERSA_H
