#include<iostream>
#include<vector>
using namespace std;
void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>> &vis, int delrw[], int delcl[],int n, int m) {
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int nRow = row + delrw[i];
        int nCol = col + delcl[i];
        if (nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and !vis[nRow][nCol] and board[nRow][nCol] == 'O') {
            dfs(nRow, nCol, board, vis,delrw,delcl,n,m);
        }
   }

}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    int delrw[] = { 0,-1,0,1 };
    int delcl[] = { -1,0,1,0 };
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++) { //first row
        if (!vis[0][i] and board[0][i] == 'O') {
            dfs(0, i, board, vis, delrw, delcl, n, m);
        }
    }
    for (int i = 0; i < m; i++) {
        if (!vis[n - 1][i] and board[n - 1][i] == 'O') {
            dfs(n-1, i, board, vis, delrw, delcl, n, m);
        }
    }// last row
    for (int i = 0; i < n; i++) {
        if (!vis[i][0] and board[i][0] == 'O') {
            dfs(i, 0, board, vis, delrw, delcl, n, m);
        }
    }//first column

    for (int i = 0; i < n; i++) {
        if (!vis[i][m - 1] and board[i][m - 1]=='O') {
            dfs(i, m-1, board, vis, delrw, delcl, n, m);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] != 1 and board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}
int main() {
    vector<vector<char>> board = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'X'}
    };

    solve(board);
    for (auto ch : board) {
        for (auto c : ch) {
            cout << c;
        }
        cout << endl;
    }

}
