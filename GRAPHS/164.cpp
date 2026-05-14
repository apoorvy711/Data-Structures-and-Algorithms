#include <bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    int no_of_ways(vector<vector<int>>&edges,int sn,int n){
        vector<pair<int,int>>adj[n];

        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        vector<int>ways(n,0);
        dist[sn]=0;
        ways[0]=1;
        pq.push({0,sn});
        int mod=(int)(1e9+7);

        while(!pq.empty()){

            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            int node=it.second;

            for(auto & it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;

                if(dis+wt < dist[adjNode]){
                    dist[adjNode]=dis+wt;
                    pq.push({dis+wt,adjNode});
                    ways[adjNode]=ways[node];
                }

                else if(dis+wt == dist[adjNode]){
                    ways[adjNode]=(ways[adjNode] + ways[node]) ;
                }

            }
        }
        return ways[n-1]; 
    }
};

int main(){
    int n=9;
    vector<vector<int>>edges={{0,1,1},{0,2,2},{0,3,1},{0,4,2},
                              {1,5,2},{2,5,1},{3,5,2},{3,7,3},
                              {3,6,2},{4,6,1},{5,8,1},{7,8,1},
                              {6,8,1}};
    int sn=0;
    Solution obj;
    int ans=obj.no_of_ways(edges,sn,n);
    cout<<ans<<endl;
    return 0;                          
}

*/

int no_of_ways(vector<vector<int>>edges,int sn , int n){
    vector<int>dist(n,1e9);
    vector<int>ways(n,0);
    vector<pair<int,int>>adj[n];
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    dist[sn]=0;
    ways[sn]=1;
    q.push({0,sn});
    while(!q.empty()){
        auto it=q.top();
        q.pop();
        int dis=it.first;
        int node=it.second;
        for(auto &it:adj[node]){
            int adjNode=it.first;
            int edWt=it.second;
            if(dis+edWt < dist[adjNode]){
                dist[adjNode]=dis+edWt;
                q.push({dist[adjNode],adjNode});
                ways[adjNode]=ways[node];
            }
            else if(dis+edWt == dist[adjNode]){
                ways[adjNode]=(ways[adjNode]+ways[node]);
            }
        }
    }
    return ways[n-1];
}
int main(){
    int n=9;
    vector<vector<int>>edges={{0,1,1},{0,2,2},{0,3,1},{0,4,2},
                              {1,5,2},{2,5,1},{3,5,2},{3,7,3},
                              {3,6,2},{4,6,1},{5,8,1},{7,8,1},
                              {6,8,1}};
    int sn=0;
    int ans=no_of_ways(edges,sn,n);
    cout<<ans<<endl;
    return 0;                          
}
