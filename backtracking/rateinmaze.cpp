#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solveMazeUntil(int maze[4][4], int row, int col, string ans, int n, vector<vector<bool>> &visited) {
    // base case
    if (row == n - 1 && col == n - 1 && maze[row][col] == 1) {
        cout << ans << endl;
        return;
    }

    // mark the cell as visited
    visited[row][col] = true;

    // moving up
    if (row - 1 >= 0 && !visited[row - 1][col] && maze[row - 1][col] == 1) {
        solveMazeUntil(maze, row - 1, col, ans + "U", n, visited);
    }

    // moving right
    if (col + 1 < n && !visited[row][col + 1] && maze[row][col + 1] == 1) {
        solveMazeUntil(maze, row, col + 1, ans + "R", n, visited);
    }

    // moving left 
    if (col - 1 >= 0 && !visited[row][col - 1] && maze[row][col - 1] == 1) {
        solveMazeUntil(maze, row, col - 1, ans + "L", n, visited);
    }

    // moving down
    if (row + 1 < n && !visited[row + 1][col] && maze[row + 1][col] == 1) {
        solveMazeUntil(maze, row + 1, col, ans + "D", n, visited);
    }

    // unmark the cell (backtrack)
    visited[row][col] = false;
}

void solveMaze(int maze[4][4], int n) {
    string ans = "";
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    if (maze[0][0] == 1) {
        solveMazeUntil(maze, 0, 0, ans, n, visited);
    }
}

int main() {
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    solveMaze(maze, 4);
    return 0;
}
