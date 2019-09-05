//
// Created by Christian on 29/08/2019.
//

#include "Matriz_Dispersa.h"
#include "Includes.h"

Matriz_Dispersa::Matriz_Dispersa(const long int &n_filas, const long int &n_columnas) : n_filas(n_filas), n_columas(n_columnas){
    dispersion = 10+rand()%50;
    no_nulos = int((dispersion*n_filas*n_columnas)/100);
}

Matriz_Dispersa::~Matriz_Dispersa() {}

Matriz_Dispersa::Matriz_Dispersa():n_filas(0),n_columnas(0),no_nulos(0),dispersion(0) {}

void Matriz_Dispersa::Rellenar_Datos() {

    for (int i=0;i<no_nulos;i++){
        vector_no_nulos.push_back(rand()%90);

        vector_n_filas.push_back(rand() % (n_filas + 1));
        vector_n_columnas.push_back(rand() % (n_columnas + 1));

        for (int j=0;j<i;j++){
            if (vector_n_filas[i]==vector_n_filas[j]&&vector_n_columnas[i]==vector_n_columnas[j]){
                vector_n_filas[i]=rand()%(n_filas+1);
                vector_n_columnas[i]=rand()%(n_columnas+1);
            }
        }
    }
}

int Matriz_Dispersa::getElement(int &primero, int &segundo) const{
    int valor = 0;
    for (int i = 0; i < no_nulos; i++) {
        if(vector_n_filas[i]==primero && vector_n_columnas[i]==segundo){
            valor=vector_no_nulos[i];
        }
    }
    return valor;
}

Matriz_Dispersa operator*(const Matriz_Dispersa & m1, const Matriz_Dispersa & m2) {
    int valor=0;
    if (m1.n_columnas==m2.n_filas){
        Matriz_Dispersa temp(m1.n_filas,m2.n_columnas);
        for (int k=0;k<m1.n_filas;k++) {
            for (int i = 0; i < m1.n_filas; i++) {
                for (int j = 0; j < m2.n_columnas; j++) {
                    valor += m1.getElement(k, j) * m2.getElement(j, i);
                }
                if (valor != 0) {
                    temp.vector_no_nulos.push_back(valor);
                    temp.vector_n_filas.push_back(k);
                    temp.vector_n_columnas.push_back(i);
                }
            }
        }
        return temp;
    }
    else throw logic_error("No es posible efectuar la multiplicacion");
}

Matriz_Dispersa operator+(const Matriz_Dispersa &m1, const Matriz_Dispersa &m2) {
    Matriz_Dispersa m3(m1.n_filas,m1.n_columnas);
    if (m1.n_filas ==m2.n_filas && m1.n_columnas==m2.n_columnas){
        for (int i=0;i<m1.n_filas;i++){
            for (int j=0;j<m1.n_columnas;j++){
                if (m1.getElement(i,j)==0 && m2.getElement(i,j)==0){}
                else {
                    m3.vector_no_nulos.push_back(m1.getElement(i,j)+m2.getElement(i,j));
                    m3.vector_n_filas.push_back(i);
                    m3.vector_n_columnas.push_back(j);
                }
            }
        }
        m3.no_nulos=m3.vector_no_nulos.size();
        return m3;
    }
    else
        throw logic_error("Las matrices tienen diferentes dimensiones");
}

Matriz_Dispersa operator*(const int & valor, const Matriz_Dispersa & m1) {
    Matriz_Dispersa temp(m1.n_filas,m1.n_columnas,m1.no_nulos);
    for (int i=0;i<m1.no_nulos;i++){
        temp.vector_no_nulos.push_back(m1.vector_no_nulos[i]*valor);
        temp.vector_n_columnas.push_back(m1.vector_n_columnas[i]);
        temp.vector_n_filas.push_back(m1.vector_n_filas[i]);
    }
    return temp;
}

void Matriz_Dispersa::setAllValues(const int & valor) {
    if (vector_valores.empty())
        for (tipoEntero i=0;i<c_noNulos;i++){
            vector_valores.push_back(valor);
        }
    else
        for (tipoEntero i=0;i<c_noNulos;i++){
            vector_valores[i]= valor;
        }
}

MatrizDispersa::MatrizDispersa(const long int &cFilas, const long int &cColumnas, const long int &cNoNulos):
        c_filas(cFilas),c_columnas(cColumnas),c_noNulos(cNoNulos){}