#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    private:
    void topoSort(int start,vector<pair<int,int>>adj[],vector<int>&visited,stack<int>&st){
        visited[start]=1;
        for(auto &it:adj[start]){
            int v=it.first;
            if(!visited[v]){
                topoSort(v,adj,visited,st);
            }
        }
        st.push(start);
    }
    public:
    vector<int>shortest_path(int sn,int N,int M,vector<vector<int>>&edges){
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            int v=edges[i][0];
            int u=edges[i][1];
            int wt=edges[i][2];
            adj[v].push_back({u,wt});
        }
        stack<int>st;
        vector<int>visited(N,0);
        for(int i=0;i<N;i++){
            if(!visited[i]){
                topoSort(i,adj,visited,st);
            }
        }
        vector<int>dist(N,1e9);
        dist[sn]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(dist[node] !=1e9){
                for(auto &it:adj[node]){
                    int v=it.first;
                    int wt=it.second;
                    if(dist[node]+wt < dist[v]){
                        dist[v]=dist[node]+wt ;
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};

int main(){
    int N=7;
    int M=8;
    vector<vector<int>>edges={{6,4,2},{6,5,3},{4,0,3},{5,4,1},
                              {4,2,1},{0,1,2},{2,3,3},{1,3,1}};
    int sn=6;
    Solution obj; 
    vector<int>ans=obj.shortest_path(sn,N,M,edges);
    cout<<"the shortest distance to every node from source node are ";
    for(auto &it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}


*/
void dfs(int start,vector<pair<int,int>>adj[],vector<int>&visited,stack<int>&st){
    visited[start]=1;
    for(auto &it:adj[start]){
        int v=it.first;
        if(!visited[v]){
            dfs(v,adj,visited,st);
        }
    }
    st.push(start);
}

vector<int>shortest_path(int sn, int N,int M,vector<vector<int>>&edges){
    vector<pair<int,int>>adj[N];
    for(int i=0;i<M;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    vector<int>visited(N,0);
    stack<int>st;
    for(int i=0;i<N;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
    vector<int>dist(N,1e9);
    dist[sn]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dist[node]+wt < dist[v]){
                dist[v]=dist[node]+wt;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(dist[i]==1e9){
            dist[i]==-1;
        }
    }
    return dist;
}
int main(){
    int N=7;
    int M=8;
    vector<vector<int>>edges={{6,4,2},{6,5,3},{4,0,3},{5,4,1},
                              {4,2,1},{0,1,2},{2,3,3},{1,3,1}};
    int sn=6;
    vector<int>ans=shortest_path(sn,N,M,edges);
    cout<<"the shortest distance to every node from source node are ";
    for(auto &it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
