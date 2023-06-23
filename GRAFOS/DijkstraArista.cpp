#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int destino;
    int peso;

    Edge(int _destino, int _peso) {
        destino = _destino;
        peso = _peso;
    }
};

vector<int> dijkstra(vector<vector<Edge>>& grafo, int origen) {
    int n = grafo.size();
    vector<int> distancias(n, INT_MAX);
    vector<bool> visitados(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distancias[origen] = 0;
    pq.push(make_pair(0, origen));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visitados[u]) {
            continue;
        }

        visitados[u] = true;

        for (const auto& arista : grafo[u]) {
            int v = arista.destino;
            int peso = arista.peso;

            if (!visitados[v] && distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                pq.push(make_pair(distancias[v], v));
            }
        }
    }

    return distancias;
}

int main() {
    int n = 6;
    int origen = 0;

    vector<vector<Edge>> grafo(n);

    grafo[0].push_back(Edge(1, 2));
    grafo[0].push_back(Edge(2, 5));
    grafo[1].push_back(Edge(2, 1));
    grafo[1].push_back(Edge(3, 6));
    grafo[2].push_back(Edge(3, 3));
    grafo[2].push_back(Edge(4, 1));
    grafo[3].push_back(Edge(4, 2));
    grafo[3].push_back(Edge(5, 4));
    grafo[4].push_back(Edge(5, 6));

    vector<int> distancias = dijkstra(grafo, origen);

    cout << "Distancias más cortas desde el nodo " << origen << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Nodo " << i << ": " << distancias[i] << endl;
    }

    return 0;
}
