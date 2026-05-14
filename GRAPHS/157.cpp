#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    vector<int>Dijkstra(vector<pair<int,int>>adj[],int V,int sn){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,1e9);
        dist[sn]=0;
        pq.push({0,sn});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int edgewt=it.second;
                int adNode=it.first;

                if(dis+edgewt < dist[adNode]){
                    dist[adNode]=dis+edgewt;
                    pq.push({dist[adNode],adNode});
                }
            }
        }
        return dist;
    }
};

void addEdge(vector<pair<int,int>>adj[],int u,int v,int wt){
    adj[u].push_back({ v,wt});
    adj[v].push_back({ u,wt});
}

int main(){
    int V=6;
    int M=8;
    vector<pair<int,int>>adj[V];
    addEdge(adj,0,1,4);
    addEdge(adj,0,2,4);
    addEdge(adj,2,3,3);
    addEdge(adj,2,4,1);
    addEdge(adj,2,5,6);
    addEdge(adj,3,5,6);
    addEdge(adj,5,4,3);
    addEdge(adj,1,2,2);
    
    Solution obj;
    int sn=0;
    vector<int>ans=obj.Dijkstra(adj,V,sn);
    cout<<"the distances from the start node are:"<<endl;
    for(auto &it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
*/
vector<int>Dijkstra(vector<pair<int,int>>adj[],int V, int sn){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(V,1e9);
    dist[sn]=0;
    pq.push({0,sn});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto &it:adj[node]){
            int edgewt=it.second;
            int adjNode=it.first;
            if(dis+edgewt < dist[adjNode]){
                dist[adjNode]=dis+edgewt;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

void addEdge(vector<pair<int,int>>adj[],int u,int v,int wt){
    adj[u].push_back({ v,wt});
    adj[v].push_back({ u,wt});
}

int main(){
    int V=6;
    int M=8;
    vector<pair<int,int>>adj[V];
    addEdge(adj,0,1,4);
    addEdge(adj,0,2,4);
    addEdge(adj,2,3,3);
    addEdge(adj,2,4,1);
    addEdge(adj,2,5,6);
    addEdge(adj,3,5,6);
    addEdge(adj,5,4,3);
    addEdge(adj,1,2,2);
    int sn=0;
    vector<int>ans=Dijkstra(adj,V,sn);
    cout<<"the distances from the start node are:"<<endl;
    for(auto &it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
