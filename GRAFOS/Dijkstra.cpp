#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#define INF 99999
using namespace std;


template<class V, class A>
class Edge;

template<class V,class A>
class Vertex
{
    public:
     V                   m_Dato;
     int                 m_Costo;
     bool                m_Visit; 
     list<Edge<V,A> >    m_list_Edge;
  
    Vertex(V vertice)
    {
        m_Dato = vertice;
        m_Costo = INF;
        m_Visit = false;

    }

    bool operator==(const Vertex<V,A> & Ve)
    {
        return m_Dato == Ve.m_Dato;
    }

};



template<class V,class A>
class Edge
{
    public:
        A                   m_Dato;
        Vertex<V,A>  *      m_pVertex;

        Edge(A a, Vertex<V,A>  *q=0)
        {
            m_Dato = a;
            m_pVertex=q;
        }


    bool operator==(const Edge<V,A> & Ar)
    {
        return m_Dato == Ar.m_Dato;
    }

};



template<class V,class A>
class Graph
{
   typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex; 
   typedef typename   list<  Edge  <V,A>>::iterator Iterator_Edge;  
   private:
      list< Vertex <V,A> >   m_Graph;
   public:
   Graph(){};

   void Insert(V Vertice)
   {
          m_Graph.push_back(Vertex<V,A>(Vertice));
   };
   void Insert_Edge(V v1, V v2, A a)
   {
         Iterator_Vertex p = find_Vertex(v1);
         Iterator_Vertex q = find_Vertex(v2);
         if(p!= m_Graph.end() && q!= m_Graph.end())
         { 
            // ¿Qué ocurre si la arista y existe?
            Vertex<V,A>* pDestino = &(*q); 
            p->m_list_Edge.push_back(Edge<V,A>(a, pDestino));
         }
          
   };

   void Reset_Graph()
   {
     Iterator_Vertex it = m_Graph.begin();
       for(; it != m_Graph.end();it++)
       {
          it->m_Visit = false;
       }
   }

   void DFS()
   {
       stack< Iterator_Vertex > pila;
       pila.push(m_Graph.begin());
       while (!pila.empty())
       {
           Iterator_Vertex it = pila.top();
           pila.pop();
           if(!it->m_Visit)
           {
                it->m_Visit=true;
                cout<<it->m_Dato<<endl;
           }
           Iterator_Edge it_e = it->m_list_Edge.begin();
           for(; it_e != it->m_list_Edge.end();++it_e)
           {
               if(it_e->m_pVertex->m_Visit==false)
               {
                Iterator_Vertex it_d = find_Vertex(it_e->m_pVertex->m_Dato);
                if(it_d != m_Graph.end())
                  pila.push(it_d);
               }
           }
       }
       
   }

    void BFS()
   {
       Reset_Graph();
       queue< Iterator_Vertex > cola;
       cola.push(m_Graph.begin());
       while (!cola.empty())
       {
           Iterator_Vertex it = cola.front();
           cola.pop();
           
           if(!it->m_Visit)
           {
                it->m_Visit=true;
                cout<<it->m_Dato<<endl;
           }
           Iterator_Edge it_e = it->m_list_Edge.begin();
           for(; it_e != it->m_list_Edge.end();++it_e)
           {
               Iterator_Vertex it_d = find_Vertex(it_e->m_pVertex->m_Dato);
                if(it_d != m_Graph.end() && it_d->m_Visit==false)
                    cola.push(it_d);
               
           }
       }
       
   }

   Iterator_Vertex  find_Vertex(V v)
   {
    return    std::find(m_Graph.begin(), m_Graph.end(), Vertex<V,A>(v));
   } 
     
   
   bool find_edge(V v, A a)
   {
        Iterator_Vertex  p = find_Vertex(v);
        Iterator_Edge    q = std::find(p->m_list_Edge.begin(), p->m_list_Edge.end(), Edge<V,A>(a));
        if(q!=p->m_list_Edge.end())
           return true;   
   }
   void Print()
   {
       typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex; 
       Iterator_Vertex it = m_Graph.begin();
       for(; it != m_Graph.end();it++)
       {
          Iterator_Edge    it_e = it->m_list_Edge.begin();
          for(; it_e != it->m_list_Edge.end();++it_e) 
           { 
              cout<<it->m_Dato<<" ---> "<<it_e->m_Dato<<"---->"<<it_e->m_pVertex->m_Dato<<endl;
           }
          
       }

    }
    
    int mini_dis(vector<int> &d)
    {
        Iterator_Vertex it = m_Graph.begin();
        int min;
        int i=0;
     
        for(; it != m_Graph.end();it++)
        {
            if(!it->m_Visit)
            {
                min = d[i];
                break;   
            }
            i++;
        }
        i=0;
        it = m_Graph.begin();
        for(; it != m_Graph.end();it++)
        {
            if(!it->m_Visit && min > it->m_Costo)
                min = d[i];
            i++;
        }

        return min;
        
    }
   
    
    void disjtrak_alg(V Or)
    {
        typedef priority_queue <int, vector<int>, greater<int> > min_heap;
        typedef Vertex<string,int> vertesss;
        Iterator_Vertex O = find_Vertex(Or);
        O->m_Costo=0;
	    //min_heap d;
	    int n_vectors =m_Graph.size() ;
        vector<int> d(n_vectors, 0);
        vector<string> previus(n_vectors);
        
        //_________________________________________________________________________________________________
        
        for(int m=0; m<n_vectors;m++)
        {
            vector<Edge<string,int>*> lst_edges;
            for(Iterator_Edge or_ed = O->m_list_Edge.begin(); or_ed != O->m_list_Edge.end();++or_ed) 
                lst_edges.push_back(&(*or_ed));
            
            O->m_Visit=true;
            
            int k =0;
            for (Iterator_Vertex it = m_Graph.begin();it!=m_Graph.end(); it++)
            {
                if(it->m_Visit)
                {
                    d[k] = it->m_Costo;
                }
                else
                {
                    bool band=false;
                    for(auto i =lst_edges.begin(); i != lst_edges.end();++i) 
                    { 
                        if((*i)->m_pVertex == &(*it))
                        {
                            if( d[k] != (std::min(O->m_Costo + (*i)->m_Dato, it->m_Costo)))
                                previus[k] = O->m_Dato;
                            d[k] = std::min(O->m_Costo + (*i)->m_Dato, it->m_Costo);
                            
                            band=true;
                            it->m_Costo = std::min(O->m_Costo + (*i)->m_Dato, it->m_Costo)  ;
                            lst_edges.erase(i);
                            break;
                        }
                    }
                    if(!band)
                        d[k] = it->m_Costo;
                }
                k++;
            }
            lst_edges.clear();
            
            if(m==0){
                O->m_Costo= d[0]=INF;
            }
            
            int peso = mini_dis(d);

            Iterator_Vertex ittt = m_Graph.begin();
            vector<int>::iterator it_vd = d.begin();
            
            for(; ittt != m_Graph.end();ittt++)
            {
                if((*it_vd) ==peso && !ittt->m_Visit){
                    O = ittt;
                    break;
                }
 
                it_vd++;
            }
            k=0;
            
        }
        
        
        
        cout<<"\n\ndistanaci: "<<d.size()<<endl;

        for(int l=0;l<d.size();l++)
            cout<<d[l]<< "\t\t: " <<previus[l]<<endl;

    }



   

};


void test1()
{
   Graph<string, int>  G;
   G.Insert("Arequipa");
   G.Insert("Lima");
   G.Insert("Cusco");
   G.Insert("Puno");
   G.Insert("Tacna");
   G.Insert("Ica");

   G.Insert_Edge("Arequipa","Cusco",100);
   G.Insert_Edge("Arequipa","Puno",160);
   G.Insert_Edge("Arequipa","Lima",1500);
   G.Insert_Edge("Puno","Ica",1500);
   G.Insert_Edge("Puno","Tacna",1070);
   G.Insert_Edge("Cusco","Puno",400);
   G.Insert_Edge("Cusco","Tacna",600);
   G.Insert_Edge("Tacna","Lima",600);
   G.Insert_Edge("Tacna","Arequipa",600);
   G.Insert_Edge("Lima","Puno",600);
   G.Insert_Edge("Ica","Arequipa",600);
   
   //G.Print();
   //G.BFS();
   G.disjtrak_alg("Arequipa"); 
        
}
int main()
{
    test1();
    return 1;
}

