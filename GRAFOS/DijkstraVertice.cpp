#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& grafo, int origen) {
    int n = grafo.size();
    vector<int> distancias(n, INT_MAX);
    vector<bool> visitados(n, false);

    // La cola de prioridad almacena pares (distancia, nodo)
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distancias[origen] = 0;
    pq.push(make_pair(0, origen));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visitados[u]) {
            continue;
        }

        visitados[u] = true;

        for (const auto& vecino : grafo[u]) {
            int v = vecino.first;
            int peso = vecino.second;

            if (!visitados[v] && distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                pq.push(make_pair(distancias[v], v));
            }
        }
    }

    return distancias;
}

int main() {
    int n = 6;  // Número de nodos del grafo
    int origen = 0;  // Nodo de origen

    vector<vector<pii>> grafo(n);
    grafo[0].push_back(make_pair(1, 2));
    grafo[0].push_back(make_pair(2, 5));
    grafo[1].push_back(make_pair(2, 1));
    grafo[1].push_back(make_pair(3, 6));
    grafo[2].push_back(make_pair(3, 3));
    grafo[2].push_back(make_pair(4, 1));
    grafo[3].push_back(make_pair(4, 2));
    grafo[3].push_back(make_pair(5, 4));
    grafo[4].push_back(make_pair(5, 6));

    vector<int> distancias = dijkstra(grafo, origen);

    cout << "Distancias más cortas desde el nodo " << origen << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Nodo " << i << ": " << distancias[i] << endl;
    }

    return 0;
}
