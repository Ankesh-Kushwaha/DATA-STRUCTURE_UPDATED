#include <iostream>
using namespace std;

// class example {
// public:
//     static int x; // Declaration of static member variable
// };

// int example::x = 0; // Initialization of static member variable
 
 class example{
  public:
     example(){
      cout<<"constructer"<<endl;
     }

     ~example(){
      cout<<"destructor"<<endl;
     }
 };


int main() {
  int a=0;
  if(a==0){
    static example eg1;
  }

  cout<<"code ending"<<endl;
   

    // cout << eg1.x++ << endl;
    // cout << eg2.x++ << endl;
    // cout << eg3.x++ << endl;

    return 0;
}
