#include <iostream>
#include<vector>
using namespace std;

int maxActitvity(vector<int> start ,vector<int> end){
    //sort end time
    cout<<"selecting activity : A0"<<endl;
    int count=1;
    int endingTime=end[0];

    for(int i=1;i<=start.size()-1;i++){
         if(start[i]>=endingTime){ //condtion for non -overlapping
          cout<<"selecting activity : A"<<i<<endl;
          count++;
          endingTime=end[i];
         }
    }
    return count;
}
int main(){
 vector<int>start={1,3,0,5,8,5};
 vector<int>end={2,4,6,7,9,9};//4
  cout<<maxActitvity(start,end)<<endl;
  return 0;
}