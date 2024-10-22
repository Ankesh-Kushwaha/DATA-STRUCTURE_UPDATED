#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class row {
public:
    int count;
    int idx;

    row(int count, int idx) {
        this->count = count;
        this->idx = idx;
    }

    bool operator <(const row& obj) const {
        if (this->count == obj.count) {
            return this->idx > obj.idx;
        }
        return this->count > obj.count;
    }
};

void weakestSoldier(vector<vector<int>> matrix, int k) {
    vector<row> Rows;
    for (int i = 0; i < matrix.size(); i++) {
        int count = 0; // Reset count for each row
        for (int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++) {
            count++;
        }
        Rows.push_back(row(count, i));
    }

    priority_queue<row> pq(Rows.begin(), Rows.end());
    for (int i = 0; i < k; i++) {
        cout << "Row :" << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };

    weakestSoldier(matrix, 2);
    return 0;
}
