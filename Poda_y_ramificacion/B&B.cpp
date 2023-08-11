#include <bits/stdc++.h>
/*
Algoritmo B&B para resolver el problema de la asignación con la siguiente matriz de costes:
x  f1 f2 f3 f4
d1 94 1 54 68
d2 74 10 88 82
d3 62 88 8 76
d4 11 74 81 21
*/

using namespace std;

const int INF = INT_MAX;

int n = 4; // Número de trabajadores y tareas
vector<vector<int>> costs = {
    {94, 1, 54, 68},
    {74, 10, 88, 82},
    {62, 88, 8, 76},
    {11, 74, 81, 21}
};

int minCost = INF;
vector<int> bestAssignment;

void branchAndBound(int worker, vector<bool>& assigned, vector<int>& assignment, int cost) {
    if (worker == n) {
        if (cost < minCost) {
            minCost = cost;
            bestAssignment = assignment;
        }
        return;
    }

    for (int task = 0; task < n; ++task) {
        if (!assigned[task]) {
            assigned[task] = true;
            assignment[worker] = task;
            branchAndBound(worker + 1, assigned, assignment, cost + costs[worker][task]);
            assigned[task] = false;
        }
    }
}

int main() {
    vector<bool> assigned(n, false);
    vector<int> assignment(n);
    
    branchAndBound(0, assigned, assignment, 0);

    cout << "Asignación óptima: ";
    for (int worker = 0; worker < n; ++worker) {
        cout << "f" << (worker + 1) << "->d" << (bestAssignment[worker] + 1) << " ";
    }
    cout << endl;
    cout << "Costo mínimo: " << minCost << endl;

    return 0;
}
