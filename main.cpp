#include <iostream>
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
    Matriz M6(filas,columnas);


    M1.llenar();
    cout << "Matriz 1: " << '\n';
    M1.imprimir();
    cout <<endl;

    M2.llenar();
    cout << "Matriz 2:" << '\n';
    M2.imprimir();
    cout <<endl;

    M3 = M1 + M2;//Sobrecarga operador +
    cout << "La suma es: " << '\n';
    M3.imprimir();
    cout <<endl;

    M4 = M1 * M2; //Sobrecarga operador *
    cout << "La multiplicacion es: " << '\n';
    M4.imprimir();
    cout <<endl;

    M5.transposicion(M1);
    cout << "La transpuesta es: " << '\n';
    M5.imprimir();
    cout <<endl;

    M6.escalar(M1,5);
    cout << "La mult escalar es: " << '\n';
    M6.imprimir();


    return 0;
}

