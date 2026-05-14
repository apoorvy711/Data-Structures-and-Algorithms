#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool dfs(int start,vector<int>adj[],vector<int>&visited,vector<int>&pathVisited){
        visited[start]=1;
        pathVisited[start]=1;
        for(auto & it:adj[start]){
            if(!visited[it]){
                if(dfs(it,adj,visited,pathVisited)==true){
                    return true;
                }
            }
            else if(pathVisited[it]){
                return true;
            }
        }
        pathVisited[start]=0;
        return false;
    }

    bool detect_cycle(int V,vector<int>adj[]){
        vector<int>visited(V,0);
        vector<int>pathVisited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,pathVisited)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

int main(){
    int V=11;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,3,7);
    addEdge(adj,8,9);
    addEdge(adj,9,10);
    addEdge(adj,10,8);
    addEdge(adj,8,2);
    addEdge(adj,7,5);
    Solution obj;
    bool ans=obj.detect_cycle(V,adj);
    if(ans){
        cout<<"the cycle is present ";
    }
    else{
        cout<<"the cycle is absent "; 
    }
    return 0;
}