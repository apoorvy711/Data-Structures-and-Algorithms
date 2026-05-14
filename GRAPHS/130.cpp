#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    vector<int>bfsofgraph(int V,vector<int>adj[],int start){
        vector<int>visited(V,0);
        visited[start]=1;
        queue<int>q;
        q.push(start);
        vector<int>res;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);

            for(auto &it:adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        return res;    
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
    int V=10;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,1,6);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,4,5);
    addEdge(adj,5,8);
    addEdge(adj,7,8);
    addEdge(adj,6,7);
    addEdge(adj,6,9);
    Solution obj;
    vector<int>ans=obj.bfsofgraph(V,adj,1);
    print(ans);
    return 0;
}
*/
vector<int> bfsofgraph(int V, vector<int>adj[], int start){
    vector<int>visited(V,0);
    visited[start]=1;
    queue<int>q;
    vector<int>res;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return res;
}

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int>ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int V=10;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,1,6);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,6,7);
    addEdge(adj,6,9);
    addEdge(adj,4,5);
    addEdge(adj,7,8);
    addEdge(adj,5,8);

    vector<int>ans=bfsofgraph(V, adj,1);
    print(ans);
    return 0;
}

