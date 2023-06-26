#include <iostream>
#include <list>
#include <limits>
using namespace std;


class Grafo {
	list<pair<int, int>>* ListaAdyacencia;
	int numVertices;	
public:
	Grafo(int vertices){
		numVertices = vertices;
		ListaAdyacencia = new list<pair<int, int>>[numVertices];
	}
	
	void addEdge(int inicio, int fin, int peso) {
		ListaAdyacencia[inicio].push_back(make_pair(fin, peso));
		ListaAdyacencia[fin].push_back(make_pair(inicio, peso));
	}
	
	void costoT(int& totalCost,int VerticeInicial) {
		bool* visited = new bool[numVertices];
		for (int i = 0; i < numVertices; ++i) {
			visited[i] = false;
		}
		visited[VerticeInicial] = true;  
		list<pair<int, int>> path;  
		int currentVertex = VerticeInicial;
		int minCost = 0;
		
		for (int count = 0; count < numVertices - 1; ++count) {
			int nextVertex = -1;
			int minWeight = std::numeric_limits<int>::max();
			
			for (const auto& neighbor : ListaAdyacencia[currentVertex]) {
				int vertex = neighbor.first;
				int weight = neighbor.second;
				
				if (!visited[vertex] && weight < minWeight) {
					nextVertex = vertex;
					minWeight = weight;
				}
			}
			
			if (nextVertex != -1) {
				visited[nextVertex] = true;
				path.push_back(std::make_pair(currentVertex, nextVertex));
				minCost += minWeight;
				currentVertex = nextVertex;
			}
		}
		
		path.push_back(std::make_pair(currentVertex, 0));
		minCost += ListaAdyacencia[currentVertex].front().second;
		
		totalCost = minCost;
		
		for (const auto& edge : path) {
			cout<<"(" << edge.first << "," << edge.second << ") "<<endl;
		}
		cout<<endl;
		
		cout<<"Costo: "<<totalCost<<endl;
		
		delete[] visited;
	}
	
	~Grafo() {
		delete[] ListaAdyacencia;
	}
};

int main() {
	Grafo grafo(6);
	
	grafo.addEdge(0, 1, 10);
	grafo.addEdge(0, 2, 55);
	grafo.addEdge(0, 3, 25);
	grafo.addEdge(0, 4, 45);
	grafo.addEdge(1, 2, 20);
	grafo.addEdge(1, 3, 25);
	grafo.addEdge(1, 4, 40);
	grafo.addEdge(2, 3, 15);
	grafo.addEdge(2, 4, 30);
	grafo.addEdge(3, 4, 50);
	
	int totalCost = 0;
	int VerticeInicial = 1;  // Cambiar el nodo de inicio aquí
	grafo.costoT(totalCost, VerticeInicial);
	
	return 0;
}
