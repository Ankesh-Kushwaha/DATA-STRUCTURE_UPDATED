#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph{
int V;
list<int> *l;
bool undir;

public:
Graph(int V,bool undir){
 this->V=V;
 l=new list<int> [V];
 this->undir=undir;
}

void addedge(int u,int v){
 l[u].push_back(v);
 if(undir){
   l[v].push_back(u);
 }
}

  void calcIndegree(vector<int> &indegree){
    for(int u=0;u<V;u++){
       list<int> neighbour=l[u];
       for(auto v:neighbour){ //u--->v
            indegree[v]++;
       }
    }
  }

  void topoSort(){   //kahn's algorithm for topological sort
     vector<int> indegree(V);
     calcIndegree(indegree);
      queue<int> q;
     for(int i=0;i<V;i++){
        if(indegree[i]==0){
           q.push(i);
        }
     }

     while(!q.empty()){
      int curr=q.front();
      q.pop();
        cout<<curr<<" ";
        for(auto v:l[curr]){
           indegree[v]--;
           if(indegree[v]==0){  //no pending dependencies
              q.push(v);
           }
        }
     }
     cout<<endl;
  }

};

int main(){
 Graph gp(6,false);

  gp.addedge(5,0);
  gp.addedge(4,0);
  gp.addedge(5,2);
  gp.addedge(4,1);
  gp.addedge(2,3);
  gp.addedge(3,1);
  
  gp.topoSort();
  return 0;
}