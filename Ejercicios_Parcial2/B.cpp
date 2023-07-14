#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct coordenada{
    double x;
    double y;
};

double combine(coordenada a[],int low,int medio,int high,double min_left,double min_right);

bool cmp(coordenada a,coordenada b)
{
    return a.x<b.x;
}
double Distancia(coordenada a,coordenada b) {return (double)sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));}

double particion(coordenada a[],int low,int high)
{
    if(low>=high){return 99999;}
    
    int medio=(low+high)/2;
    double min_left=particion(a,low,medio);
    double min_right=particion(a,medio+1,high);
    return combine(a,low,medio,high,min_left,min_right);
}

double combine(coordenada a[],int low,int medio,int high,double min_left,double min_right)
{
    double d=(min_left<min_right)?min_left:min_right;
    double line=(double)(a[medio].x+a[medio+1].x)*0.5;
    double min_D=d;
    
    for(int i=medio+1;a[i].x<line+d && i<=high;i++){
        for(int j=medio;a[j].x>line-d && j>=low;j--){
            double temp = Distancia(a[i],a[j]);
            if(temp<min_D) min_D=temp;
        }
    }
    return min_D;
}
int main()
{
    int N;
    coordenada punto[10001];
    while(cin>>N)
    {
        if (N==0) break;
        
        for(int i=0;i<N;i++){
            cin>>punto[i].x>>punto[i].y;
        }
        
        sort(punto,punto+N,cmp);
        double dis=particion(punto,0,N-1);
        if(dis>=10000.0) {
            cout<<"INFINITY"<<endl;
            
        }else{
            cout<<dis<<endl;
        }
    }
    return 0;
}
