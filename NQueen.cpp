#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<string>& board) {
    for (auto& row : board)
        cout << row << endl;
    cout << endl;
}

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row-1, j = col-1; i >=0 && j >=0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row-1, j = col+1; i >=0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void solve(vector<string>& board, int row, int n) {
    if (row == n) {
        printBoard(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 5;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n);
    return 0;
}
