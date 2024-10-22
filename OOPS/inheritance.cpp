#include <iostream>
using namespace std;

class Animal{
public:
   string color;

   void eat(){
    cout<<"eats"<<endl;
   } 

   void breathe(){
    cout<<"breathe"<<endl;
   }


};

class fish : public Animal{   //inheritance; single inheritance
  public:
   int fins;
   void swim(){
    cout<<"swims"<<endl;
   }
  
};

int main(){
 fish f1;
 f1.fins=3;
 cout<<f1.fins<<endl;
 f1.swim();
 f1.breathe();
 f1.color="blue";
 cout<<f1.color<<endl;
  return 0;
}