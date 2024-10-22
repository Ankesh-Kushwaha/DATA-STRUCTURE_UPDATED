#include <iostream>
using namespace std;
int main(){
  int *ptr;
  cout<<*ptr<<endl;
  int *ptr2=NULL;
  cout<<*ptr2<<endl;
  cout<<&ptr2<<endl;
  return 0;
}