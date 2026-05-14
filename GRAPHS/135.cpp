#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    int rotten_oranges(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
            }
        }

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int tm=0;
        while(!q.empty()){

        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        q.pop();
        tm=max(tm,t);
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int mcol=c+delcol[i];

            if(nrow>=0 && nrow<n && mcol>=0 && mcol<m && visited[nrow][mcol] !=2 && grid[nrow][mcol]==1){
                q.push({{nrow,mcol},t+1});
                visited[nrow][mcol]=2;
            }
        }

       
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && visited[i][j] !=2){
                return -1;
            }
        }
    }
    return tm;
    }
};

int main(){
    vector<vector<int>>grid={
        {2,1,1},
        {1,1,0},
        {0,1,1},
    };

    Solution obj;
    int result=obj.rotten_oranges(grid);
    cout<<"the time taken to rot all fresh oranges "<<result;
    return 0;
}
*/
int rotten_orange_time(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=2;
            }
        }
    }
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    int tm=0;
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        q.pop();
        tm=max(t,tm);
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int mcol=c+delcol[i];
            if((nrow>=0 && nrow<n) &&(mcol >=0 && mcol<m)&&
        (matrix[nrow][mcol]==1) && (visited[nrow][mcol]!=2)){
            q.push({{nrow,mcol},tm+1});
            visited[nrow][mcol]=2;
        }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1 && visited[i][j]!=2){
                return -1;
            }
        }
    }
    return tm;
}

int main(){
    vector<vector<int>>matrix={
        {2,1,1},
        {1,1,0},
        {0,1,1},
    };
    int ans=rotten_orange_time(matrix);
    cout<<ans;
    return 0;
}
