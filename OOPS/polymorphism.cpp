#include <iostream>
using namespace std;

class print{
  public:
   void show(int x){
    cout<<"int :"<<x<<endl;
   }

   void show(string str){
    cout<<"string :"<<str<<endl;
   }
};
int main(){
 print object1;
 object1.show(25);
 object1.show("Ankesh Kushwaha");
  return 0;
}