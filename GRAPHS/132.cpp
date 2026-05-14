#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    int no_provinces(vector<vector<int>>&adj, int V){
        vector<int>adjList[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int>visited(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adjList,visited);
            }
        }
        return cnt;
    }

    void dfs(int node,vector<int>adjList[],vector<int>&visited){
        visited[node]=1;
        for(auto &it:adjList[node]){
            if(!visited[it]){
                dfs(it,adjList,visited);
            }
        }
    }
};
int main(){
    vector<vector<int>> adj={
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    Solution obj;
    int ans=obj.no_provinces(adj,3);
    cout<<"the number of provinces are "<<ans;
    return 0;

}
*/
void dfs(int start,vector<int>adj[],vector<int>&visited){
    visited[start]=1;
    for(auto it:adj[start]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
    }
}
int no_province(int V,vector<int>adj[]){
    vector<int>visited(V+1,0);
    int cnt=0;
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            cnt++;
            dfs(i,adj,visited);
        }
    }
    
    return cnt;
}

void adjEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V=8;
    vector<int>adj[V+1];
    adjEdge(adj,1,2);
    adjEdge(adj,2,3);
    adjEdge(adj,4,5);
    adjEdge(adj,5,6);
    adjEdge(adj,7,8);
    int ans=no_province(V,adj);
    cout<<ans;
    return 0;
}