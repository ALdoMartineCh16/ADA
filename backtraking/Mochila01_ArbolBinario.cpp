#include <bits/stdc++.h>

using namespace std;

class Objeto {
public:
    int peso;
    int beneficio;
    Objeto(int p, int b) {
        peso = p;
        beneficio = b;
    }
};

void Actualizar(vector<int>& solucion, vector<Objeto>& objetos, vector<int>& mochilaFinal, int& pFinal, int& bfinal) {
    int beneficioTotal = 0;
    int pesoTotal = 0;
    for (int i = 0; i < objetos.size(); i++) {
        if (solucion[i] == 1) {
            beneficioTotal += objetos[i].beneficio;
            pesoTotal += objetos[i].peso;
        }
    }
    if (beneficioTotal > bfinal) {
        for (int i = 0; i < objetos.size(); i++) {
            mochilaFinal[i] = solucion[i];
        }
        pFinal = pesoTotal;
        bfinal = beneficioTotal;
    }
}

bool validarSolucion(const vector<int>& solucion, int etapa, vector<Objeto>& objetos, int capacidadMochila) {
    int pesoTotal = 0;
    for (int i = 0; i <= etapa; i++) {
        if (solucion[i] == 1) {
            pesoTotal += objetos[i].peso;
        }
    }
    return pesoTotal <= capacidadMochila;
}

void ArbolBinario(vector<int>& solucion, int nivel, vector<Objeto>& objetos) {
    if (nivel >= objetos.size()) return;

    cout<<nivel+1<<": ";
    for (int i = 0; i <= nivel; i++) {
        if (solucion[i] == 0) {
            cout << "No ";
        } else if (solucion[i] == 1) {
            cout << "Si ";
        } else {
            cout << "NA ";
        }
    }
    cout << endl;
    solucion[nivel] = 1;
    ArbolBinario(solucion, nivel + 1, objetos);
    solucion[nivel] = 0;
    ArbolBinario(solucion, nivel + 1, objetos);
    solucion[nivel] = -1;
}



void BackTracking(int M,vector<int>& solucion, int etapa, vector<Objeto>& objetos, vector<int>& mochilaFinal, int& pFinal, int& bfinal) {
    int i = 0;
    if (etapa>objetos.size()-1) return;
    
    do {
        solucion[etapa] = i;
        if (validarSolucion(solucion, etapa, objetos, M)) {
            if (etapa == objetos.size() - 1)
                Actualizar(solucion, objetos, mochilaFinal, pFinal, bfinal);
            else
                BackTracking(M,solucion, etapa + 1, objetos, mochilaFinal, pFinal, bfinal);
        }
        i++;
    }while(solucion[etapa]!=1);
    solucion[etapa]=-1;
}

int main() {
    int n, M;
    cout<<"Ingrese el numero de objetos: ";cin>>n;
    cout<<"Ingrese la capacidad de la mochila: ";cin>>M;
    vector<int> p(n), b(n);
    
    for(int i=0;i<n;i++){
        cout<<"\nElemento["<<i+1<<"]: "<<endl;
        cout<<"Peso: ";cin>>p[i];
        cout<<"Beneficio: ";cin>>b[i];
    }

    vector<Objeto> objetos;
    for (int i = 0; i < n; i++) {
        objetos.push_back(Objeto(p[i], b[i]));
    }

    vector<int> solActual(n, -1), Mochi01(n, 0);
    int pFinal = 0, bFinal = 0;

    cout<<"Arbol binario de decisiones:"<<endl;
    ArbolBinario(solActual, 0, objetos);
    BackTracking(M,solActual, 0, objetos, Mochi01, pFinal, bFinal);

    cout<<"Solucion optima Mochila: "<<endl;
    for (int i=0; i<n; i++) {
        if (Mochi01[i]==1) {
            cout<<"Objeto "<<i+1<<" ";
        }
    }
    cout<<"\nValor Optimo: "<<bFinal<<endl;
    return 0;
}
