#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    void bfs(int row,int col,vector<vector<char>>&grid, vector<vector<int>>&visited){
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int drow=-1;drow<=1;drow++){
                for(int dcol=-1;dcol<=1;dcol++){
                    int nrow=r +drow;
                    int mcol=c+dcol;
                    if((nrow>=0 && nrow<n) && (mcol>=0 && mcol<m) && (grid[nrow][mcol]=='1' && !visited[nrow][mcol])){
                        visited[nrow][mcol]=1;
                        q.push({nrow,mcol});
                    } 
                }
            }
        }
    }
    int no_lands(vector<vector<char>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col] =='1' && !visited[row][col]){
                    cnt++;
                    bfs(row,col,grid,visited);
                }
            }
        }
        return cnt;
    }
};
int main(){
    vector<vector<char>>grid={
        {'0','1','1','0'},
        {'0','1','1','0'},
        {'0','0','1','0'},
        {'0','0','0','0'},
        {'1','1','0','1'},
    };
    Solution obj;
    int ans=obj.no_lands(grid);
    cout<<"the number of lands are "<<ans;
    return 0;
}
*/
void bfs(int row, int col,vector<vector<int>>&grid,vector<vector<int>>&visited){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>>q;
    visited[row][col]=1;
    q.push({row,col});
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int drow=-1;drow<=1;drow++){
            for(int dcol=-1;dcol<=1;dcol++){
                int nrow=r+drow;
                int mcol=c+dcol;
                if((nrow>=0 && nrow<n) && (mcol>=0 && mcol<m) && (grid[nrow][mcol]==1) && (!visited[nrow][mcol])){
                    visited[nrow][mcol]=1;
                    q.push({nrow,mcol});
                }
            }
        }
    }
}
int no_oflands(vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                cnt++;
                bfs(i,j,grid,visited);
            }
        }
    }
    return cnt;
}
int main(){
    vector<vector<int>>grid={
        {0,1,1,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,0},
        {1,1,0,1},
    };
    int ans=no_oflands(grid);
    cout<<ans;
    return 0;
}





























