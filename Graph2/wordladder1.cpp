#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;

int shortestTransformation(string &beginWord,string &endWord,vector<string> &wordList){
  // bfs algo to count shortest transformation
  unordered_set<string> st(wordList.begin(), wordList.end());
  queue<pair<string, int>> q;
  q.push({beginWord, 1});
  st.erase(beginWord);

  while (!q.empty())
  {
    string word = q.front().first;
   // cout << word << " ";
    int steps = q.front().second;
    q.pop();

    if (word == endWord)
    {
      return steps;
    }

    for (auto &ch : word)
    {
      char original = ch;
      for (char i = 'a'; i <= 'z'; i++)
      {
        ch = i;
        if (st.find(word) != st.end())
        {
          q.push({word, steps + 1});
          cout << word << " ";
          st.erase(word);
        }
      }
      ch = original;
    }
  }
  return 0;
}

int main(){
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

  cout << shortestTransformation(beginWord, endWord, wordList) << endl;

  return 0;
}