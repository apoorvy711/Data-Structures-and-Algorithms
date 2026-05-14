#include <bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    pair<int,vector<vector<int>>>prism(int n,vector<vector<int>>adj[]){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>visited(n,0);
        vector<int>parent(n,-1);
        vector<vector<int>>mstedges;
        int sum=0;
        pq.push({0,0});  //wt,node
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            if(visited[node]) continue;
            visited[node]=1;
            sum+=wt;
            if(parent[node] !=-1){
                mstedges.push_back({parent[node],node,wt});
            }
            for(auto &it:adj[node]){
                int adjNode=it[0];
                int edWt=it[1];

                if(!visited[adjNode]){
                    pq.push({edWt,adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        return {sum,mstedges};
    }
};

int main(){
    int n=5;
    vector<vector<int>>edges={{0,1,2},{0,2,1},{1,2,1},{2,4,2},{2,3,2},{3,4,1}};
    vector<vector<int>>adj[n];
    for(auto &it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    Solution obj;
    auto result=obj.prism(n,adj);
    int sum=result.first;
    vector<vector<int>>mstedges=result.second;
    cout<<"the sum of the mst weights is "<<sum<<endl;
    cout<<"the mst is "<<endl;
    for(auto &it:mstedges){
        cout<<it[0]<<"-"<<it[1]<<" "<<"with weight"<<"="<<it[2]<<endl;
    }
    cout<<endl;
    return 0;
}


*/

pair<int,vector<vector<int>>>prism(int n,vector<vector<int>>adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>parent(n,-1);
    vector<int>visited(n,0);
    pq.push({0,0});
    int sum=0;
    vector<vector<int>>mstedges;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(visited[node]) continue;
        visited[node]=1;
        sum+=wt;
        if(parent[node] !=-1){
            mstedges.push_back({parent[node],node,wt});
        }
        for(auto &it:adj[node]){
            int edgNode=it[0];
            int edgwt=it[1];
            if(!visited[edgNode]){
                pq.push({edgwt,edgNode});
                parent[edgNode]=node;
            }
        }
    }
    return {sum,mstedges};
}

int main(){
    int n=5;
    vector<vector<int>>edges={{0,1,2},{0,2,1},{1,2,1},{2,4,2},{2,3,2},{3,4,1}};
    vector<vector<int>>adj[n];
    for(auto &it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    auto result=prism(n,adj);
    int sum=result.first;
    vector<vector<int>>mstedges=result.second;
    cout<<"the sum of the mst weights is "<<sum<<endl;
    cout<<"the mst is "<<endl;
    for(auto &it:mstedges){
        cout<<it[0]<<"-"<<it[1]<<" "<<"with weight"<<"="<<it[2]<<endl;
    }
    cout<<endl;
    return 0;
}
