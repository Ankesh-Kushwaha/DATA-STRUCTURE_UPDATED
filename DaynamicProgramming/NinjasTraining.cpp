#include <iostream>
#include<vector>
using namespace std;
int requiredMaximumScoreRec(int day,int last,vector<vector<int>> points){
    //base case
    if(day==0){
      int score = 0;
      for (int i = 0; i <= 2;i++){
        if (i != last)
        {
          score = max(score, points[day][last]);
         }
      }
      return score;
    }

    int score = 0;
    for (int i = 0; i <= 2;i++){
      if(i!=last){
        int gain = points[day][i] + requiredMaximumScoreRec(day - 1, i, points);
        score = max(score, gain);
      }
    }
    return score;
}


int requiredMaximumScoreMemo(int day,int last){

}

int main(){
  vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
  int Days = points.size();
  cout << requiredMaximumScoreRec(Days- 1, 3, points);
  return 0;
}