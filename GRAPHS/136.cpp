#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    bool detect_cycle(int V,vector<int>adj[]){
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }

    bool bfs(int start,vector<int>adj[],vector<int>&visited){
        visited[start]=1;
        queue<pair<int,int>>q;
        q.push({start,-1});

        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto &neighbour:adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push({neighbour,node});
                }
                else if(neighbour !=parent){
                    return true;
                }
            }
        }
        return false;
    }
};

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V=8;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,5);
    addEdge(adj,3,4);
    addEdge(adj,3,6);
    addEdge(adj,5,7);
    addEdge(adj,6,7);

    Solution obj;
    bool ans=obj.detect_cycle(V,adj);
    if(ans){
        cout<<"the cycle is present";
    }
    else{
        cout<<"the cycle is absent";
    }
}

*/
bool bfs(int start,vector<int>adj[],vector<int>&visited ){
    queue<pair<int,int>>q;
    q.push({start,-1});
    visited[start] = 1;
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto &neighbour:adj[node]){
            if(!visited[neighbour]){
                visited[neighbour]=1;
                q.push({neighbour,node});
            }
            else if(neighbour !=parent){
                return true;
            }
        }
    }
    return false;
}

bool detect_cycle(int V,vector<int>adj[] ){
    vector<int>visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(bfs(i,adj,visited)){
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V=8;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,5);
    addEdge(adj,3,4);
    addEdge(adj,3,6);
    addEdge(adj,5,7);
    addEdge(adj,6,7);
    bool ans=detect_cycle(V,adj);
    if(ans){
        cout<<"the cycle is present";
    }
    else{
        cout<<"the cycle is absent";
    }
}

