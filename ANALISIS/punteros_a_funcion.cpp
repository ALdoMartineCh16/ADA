#include <iostream>
#include <cmath>

using namespace std;

typedef double(*Ptr_operation)(double,double);

double suma(double a, double b) {
    return a + b;
}

double resta(double a, double b) {
    return a - b;
}

double multiplicacion(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    return a / b;
}

double potencia(double a, double b) {
    return pow(a, b);
}

double radicacion(double a, double b) {
    return pow(a,1/b);
}

int main() {
    double a, b, resultado;
    int opc;
    Ptr_operation vector_operaciones[6] = {&suma,&resta,&multiplicacion,&division,&potencia,&radicacion};

    cout << "Ingrese dos números: ";
    cin >> a>>b;
    //0-Addition, 1-Subtraction, 2-Multiplication, 3-Division, 4-Potencia, 5-radical
    cout << "Opcion: ";
    cin >> opc;
    
    resultado = (*vector_operaciones[opc])(a,b);
    cout<<"El resultado es: "<<resultado;
    return 0;
}
