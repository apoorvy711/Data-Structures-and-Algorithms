#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    void dfs( int node,vector<int>adj[],vector<int>&visited, vector<int>&result){
        visited[node]=1;
        result.push_back(node);

        for(auto &it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,result);
            }
        }
    }

    vector<int> dfsofgraph(int V,vector<int>adj[]){
        int start=1;
        vector<int>result;
        vector<int>visited(V,0);
        dfs(start,adj,visited,result);
        return result;
    }
};

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int>&ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int V=9;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,5);
    addEdge(adj,2,6);
    addEdge(adj,3,4);
    addEdge(adj,3,7);
    addEdge(adj,4,8);
    addEdge(adj,7,8);

    Solution obj;
    vector<int>ans=obj.dfsofgraph(V,adj);
    print(ans);
    return 0;
}

*/
void dfs(int start,vector<int>adj[],vector<int>&visited,vector<int>&res){
    visited[start]=1;
    res.push_back(start);
    for(auto it:adj[start]){
        if(!visited[it]){
            dfs(it,adj,visited,res);
        }
    }
}

vector<int>dfs_ofgraph(int V, vector<int>adj[]){
    vector<int>visited(V,0);
    vector<int>res;
    int start=1;
    dfs(start,adj,visited,res);
    return res;
}

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V=9;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,5);
    addEdge(adj,2,6);
    addEdge(adj,3,4);
    addEdge(adj,4,8);
    addEdge(adj,8,7);
    addEdge(adj,3,7);
    vector<int>ans=dfs_ofgraph(V,adj);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
