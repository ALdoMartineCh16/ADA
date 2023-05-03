#include <iostream>
#include <cmath>

using namespace std;

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

double raiz_cuadrada(double a, double b) {
    return sqrt(a);
}

int main() {
    double a, b;
    char op;
    double (*operacion)(double, double);

    cout << "Ingrese un número: ";
    cin >> a>>b;
    operacion = &suma;
    cout << "El resultado es: " << operacion(a, b) << endl;

    
    operacion = &resta;
    cout << "El resultado es: " << operacion(a, b) << endl;

    return 0;
}
