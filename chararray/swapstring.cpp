#include <iostream>
using namespace std;
bool is_possible(string str1,string str2){
    int start=0,end=str2.length()-1;
    while(start<=end){
      swap(str2[start],str2[end]);
      if(str1==str2){
        cout<<"can be made"<<endl;
        return true;
      }
      start++;
      end--;
    }
    cout<<"can not be made"<<endl;
    return false;
}

int main(){
 string str1="bank";
 string str2="kanb";
cout<<is_possible(str1,str2)<<endl;;
  return 0;
}