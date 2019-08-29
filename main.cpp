#include "Definiciones.h"
#include "Matriz_Dispersa.h"
#include "Matriz_Dispersa.cpp"

int main() {
    Matriz_Dispersa* matriz = new Matriz_Dispersa(4,4);

    matriz->Rellenar_Datos();
    matriz->Imprimir_Matriz();
    delete matriz;
    return 0;
}