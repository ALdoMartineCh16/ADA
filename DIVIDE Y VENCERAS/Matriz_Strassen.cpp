#include <iostream>
#include <vector>

using namespace std;

// Función para sumar dos matrices
vector<vector<int>> sum(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Función para restar dos matrices
vector<vector<int>> subtract(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Función para multiplicar matrices utilizando el algoritmo de Strassen
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Caso base: si el tamaño de la matriz es 1x1, realizar multiplicación simple
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Dividir las matrices en submatrices de tamaño n/2
    int newSize = n / 2;

    vector<vector<int>> A11(newSize, vector<int>(newSize, 0));
    vector<vector<int>> A12(newSize, vector<int>(newSize, 0));
    vector<vector<int>> A21(newSize, vector<int>(newSize, 0));
    vector<vector<int>> A22(newSize, vector<int>(newSize, 0));
    vector<vector<int>> B11(newSize, vector<int>(newSize, 0));
    vector<vector<int>> B12(newSize, vector<int>(newSize, 0));
    vector<vector<int>> B21(newSize, vector<int>(newSize, 0));
    vector<vector<int>> B22(newSize, vector<int>(newSize, 0));

    // Dividir las matrices A y B en submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calcular los productos de Strassen recursivamente
    vector<vector<int>> P1 = strassen(A11, subtract(B12, B22));
    vector<vector<int>> P2 = strassen(sum(A11, A12), B22);
    vector<vector<int>> P3 = strassen(sum(A21, A22), B11);
    vector<vector<int>> P4 = strassen(A22, subtract(B21, B11));
    vector<vector<int>> P5 = strassen(sum(A11, A22), sum(B11, B22));
    vector<vector<int>> P6 = strassen(subtract(A12, A22), sum(B21, B22));
    vector<vector<int>> P7 = strassen(subtract(A11, A21), sum(B11, B12));

    // Calcular las submatrices del resultado
    vector<vector<int>> C11 = subtract(sum(sum(P5, P4), P2), P6);
    vector<vector<int>> C12 = sum(P1, P2);
    vector<vector<int>> C21 = sum(P3, P4);
    vector<vector<int>> C22 = subtract(subtract(sum(P5, P1), P3), P7);

    // Combinar las submatrices en la matriz de resultado
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            result[i][j] = C11[i][j];
            result[i][j + newSize] = C12[i][j];
            result[i + newSize][j] = C21[i][j];
            result[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return result;
}

// Función para imprimir una matriz
void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};

    vector<vector<int>> B = {{17, 18, 19, 20},
                             {21, 22, 23, 24},
                             {25, 26, 27, 28},
                             {29, 30, 31, 32}};

    cout << "Matriz A:" << endl;
    printMatrix(A);

    cout << "Matriz B:" << endl;
    printMatrix(B);

    vector<vector<int>> C = strassen(A, B);

    cout << "Resultado de la multiplicación de matrices:" << endl;
    printMatrix(C);

    return 0;
}
