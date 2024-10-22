#include <iostream>
using namespace std;

class student{
  public:
  //properties;
   string name;
   float cgpa;

 //methods
 void getPercentage(){
   cout<<(cgpa*10)<<"%"<<endl;
 }

};

class user{
 int id;
 string username;
 string password;
 string bio;

 //methods 
 void deactivate(){
  cout<<"deleting account\n";
 }

 void editBio(string newbio){
  bio=newbio;
 }
};

int main(){
  student s1;//objects;
  s1.name="Ankesh Kushwaha";
  s1.cgpa=9.0;
  
  cout<<s1.name<<endl;
  cout<<s1.cgpa<<endl;
  s1.getPercentage();
  return 0;
}