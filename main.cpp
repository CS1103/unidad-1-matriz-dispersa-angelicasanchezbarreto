#include <iostream>
#include <cassert>
#include "Matriz.cpp"

using namespace std;

int main() {


    int filas, columnas;
    cout<<"Ingresar filas: ";
    cin>>filas;
    cout<<"Ingrese columnas: ";
    cin>>columnas;

    Matriz M1(filas,columnas);
    Matriz M2(filas,columnas);
    Matriz M3(filas,columnas);
    Matriz M4(filas,columnas);
    Matriz M5(filas,columnas);


    M1.llenar();
    std::cout << "Matriz 1: " << '\n';
    M1.imprimir();
    cout <<endl;
    srand(time(NULL));

    M2.llenar();
    std::cout << "Matriz 2:" << '\n';
    M2.imprimir();
    cout <<endl;

    M3 = M1 * M2; //Sobrecarga operador * y +
    std::cout << "La multiplicacion es: " << '\n';
    M3.imprimir();
    cout <<endl;

    M4.transposicion(M3);
    std::cout << "La transpuesta es: " << '\n';
    M4.imprimir();
    cout <<endl;

    M5.escalar(M1,5);
    std::cout << "La mult escalar es: " << '\n';
    M5.imprimir();



    return 0;
}

