#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void print(const vector<int>& ans) {
    cout << "ANS ARRAY" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void next_greater(vector<int> arr, vector<int>& ans) {
    stack<int> s;
    int n = arr.size();
    ans.resize(n); // Resize ans to the same size as arr
    
    // Initialize the last element of ans
    ans[n - 1] = -1;
    s.push(arr[n - 1]);
    
    // Process the array from second last element to the first
    for (int idx = n - 2; idx >= 0; idx--) {
        int curr = arr[idx];
        while (!s.empty() && curr >= s.top()) {
            s.pop();
        }
        if (s.empty()) {
            ans[idx] = -1;
        } else {
            ans[idx] = s.top();
        }
        s.push(curr);
    }
    print(ans);
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans;
    next_greater(arr, ans);
    return 0;
}
