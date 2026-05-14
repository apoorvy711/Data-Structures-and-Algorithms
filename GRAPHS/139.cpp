#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void dfs(int row,int col, vector<vector<int>>&visited, vector<vector<char>>&mat,int delrow[],int delcol[]){
        visited[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int mcol=col+delcol[i];
            if(nrow>=0 && nrow<n && mcol>=0 && mcol<m && !visited[nrow][mcol] && mat[nrow][mcol]=='0'){
                dfs(nrow,mcol,visited,mat,delrow,delcol);
            }
        }
    }

    vector<vector<char>>surround( vector<vector<char>>&mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        //1st row
        for(int j=0;j<m;j++){
            if(!visited[0][j] && mat[0][j]=='0'){
                dfs(0,j,visited,mat,delrow,delcol);
            }
        }
        //Last row
        for(int j=0;j<m;j++){
            if(!visited[n-1][j] && mat[n-1][j]=='0'){
                dfs(n-1,j,visited,mat,delrow,delcol);
            }
        }
        //1st column
        for(int j=0;j<n;j++){
            if(!visited[j][0] && mat[j][0]=='0'){
                dfs(j,0,visited,mat,delrow,delcol);
            }
        }
        //Last column
        for(int j=0;j<n;j++){
            if(!visited[j][m-1] && mat[j][m-1]=='0'){
                dfs(j,m-1,visited,mat,delrow,delcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mat[i][j]=='0'){
                    mat[i][j]='X';
                }
            }
        }

        return mat;
    }

};

int main(){
    vector<vector<char>>mat={{'X','X','X','X','X'},
                            {'X','0','0','X','0'}, 
                            {'X','X','0','X','0'},
                            {'X','0','X','0','X'},
                            {'0','0','X','X','X'}};

    Solution obj;
    vector<vector<char>>ans=obj.surround(mat);
    cout<<"the new matrix is "<<endl;
    for(auto &it:ans){
        for(auto &j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }              
    return 0;          
}
