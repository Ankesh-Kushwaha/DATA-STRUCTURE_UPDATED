#include<iostream>
#include<list>
using namespace std;

class Graph{
  int V; //v=no. of vertex
  list<int> *l;
  public:
  Graph(int V){
    this->V=V;
    l=new list<int> [V];
  }

  void addedge(int u,int v){ //u---v ->two edges
   l[u].push_back(v);
   l[v].push_back(u);
  }

  void print(){
      for(int u=0;u<V;u++){
         list<int> neighbour=l[u];
         cout<<u<<":"<<" ";
         for(int v:neighbour){
           cout<<v<<" ";
         }
         cout<<endl;
      }
  }
};
int main(){
Graph gp(5);
gp.addedge(0,1);
gp.addedge(1,2);
gp.addedge(1,3);
gp.addedge(2,3);
gp.addedge(2,4);

gp.print();
  return 0;
}