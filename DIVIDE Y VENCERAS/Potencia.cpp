#include <iostream>

using namespace std;

// Función para calcular la potencia de un número
double power(double base, int exponente) {
    if (exponente == 0) {
        return 1;
    } else if (exponente % 2 == 0) {
        double temp = power(base, exponente / 2);
        return temp * temp;
    } else {
        double temp = power(base, exponente / 2);
        return base * temp * temp;
    }
}

int main() {
    double base;
    int exponente;
    cout << "Ingrese la base: ";cin>>base;
    cout << "Ingrese el exponente: ";cin>>exponente;
    double resultado = power(base, exponente);
    cout << "El resultado es: " << resultado << endl;

    return 0;
}
