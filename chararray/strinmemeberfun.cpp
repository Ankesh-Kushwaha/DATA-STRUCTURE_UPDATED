#include <iostream>
#include<string>
using namespace std;
int main(){
 string str="ankesh kushwaha";
 cout<<str.length()<<endl;//for finding the length of the strings;
 cout<<str.at(3)<<endl;//for finding the value at the index;
 cout<<str.substr(4,8)<<endl;//provide substring from the provided starting to the ending posititon;
 cout<<str.find("kesh")<<endl;//search the element in our strings;
 cout<<(int)str.find("coder")<<endl;
 return 0;
}