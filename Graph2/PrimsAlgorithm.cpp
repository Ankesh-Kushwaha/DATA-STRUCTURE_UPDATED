#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class edge {
public:
    int v;
    int wt;
    edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

int primsAlgo(vector<vector<edge>> graph, int V, int src) {
    vector<bool> MSTset(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (wt, v)
    
    int totalCost = 0;
    pq.push(make_pair(0, src)); // Start from the source vertex with 0 cost
    
    while (!pq.empty()) {
        int currWt = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        // If the vertex is already in the MST, skip it
        if (MSTset[u]) continue;

        // Mark the current vertex as part of the MST
        MSTset[u] = true;
        
        // Add the cost of the edge to the total cost
        totalCost += currWt;
        
        // Explore all neighbors of the current vertex
        for (edge e : graph[u]) {
            if (!MSTset[e.v]) {
                pq.push(make_pair(e.wt, e.v));
            }
        }
    }
    return totalCost;
}

int main() {
    int V = 4;
    vector<vector<edge>> graph(V);
    
    graph[0].push_back(edge(1, 10));
    graph[0].push_back(edge(2, 15));
    graph[0].push_back(edge(3, 30));

    graph[1].push_back(edge(0, 10));
    graph[1].push_back(edge(3, 40));

    graph[2].push_back(edge(0, 15));
    graph[2].push_back(edge(3, 50));

    graph[3].push_back(edge(0, 30));
    graph[3].push_back(edge(1, 40));
    graph[3].push_back(edge(2, 50));

    int ans = primsAlgo(graph, V, 0);
    cout << "Cost of MST: " << ans << endl;

    return 0;
}
