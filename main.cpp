#include <iostream>
#include "Matriz.cpp"

using namespace std;

int main() {
    srand(time(nullptr));
    int filas, columnas;
    cout<<"Ingresa la dimension: ";
    cin>>filas;
    columnas=filas;

    auto M1=new Matriz(filas,columnas);
    auto M2=new Matriz(filas,columnas);
    auto M3=new Matriz(filas,columnas);
    auto M4= new Matriz(filas,columnas);
    auto M5=new Matriz(filas,columnas);
    auto M6= new Matriz(filas,columnas);


    M1->llenar();
    cout << "Matriz 1: " << '\n';
    M1->imprimir();
    cout <<endl;

    M2->llenar();
    cout << "Matriz 2:" << '\n';
    M2->imprimir();
    cout <<endl;

    *M3 = *M1 + *M2;//Sobrecarga operador +
    cout << "La suma es: " << '\n';
    M3->imprimir();
    cout <<endl;

    *M4 = *M1 * *M2; //Sobrecarga operador *
    cout << "La multiplicacion es: " << '\n';
    M4->imprimir();
    cout <<endl;

    M5->transposicion(*M1);
    cout << "La transpuesta es: " << '\n';
    M5->imprimir();
    cout <<endl;

    M6->escalar(*M1,5);
    cout << "La mult escalar es: " << '\n';
    M6->imprimir();

    delete M1;delete M2;delete M3;delete M4;delete M5;delete M6;
    return 0;
}

