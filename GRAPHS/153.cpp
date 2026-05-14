#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    vector<int>shortest_dist(int N,int M,vector<vector<int>>&edges,int sn){
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<int>dist(N,1e9);
        dist[sn]=0;
        q.push(sn);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &it:adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it]=1+dist[node];
                    q.push(it);
                }
            }
        }

        vector<int>ans(N,-1);
        for(int i=0;i<N;i++){
            if(dist[i] != 1e9){
                ans[i]=dist[i];
            }
        }
        return ans;
    }
};


int main(){
    int N=9;
    int M=11;
    vector<vector<int>> edges={{0,1},{0,3},{1,2},{1,3},{3,4},{4,5},{5,6},{6,8},{8,7},{6,7},{2,6}};
    int sn=0;
    Solution obj;
    vector<int>ans=obj.shortest_dist(N,M,edges,sn);
    cout<<"the shortest distance from the source node is ";
    for(auto &it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;

}

*/

vector<int>shortest_dist(int N,int M,vector<vector<int>> &edges,int sn){
    vector<int>visited(N,0);
    queue<int>q;
    vector<int>adj[N];
    vector<int>dist(N,1e9);
    for(auto &it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    dist[sn]=0;
    q.push(sn);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto &it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it]=dist[node]+1;
                q.push(it);
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

int main(){
    int N=9;
    int M=11;
    vector<vector<int>> edges={{0,1},{0,3},{1,2},{1,3},{3,4},{4,5},{5,6},{6,8},{8,7},{6,7},{2,6}};
    int sn=0;
    vector<int>ans=shortest_dist(N,M,edges,sn);
    cout<<"the shortest distance from the source node is ";
    for(auto &it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;

}