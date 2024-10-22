#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<char>> &board, int row, int col) {
    int n = board.size();

    // Check the column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

bool nQueens(vector<vector<char>> &board, int row) {
    int n = board.size();
    // Base case
    if (row == n) {
        printBoard(board);
        return true; // Found a solution
    }

    for (int j = 0; j < n; ++j) { // col
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';
            if (nQueens(board, row + 1)) {
                return true; // Solution found, no need to backtrack further
            }
            board[row][j] = '.'; // Backtrack
        }
    }
    return false; // No solution found in this path
}

int main() {
    int n = 2; // Adjust n as needed
    vector<vector<char>> board(n, vector<char>(n, '.'));
    if (!nQueens(board, 0)) {
        cout << "No solution exists for n = " << n << endl;
    }
    return 0;
}
