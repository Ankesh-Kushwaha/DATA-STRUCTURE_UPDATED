#include <iostream>
#include <string>
using namespace std;
class student{
  string name;
  float cgpa;
  string address;

  public:
  //setters;
  void setname(string namevalue){
       name=namevalue;
  }

  void setcgpa(float cgpavalue){
    cgpa=cgpavalue;
  }

  void setaddress(string addressvalue){
     address=addressvalue;
  }

  //getters
  string getname(){
    return name;
  }

  float getcgpa(){
    return cgpa;
  }

  string getaddress(){
    return address;
  }

};

int main(){
 student s1;
 //setting value to object
 s1.setname("Ankesh Kushwaha");
 s1.setcgpa(9.5);
 s1.setaddress("Bharhe Chaura");

 //accesssing value;
 cout<<s1.getname()<<endl;
 cout<<s1.getcgpa()<<endl;
 cout<<s1.getaddress()<<endl;
  return 0;
}