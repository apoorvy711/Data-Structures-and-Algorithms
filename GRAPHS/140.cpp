#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int count_land(vector<vector<int>>&land){
        int n=land.size();
        int m=land[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        int i=0;
        int j=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(land[i][j]==1){
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }

            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for( int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int mcol=c+delcol[i];
                if(nrow>=0 && nrow<n && mcol>=0 && mcol<m && visited[nrow][mcol]==0 && land[nrow][mcol]==1){
                    visited[nrow][mcol]=1;
                    q.push({nrow,mcol});     
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && visited[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main(){
    vector<vector<int>>land={{0,0,0,1},
                             {0,1,1,0},
                             {0,1,1,0},
                             {0,0,0,1},
                             {0,1,1,0},};
    Solution obj;
    int ans=obj.count_land(land);
    cout<<"the number of enclave lands is "<<ans;
    return 0;                         
}