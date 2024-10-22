#include <iostream>
using namespace std;
void func(){
   int n;
  cout<<"enter the size of array:"<<endl;
  cin>>n;
  int *ptr=new int[n];
  int *start=ptr; //save starting address
  for(int i=0;i<n;i++){
     cin>>ptr[i];
  }

  for(int i=0;i<n;i++){
    cout<<start[i]<<" ";
    //ptr=ptr+1;
  }

  delete(ptr); //free the memory;
}

int main(){
 func();
  return 0;
}