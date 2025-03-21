#include<iostream>
#include<vector>
using namespace std;

class disjoint{
  public:  
  int n;
  vector<int> par;
  vector<int> rank;
  
  //if the parent of two nodes are same then it is confirm that they belong to the same set
  //if the parent of two nodes are different than they confirmly belong to the different set
  disjoint(int n){
    this->n=n;
    for(int i=0;i<n;i++){
      par.push_back(i); //assingn each node as parent of itself
      rank.push_back(0); //assign rank of each node as 0 initially
    }
  }
   
  //find fuction recursively find the parent of the each node
  int find(int x){
    if(par[x]==x){
      return x;
    }
    //we use path compression to simple make the graph less skewed
    return par[x]=find(par[x]);  //path compresion;
  }

  void unionByRank(int a,int b){
      int parA=find(a); //find parent a
      int parB=find(b); //find parent of b

      if(rank[parA]==rank[parB]){   //if rank of both parent is same then increase the rank of parentA
           par[parB]=parA; //make parent of b as parent of a
           rank[parA]++; //since a is parent of b than we have to increase the rank of a
      }
        //if rank of a is greater than rank of b than make parent of b as paren of a
      else if(rank[parA]>rank[parB]){
           par[parB]=parA;
      }
      else{//if rank of b is greater than the rank of a than make b as a parent of a 
        par[parA]=parB;
      }
  }

  void print(){
    for(int i=0;i<n;i++){
      cout<<"par:"<<par[i]<<" "<<"rank:"<<rank[i]<<endl;
    }
  }
};



int main(){
   disjoint dj(6);
   dj.unionByRank(0,2);
   cout<<dj.find(2)<<endl;
   dj.unionByRank(1,3);
   dj.unionByRank(2,5);
   dj.unionByRank(0,3);
   cout<<dj.find(2)<<endl;
   dj.unionByRank(0,4);
   dj.print();

  return 0;
}