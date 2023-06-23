#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> cambioMonedas(vector<int>& denominaciones, int monto) {
    int n = denominaciones.size();
    
    vector<int> solucion(monto + 1, INT_MAX);
    
    solucion[0] = 0;
    
    for (int i = 1; i <= monto; i++) {
        for (int j = 0; j < n; j++) {
            if (denominaciones[j] <= i) {
                int subproblema = solucion[i - denominaciones[j]];
                if (subproblema != INT_MAX && subproblema + 1 < solucion[i]) {
                    solucion[i] = subproblema + 1;
                }
            }
        }
    }
    
    vector<int> combinacion;
    int montoActual = monto;
    while (montoActual > 0) {
        for (int j = 0; j < n; j++) {
            if (denominaciones[j] <= montoActual && solucion[montoActual - denominaciones[j]] == solucion[montoActual] - 1) {
                combinacion.push_back(denominaciones[j]);
                montoActual -= denominaciones[j];
                break;
            }
        }
    }
    
    return combinacion;
}

int main() {
    vector<int> denominaciones = {1, 5, 10, 25};
    int monto = 47;
    
    vector<int> combinacion = cambioMonedas(denominaciones, monto);
    
    cout << "Combinación de monedas para el monto " << monto << ":" << endl;
    for (int i = 0; i < combinacion.size(); i++) {
        cout << combinacion[i] << " ";
    }
    cout << endl;
    
    return 0;
}
