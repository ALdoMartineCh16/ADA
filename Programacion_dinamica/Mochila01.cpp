#include <iostream>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void mochila01(int m, int peso[], int beneficio[], int n) {
    int matriz[n+1][m+1];

    for (int i=0;i<=n;i++) {
        for (int j=0; j<=m; j++) {
            if(i==0 || j==0) {
                matriz[i][j] = 0;
            }else if(peso[i-1]<=j) {
                matriz[i][j] = max(beneficio[i-1]+matriz[i-1][j-peso[i-1]],matriz[i-1][j]);
            }else{
                matriz[i][j] = matriz[i-1][j];
            }
            cout<<matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    cout<<"El beneficio maximo es: "<<matriz[n][m]<<endl;
}
int main() {
   
    int n,m;
    cout<<"Numero de objetos: ";cin>> n;
    cout<<"Capacidad maxima de la mochila: ";cin>> m;
    
    int pesos[n],beneficios[n];
    for(int i=0;i<n;i++){
        cout<<"Peso "<<i+1<<": ";cin>>pesos[i];
        cout<<"Beneficios "<<i+1<<": ";cin>>beneficios[i];
    }
    mochila01(m, pesos, beneficios, n);

    return 0;
}

