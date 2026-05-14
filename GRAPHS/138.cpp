#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    vector<vector<int>>dist_one( vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[r][c]=steps;
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int mcol=c+delcol[i];
                if(nrow>=0 && nrow<n && mcol>=0 && mcol<m && visited[nrow][mcol]==0){
                    visited[nrow][mcol]=1;
                    q.push({{nrow,mcol},steps+1});
                }
            }
        }
        return dist;
    }
};

int main(){
    vector<vector<int>>grid={{0,0,0},{0,1,0},{1,0,1}};
    Solution obj;
    vector<vector<int>>ans=obj.dist_one(grid);
    for(auto &it:ans){
        for(auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/
vector<vector<int>>dist_one(vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>visited(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        dist[r][c]=steps;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int mrow=c+delcol[i];
            if(nrow>=0 && nrow<n && mrow>=0 && mrow<m && visited[nrow][mrow]==0){
                visited[nrow][mrow]=1;
                q.push({{nrow,mrow},steps+1});
            }
        }
    }
    return dist;
}
int main(){
    vector<vector<int>>grid={{0,0,0},{0,1,0},{1,0,1}};
 
    vector<vector<int>>ans=dist_one(grid);
    for(auto &it:ans){
        for(auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}