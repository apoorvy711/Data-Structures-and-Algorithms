#include<bits\stdc++.h>
using namespace std;

//BRUTE
bool safe_to_put(int row,int col, vector<string> board,int N){
    int dup_row=row;
    int dup_col=col;

    while( row>=0 && col>=0 ){
        if(board[row][col]=='Q') return false;
        row--,col--;
    }

    row=dup_row, col=dup_col;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
    row=dup_row, col=dup_col;
    while(row<N && col>=0){
        if(board[row][col]=='Q') return false;
        row++,col--;
    }
    return true;
}

void N_QUEENS1(int col,  vector<string> &board,vector<vector<string>> &ans,int N){
    if(col==N){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<N;row++){
        if(safe_to_put(row,col,board,N)){
            board[row][col]='Q';
            N_QUEENS1(col+1,board,ans,N);
            board[row][col]='.';
        }
    }
}

//OPTIMAL

void N_QUEENS2(int col, vector<string> &board, vector<vector<string>> &ans,vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int N) {
    if (col == N) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < N; row++) {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[N - 1 + col - row] == 0) {
            // Place the queen
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[N - 1 + col - row] = 1;

            // Recurse to next column
            N_QUEENS2(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, N);

            // Backtrack: Remove the queen
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[N - 1 + col - row] = 0;
        }
    }
}

int main() {
    int N = 4;
    vector<vector<string>> ans;
    vector<string> board(N, string(N, '.'));
    vector<int> leftRow(N, 0), upperDiagonal(2 * N - 1, 0), lowerDiagonal(2 * N - 1, 0);

    N_QUEENS2(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, N);

    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << " is:" << endl;
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
