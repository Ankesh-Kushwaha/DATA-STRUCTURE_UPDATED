#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph {
    int V;
    list<int>* l;
    bool isUndirec;

public:
    Graph(int V, bool isUndirec) {
        this->V = V;
        l = new list<int>[V];
        this->isUndirec = isUndirec;
    }

    void addedge(int u, int v) {
        l[u].push_back(v);
        if (isUndirec) {
            l[v].push_back(u);
        }
    }

    void topoSortHelper(int src, vector<bool> &vis, stack<int> &st) {
        vis[src] = true;
        for (auto v : l[src]) {
            if (!vis[v]) {
                topoSortHelper(v, vis, st);
            }
        }
        st.push(src);
    }

    void toposort() {
        vector<bool> vis(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSortHelper(i, vis, st);
            }
        }

        // Printing stack;
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph gp(6, false); // Directed graph
    gp.addedge(5, 0);
    gp.addedge(4, 0);
    gp.addedge(5, 2);
    gp.addedge(2, 3);
    gp.addedge(3, 1);
    gp.addedge(4, 1);

    gp.toposort();
    return 0;
}
