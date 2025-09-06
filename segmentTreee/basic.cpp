#include <iostream>
#include <vector>
using namespace std;

class segmentTree
{
  int n;
  vector<int> tree;


  int searchRangeQuery(int qi,int qj,int si,int sj,int node){
      //no overlap
      if(qj<si || qj>sj)
       {return 0;}

      //complete overlap
      if(si>=qi && sj<=qj)
        {return tree[node];}

      //partial overlap
        int mid = si + (sj - si) / 2;
       return searchRangeQuery(qi, qj, si, mid, 2 * node + 1)+
        searchRangeQuery(qi, qj, mid + 1, sj, 2 * node + 2);
  }

public:
  segmentTree(int size, vector<int> arr)
  {
    n = size;
    tree.resize(4 * n, 0);
    buildTree(arr, 0, n - 1, 0); // fix range
  }

  void buildTree(vector<int> &arr, int start, int end, int node)
  {
    if (start == end)
    {                          // base case: leaf node
      tree[node] = arr[start]; // fix: use arr[start]
      return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, start, mid, 2 * node + 1);
    buildTree(arr, mid + 1, end, 2 * node + 2);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }

  void printTree()
  {
    for (int i = 0; i < 4 * n; i++)
    {
      cout << tree[i] << " ";
    }
    cout << endl;
  }


  int rangeQuery(int qi,int qj){
    return searchRangeQuery(qi, qj, 0, n - 1, 0);
  }

};

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
  segmentTree st(10, arr);
  st.printTree();
  cout << st.rangeQuery(2, 5) << endl;
  return 0;
}
