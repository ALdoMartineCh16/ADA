#include <iostream>

using namespace std;

int condition(int i,int n,int &count){
    count++;
    return i < n;
}

void funcion1(int _n){
    
    int n=_n;
    int a=0,b=0,c=0;
    
    for(int i=0;condition(i,n,a);i++){  //n + 1
        b++; 
        if(i % 2 == 0){ // n 
            c++; 
            cout<<i<<endl; // n/2 (piso) + 1
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<endl;
}

void funcion2(int _n){
    int n=_n;
    //contadores del primer for {a,b,c}
    //contadores del segundo for {d,e,f}
    int a=0,b=0,c=0,d=0,e=0,f=0;
    
    for(int i=0;condition(i,n,a);i++){ //n+1
        b++;
        if(i % 2 == 0){ //n
            c++;
            cout<<i<<endl; //n/2 (piso) + 1
        }
    }
    
    for(int i=0;condition(i,n,d);i++){ //n+1
        e++;
        if(i % 2 != 0){ //n
            f++;
            cout<<i<<endl; //n/2 (piso)
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"-"<<e<<"-"<<f<<endl;
    //
}

void funcion3(int _n){
    int n=_n;
    
    int a=0,b=0,c=0;
    
    for(int i=0;condition(i,n,a);i++){ //n+1
        for(int j=i;condition(j,n,b);j++){ // (n+1)(n)/2 + n
            c++;
            cout<<i<<","<<j<<endl; //n(n+1)/2
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<endl;
    //O(n^2)
}

void funcion4(int _n){
    int n=_n,i=1; //1
    int a=0,b=0,c=0;
    while(condition(i,n,a)){ //log2n + 1 se redondeda el log2n a techo
        cout<<i<<endl; b++;//log2n 
        i *= 2; c++;//log2n
    }
    cout<<a<<"-"<<b<<"-"<<c<<endl;
    //O(log2n)
}

void funcion5(string _a,string _b){
    string A = _a, B = _b; 
    int a=0,b=0,c=0;
    for(int i=0;i <= A.size()+2;i++){ // A + 1
        for(int j=0;j <= B.size()+1;j++){ // A(B+1)
            c++;
            cout<<A[i]<<","<<B[j]<<endl; // AB
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<endl;
    //O(A*B)
}

void funcion6(int _n){
    int n=_n,j;
    int a=0,b=0,c=0,d=0,e=0;
    for(int i=0; condition(i,n,a);i++){ //n+1 
        j=1; b++; // n --9
        while(condition(j,n,c)){ //n(log2n + 1) 
            cout<<j<<endl; d++; //n(log2n)  
            j *= 2; e++; //n(log2n)
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"-"<<e<<endl;
    //O(nlog2n)
}

void funcion7(){
    int a=0,b=0,c=0,d=0,e=0;
    int n = 1000; a++; //1
    if(n % 2 == 0){ //1
        b++;
        cout<<"par"<<endl; //1
    }
    else{ 
        c++;
        cout<<"impar"<<endl;
    }
    //3
    //O(1)
}


int main(){
    
    funcion1(12);
    funcion2(21);
    funcion4(33);
    funcion7();
    funcion5("HOLA","MUNDO");
    funcion6(9);
    return 0;
}
