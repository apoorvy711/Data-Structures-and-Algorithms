#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    vector<int>shortest_path(int sn,int n,int m,vector<vector<int>>&edges){
        vector<pair<int,int>>adj[n+1];
        for(auto &it:edges){
            adj[it[1]].push_back({it[0],it[2]});
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<int>dist(n+1,1e9);
        dist[sn]=0;
        pq.push({0,sn});
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int dis=it.first;
            pq.pop();
            for(auto &it:adj[node]){
                int edgeNode=it.first;
                int wt=it.second;
                if(wt+dis <dist[edgeNode]){
                    dist[edgeNode]=wt+dis;
                    pq.push({dist[edgeNode],edgeNode});
                    parent[edgeNode]=node;
                }
            }
        }  
        vector<int>path;
        int node=n;
        while(parent[node] !=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(sn);
        reverse(path.begin(),path.end());
        return path;
    }
};

int main(){
    int n=5;
    int m=6;
    vector<vector<int>>edges={{1,2,2},{1,4,1},{2,5,5},
                              {2,3,4},{3,4,3},{3,5,1},
                              {3,2,4},{4,1,1},{4,3,3},
                              { 5,2,5},{5,3,1},{2,1,2}};
    Solution obj;
    int sn=1;
    vector<int>result=obj.shortest_path(sn,n,m,edges);
    cout<<"the path is :";
    for(auto &it:result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

*/

vector<int>shortest_path(int sn,int n, int m,vector<vector<int>>&edges){
    vector<pair<int,int>>adj[n+1];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>parent(n+1);
    for(auto &it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int>dist(n+1,1e9);
    dist[sn]=0;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    pq.push({0,sn});
    while(!pq.empty()){
        auto it=pq.top();
        int dis=it.first;
        int node=it.second;
        pq.pop();
        for(auto &it:adj[node]){
            int edgenode=it.first;
            int wt=it.second;
            if(dis+wt<dist[edgenode]){
                dist[edgenode]=dis+wt;
                pq.push({dist[edgenode],edgenode});
                parent[edgenode]=node;
            }
        }
    }
    vector<int>path;
    int node=n;
    while(parent[node] !=node){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(sn);
    reverse(path.begin(),path.end());
    if(dist[n]==1e9) return {-1};
    return path;
}

int main(){
    int n=5;
    int m=6;
    vector<vector<int>>edges={{1,2,2},{1,4,1},{2,5,5},
                              {2,3,4},{3,4,3},{3,5,1},
                              {3,2,4},{4,1,1},{4,3,3},
                              { 5,2,5},{5,3,1},{2,1,2}};

    int sn=1;
    vector<int>result=shortest_path(sn,n,m,edges);
    cout<<"the path is :";
    for(auto &it:result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

