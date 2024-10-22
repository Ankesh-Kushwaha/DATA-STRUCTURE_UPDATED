#include <Iostream>
using namespace std;
int main(){
  //  int n=10;
  //  int *ptr=&n;
  //  cout<<"address of ptr "<<&n<<endl;
  //  cout<<"pointer  value "<<ptr<<endl;
  //  cout<<"address of pointer "<<&ptr<<endl;
  //  cout<<*ptr<<endl;
  //  *ptr=20;
  //  cout<<*ptr<<endl;
  //  int **ptr2=&ptr;
  // cout<<endl;
  // cout<<"value store in ptr2 "<<ptr2<<endl; //gives the value store in it;
  // cout<<"address of ptr1 "<<&ptr<<endl;//give sthe address of ptr
  // cout<<**ptr2<<endl;

  int n=30;
  int *ptr=&n;
  int **ptr2=&ptr;
  int ***ptr3=&ptr2;

  //printing value;
  cout<<n<<endl;
  cout<<*ptr<<endl;
  cout<<**ptr2<<endl;
  cout<<***ptr3<<endl;
  
  cout<<endl;
  //printing adress;
  cout<<ptr<<endl;
  cout<<&n<<endl;
  cout<<endl;
  cout<<ptr2<<endl;
  cout<<&ptr<<endl;
  cout<<endl;
  cout<<ptr3<<endl;
  cout<<&ptr2<<endl;
  cout<<endl;
  cout<<&ptr<<endl;
  cout<<&ptr2<<endl;
  cout<<&ptr3<<endl;
  return 0;
}