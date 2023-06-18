#include <iostream>

using namespace std;

struct mochila{
    float peso;
    float beneficio;
    float ind;
};

float Mochila(mochila *elemento, float pesomax){
    float valmax =0;
    int i=0;
    
    while(pesomax>0){
        if(pesomax>elemento[i].peso){
            pesomax -= elemento[i].peso;
            valmax += elemento[i].beneficio;
        }else{
            valmax += elemento[i].beneficio*(pesomax/elemento[i].peso);
            pesomax = 0;
        }
        i++;
    }
    return valmax;
}

int main()
{
    int n, max, j, cont;
    mochila *elemento, aux;
    
    cout<<"Numero de elementos: ";cin>>n;
    
    elemento = new mochila[n];
    
    for(int i=0;i<n;i++){
        cout<<"\nElemento "<<i<<":\n";
        cout<<"Peso: ";cin>>elemento[i].peso;
        cout<<"beneficio: ";cin>>elemento[i].beneficio;
        
        elemento[i].ind = elemento[i].beneficio/elemento[i].peso;
    }
    //ordenar listas
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(elemento[i].ind<elemento[j].ind){
                aux = elemento[i];
                elemento[i] = elemento[j];
                elemento[j] = aux;
            }
        }
    }
  
    float pesomax;
    cout<<"Peso maximo de la mochila: ";cin>>pesomax;
    
    cout<<"El valor maximo es "<<Mochila(elemento,pesomax)<<endl;
    
    return 0;
}
