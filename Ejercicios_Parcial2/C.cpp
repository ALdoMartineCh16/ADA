#include <bits/stdc++.h>
using namespace std;

int main() {
    int cant,n,v;
    cin>>cant;
    while(cant--){
        cin>>n;
        
        vector<int> monedas;
        for(int i=0;i<n;i++){
            cin>>v;
            monedas.push_back(v);
        }
        int curSum = 0, rest=0;
        for(int i=0;i<n;i++){
            if(n-1 == i || curSum+monedas[i]<monedas[i+1]){
                curSum += monedas[i];
                rest++;
            }
            
        }

        cout<<rest<<endl;
    }
}
