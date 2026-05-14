#include <bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    int cheapest(int sn,int destination,vector<vector<int>>&grid,int n,int k){
        vector<pair<int,int>>adj[n];
        for(auto &it:grid){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0,{sn,0}});
        dist[sn]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            if(stops >k) continue;
            for(auto it:adj[node]){
                int edNode=it.first;
                int wt=it.second;
                if(dis+wt <dist[edNode] && stops <=k){
                    dist[edNode]=dis+wt;
                    q.push({stops+1,{edNode,dis+wt}});
                }
            }
        }
        if(dist[destination]==1e9) return -1;
        return dist[destination];
    }
};

int main(){
    int sn=0;
    int n=4;
    int k=1;
    int destination =3;
    vector<vector<int>>grid={{0,1,100},{1,3,600},{1,2,100},
                             {2,0,100},{2,3,200}};
    Solution obj;
    int ans=obj.cheapest(sn,destination,grid,n,k);
    cout<<"the ans is "<<ans;
    return 0;                         
}

*/



int cheapest(int sn,int destination,vector<vector<int>>grid,int n, int k){
    vector<pair<int,int>>adj[n];
    for(auto &it:grid){
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>>q;
    vector<int>dist(n,1e9);
    dist[sn]=0;

    //{stops,{sn,dist}}

    q.push({0,{sn,0}});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stops=it.first;
        int node=it.second.first;
        int dis=it.second.second;
        if(stops>k) continue;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int wt=it.second;
            if(dis+wt <dist[adjNode] && stops<=k){
                dist[adjNode]=dis+wt;
                q.push({stops+1,{adjNode,dist[adjNode]}});
            }
        }
    }
    if(dist[destination]==1e9) return -1;
    return dist[destination];
}

int main(){
    int sn=0;
    int n=4;
    int k=1;
    int destination =3;
    vector<vector<int>>grid={{0,1,100},{1,3,600},{1,2,100},
                             {2,0,100},{2,3,200}};

    int ans=cheapest(sn,destination,grid,n,k);
    cout<<"the ans is "<<ans;
    return 0;                         
}
