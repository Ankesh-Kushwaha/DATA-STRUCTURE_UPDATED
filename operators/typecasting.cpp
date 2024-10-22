#include <iostream>
using namespace std;
int main(){
  cout<<(10/3)<<endl;//3 
  cout<<(10/3.0)<<endl; //3.33333
  // Type conversion   bool->char -> int ->float->double
   cout<<('A'+1)<<endl;
   cout<<('A'+2)<<endl;//implicit conversion
   //explicit conversion
   cout<<((float)10/3);
   cout<<((bool)3+2)<<endl;
   cout<<(23.5+2+'A')<<endl;
  return 0;
}