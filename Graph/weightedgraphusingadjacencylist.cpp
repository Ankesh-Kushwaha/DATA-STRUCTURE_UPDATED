#include <iostream>
#include<list>
using namespace std;

class Graph{
  int V;
  list<pair<int,int>> *l;
  public:
  Graph(int V){
    this->V=V;
    l=new list<pair<int,int>> [V];
  }

  void addedge(int u,int v,int wt){
    l[u].push_back(make_pair(v,wt));
    l[v].push_back(make_pair(u,wt));
  }

  void print(){
    for(int u=0;u<V;u++){
      cout<<u<<":"<<" ";
      for(auto v:l[u]){
        cout<<"("<<v.first<<" "<<v.second<<") ";
      }
      cout<<endl;
    }
  }

};
int main(){
Graph gp(5);
gp.addedge(0,1,5);
gp.addedge(1,2,1);
gp.addedge(2,3,1);
gp.addedge(1,3,3);
gp.addedge(2,4,2);
gp.print();
  return 0;
}