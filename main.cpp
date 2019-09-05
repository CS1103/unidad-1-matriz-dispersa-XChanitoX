#include "Includes.h"
#include "Matriz_Dispersa.h"
#include "Matriz_Dispersa.cpp"

int main() {
    Matriz_Dispersa m1(10,10);

    m1.Rellenar_Datos();

    Matriz_Dispersa m2 = m1.Transpuesta();

    Matriz_Dispersa m3 = 3*m1;

    Matriz_Dispersa m4 = m3*m1;

    cout << "Matriz 1: " << endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << m1.getElement(i,j) << " ";
        }
        cout << endl;
    }

    cout << "Matriz 2: " << endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << m1.getElement(i,j) << " ";
        }
        cout << endl;
    }

    return 0;
}