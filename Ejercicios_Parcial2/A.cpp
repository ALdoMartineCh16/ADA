#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){

    vector<int>lista;
    
    int x,c=0;
    
    while(cin>>x){
        lista.push_back(x);
        sort(lista.begin(),lista.end());
        
        if(c%2==0){
            int mid=(0+c)/2;
            cout<<lista[mid]<<endl;
        }
        else{
            int mid=(0+c)/2;
            int min=mid+1;
            int val=(lista[mid]+lista[min])/2;
            cout<<val<<endl;
        }
        c++;
    }

    return 0;
}
