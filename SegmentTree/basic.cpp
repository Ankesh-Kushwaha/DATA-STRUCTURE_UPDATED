#include <iostream>
#include <vector>
using namespace std;

class segmentTree {
    vector<int> nodes;

public:
    segmentTree(int n) {
        nodes.resize(4 * n);
    }

    void BuildTreeHelper(vector<int> nums, int node, int left, int right) {
            //base case 
            if(left==right){
              nodes[node] = nums[right]; // it can be left because left==right;
              return;// the recursion should be stop here
            }

            int mid = left + (right - left) / 2;
            BuildTreeHelper(nums, 2 * node + 1, left, mid);
            BuildTreeHelper(nums, 2 * node + 2, mid + 1, right);

            nodes[node] = nodes[2 * node + 1] + nodes[2 * node + 2];
    }

    void buildTree(const vector<int>  nums) {
      int node = 0;
      int left = 0;
      int right = nums.size() - 1;
      BuildTreeHelper(nums,node, left, right);
    }

    void updateQueryHelper(vector<int> &nums,int val,int valueIdx,int node,int left,int right){
      //base case
      if (left==right){
        nodes[node] = val; //put the required val at it specified position
        return;
      }

      int mid = left + (right - left) / 2;
      if(valueIdx<=mid){
        updateQueryHelper(nums, val, valueIdx, 2*node+1, left, mid);
      }
      else{
        updateQueryHelper(nums, val, valueIdx, 2*node+2, mid + 1, right);
      }

      nodes[node] = nodes[2 * node + 1] + nodes[2 * node + 2];
    }

    void updateQuery(vector<int> &nums,int val,int valueIdx){
      updateQueryHelper(nums, val, valueIdx,0, 0, nums.size() - 1);
    }

   int rangeQuerySumHelper(vector<int> &nums,int startIdx,int endIdx,int node,int left,int right){
         if(endIdx<left || startIdx> right){ //no overlapping
           return 0;
         }


         if(startIdx<=left && right<=endIdx){ //full overlapping
           return nodes[node];
         }
         else{ //partial overlap
           int mid = left + (right - left) / 2;
           return rangeQuerySumHelper(nums, startIdx, endIdx, 2 * node + 1, left, mid) +
                  rangeQuerySumHelper(nums, startIdx, endIdx, 2 * node + 2, mid + 1, right);
         }
   }

    int rangeQuerySum(vector<int> & nums,int startIdx,int endIdx){
      return rangeQuerySumHelper(nums, startIdx, endIdx, 0, 0, nums.size() - 1);
    }

    void printTree(){
      for (int i = 0; i < nodes.size();i++){
        cout << nodes[i] << " ";
      }
      cout << endl;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    segmentTree st(nums.size());
    st.buildTree(nums);
    cout << "before updation:" << endl;
    st.printTree();
    st.updateQuery(nums, 6, 0);
    cout << "after updation :" << endl;
    st.printTree();
    cout << "query search:" << st.rangeQuerySum(nums, 0, 8) << endl;
    ;

    return 0;
}
