//
// Created by Christian on 29/08/2019.
//

#ifndef MATRIZ_DISPERSA_MATRIZ_DISPERSA_H
#define MATRIZ_DISPERSA_MATRIZ_DISPERSA_H

#include "Definiciones.h"

class Matriz_Dispersa {
private:
    int n_filas, n_columnas, dispersion, no_nulos;
    vector<int>vector_no_nulos;
    vector<int>vector_n_filas;
    vector<int>vector_n_columnas;
public:
    Matriz_Dispersa();
    Matriz_Dispersa(const long int &, const long int &);

    friend Matriz_Dispersa operator *(const int &, const Matriz_Dispersa &);
    friend Matriz_Dispersa operator *(const Matriz_Dispersa &, const Matriz_Dispersa &);
    friend Matriz_Dispersa operator +(const Matriz_Dispersa &, const Matriz_Dispersa &);

    void Rellenar_Datos();

    int getElement(int &primero, int &segundo)const;

    virtual ~Matriz_Dispersa();

    void setAllValues(const int&);

    Matriz_Dispersa transpuesta();

};


#endif //MATRIZ_DISPERSA_MATRIZ_DISPERSA_H