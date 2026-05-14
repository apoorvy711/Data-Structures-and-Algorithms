void  N_QUEENS2(int col,vector<string> &board,vector<vector<string>> &ans,  vector<int>&leftrow,vector<int>&upperDiagnol,vector<int>&lowerDiagnol,int N){
    if(col==N){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<N;row++){
        if(leftrow[row]==0 && lowerDiagnol[row+col]==0 && upperDiagnol[N-1+col-row]==0){
            board[row][col]='Q';
            leftrow[row]=1;
            upperDiagnol[row+col]=1;
            lowerDiagnol[N-1+col-row]=1;
            N_QUEENS2(col+1,board,ans,leftrow,upperDiagnol,lowerDiagnol,N);
            board[row][col]='.';
            leftrow[row]=0;
            upperDiagnol[row+col]=0;
            lowerDiagnol[N-1+col-row]=0;
        }
    }
}

int main(){
    int N=4;
    vector<vector<string>> ans;
    vector<string> board(N,string(N,'.'));
    vector<int>leftrow(N,0),upperDiagnol(2*N-1,0),lowerDiagnol(2*N-1,0);
    N_QUEENS2(0,board,ans,leftrow,upperDiagnol,lowerDiagnol,N);
    for(int i=0;i<ans.size();i++){
        cout<<"Arrangement "<<i+1<<" is "<<endl;
        for(int j=0;j<N;j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
