#include <iostream>
using namespace std;
class teacher{
  public:
  int salary;
  string subject;
};

class student{
  public:
  int roll_no;
  float cgpa;
};

class TA:public teacher,public student{
  public:
     string name;
};

int main(){
   TA ta1;
   ta1.name="Ankesh Kushwaha";
   ta1.cgpa=9.8;
   ta1.roll_no=25467;
   ta1.salary=100000;
   ta1.subject="computer Networks";
   cout<<ta1.name<<endl;
   cout<<ta1.roll_no<<endl;
   cout<<ta1.cgpa<<endl;
   cout<<ta1.salary<<endl;
   cout<<ta1.subject<<endl;

  return 0;
}