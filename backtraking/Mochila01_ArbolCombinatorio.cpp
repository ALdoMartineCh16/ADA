#include <iostream>
#include <vector>
using namespace std;

const int N = 4; // Número de objetos disponibles
const int M = 7; // Capacidad de la mochila

vector<int> pesos = {1, 2, 3, 4}; // Pesos de los objetos
vector<int> beneficios = {2, 3, 4, 5}; // Beneficios de los objetos

vector<int> solucion_actual(N, 0); // Representación de la solución con árbol combinatorio
vector<int> solucion_optima(N, 0); // Solución óptima actual

int valor_optimo_actual = 0; // Valor óptimo actual
int peso_actual = 0; // Peso actual
int beneficio_actual = 0; // Beneficio actual
int contador = 1;

void GenerarArbolCombinatorio(int nivel) {
    if (nivel == N) {
        // Verificar si se alcanzó una solución completa
        if (peso_actual <= M && beneficio_actual > valor_optimo_actual) {
            valor_optimo_actual = beneficio_actual;
            solucion_optima = solucion_actual;
        }

        cout << contador << " => ";
        contador++;

        for (int i = 0; i < solucion_actual.size(); i++) {
            if (solucion_actual[i] == 1) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;

        return;
    }

    // Generar combinaciones con el objeto no cogido (0)
    solucion_actual[nivel] = 0;
    GenerarArbolCombinatorio(nivel + 1);

    // Generar combinaciones con el objeto cogido (1)
    solucion_actual[nivel] = 1;
    peso_actual += pesos[nivel];
    beneficio_actual += beneficios[nivel];
    GenerarArbolCombinatorio(nivel + 1);

    // Deshacer cambios para el retroceso
    peso_actual -= pesos[nivel];
    beneficio_actual -= beneficios[nivel];
}

int main() {
    GenerarArbolCombinatorio(0);

    cout << "Solucion optima: ";
    for (int i = 0; i < N; i++) {
        if (solucion_optima[i] == 1) {
            cout << "Objeto " << i + 1 << " ";
        }
    }
    cout << "\nValor optimo: " << valor_optimo_actual << endl;

    return 0;
}
