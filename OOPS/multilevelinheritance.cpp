#include <iostream>
using namespace std;
class Animal{
  public:
  void eat(){
    cout<<"eat"<<endl;
  }

   void breathe(){
    cout<<"breathe"<<endl;
   }

};

class mammal:public Animal{
  public:
  string bloodType;
    mammal(){
      bloodType="warm";
    }
};

class Dog:public mammal{
 public:
  void tailWag(){
    cout<<"a dog wails its tail"<<endl;
  }
};

int main(){
   Dog d1;
   d1.bloodType="AB+";
   cout<<d1.bloodType<<endl;
   d1.breathe();
   d1.eat();
   d1.tailWag();
  return 0;
}