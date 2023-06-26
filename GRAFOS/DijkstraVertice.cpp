#include<iostream>
#include<list>
#include<limits>

using namespace std;

class Grafo{
	list<pair<int, int>>* ListaAdyacencia;
	int numVertices;
public:
	Grafo(int vertices){
		numVertices = vertices;
		ListaAdyacencia = new list<pair<int, int>>[numVertices];
	}
	
	void addEdge(int principio,int fin,int peso) {
		ListaAdyacencia[principio].push_back(make_pair(fin, peso));
		ListaAdyacencia[fin].push_back(make_pair(principio, peso));
	}
	
	void costoT(int& totalCost, int VerticeInicial) {
		bool* visited = new bool[numVertices];
		for (int i = 0; i < numVertices; ++i) {
			visited[i] = false;
		}
		visited[VerticeInicial] = true;  // Empezar en el nodo especificado
		
		list<int> path;
		path.push_back(VerticeInicial);
		
		int currentVertex = VerticeInicial;
		int minCost = 0;
		
		for (int count = 0; count < numVertices - 1; ++count) {
			int VerticeSig = -1;
			int minWeight = numeric_limits<int>::max();
			
			for (const auto& neighbor : ListaAdyacencia[currentVertex]) {
				int vertice = neighbor.first;
				int peso = neighbor.second;
				
				if (!visited[vertice] && peso < minWeight) {
					VerticeSig = vertice;
					minWeight = peso;
				}
			}
			
			if (VerticeSig != -1) {
				visited[VerticeSig] = true;
				path.push_back(VerticeSig);
				minCost += minWeight;
				currentVertex = VerticeSig;
			}
		}
		
		path.push_back(VerticeInicial);
		minCost += ListaAdyacencia[currentVertex].front().second;
		totalCost = minCost;
		
		cout<<"Camino : ";
		for(int vertice : path){
			cout<<vertice<<" ";
		}
		cout<<endl;
		
		// Mostrar el costo total del camino
		cout<<"COSTO: "<<totalCost<<endl;
		
		delete[] visited;
	}
	
	~Grafo() {
		delete[] ListaAdyacencia;
	}
};

int main() {
	Grafo grafo(5);
	
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
