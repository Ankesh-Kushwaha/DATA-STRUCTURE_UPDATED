#include <iostream>
using namespace std;

class Animal{
 public:
   void eat(){
    cout<<"can eat"<<endl;
   }

   void breathe(){
    cout<<"can breathe"<<endl;
   }
};

class bird :public Animal{
  public:
   void fly(){
    cout<<"can fly"<<endl;
   }
};

class fish:public Animal{
  public:
   void swim(){
    cout<<"can swim"<<endl;
   }
};

class mammal:public Animal{
  public:
   void walk(){
    cout<<"can walk"<<endl;
   }
};
int main(){
  mammal m1;
  m1.breathe();
  
  return 0;
}