#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public: 
    bool dfs(int node,int start,vector<int>adj[],vector<int>&color){
        color[node]=start;

        for(auto & it:adj[node]){
            if(color[it]==-1){
                if(dfs(it,1-start,adj,color)==false){
                    return false;
                }
                else if(color[it]==start){
                    return false;
                }
            }
        }
        return false;
    }

    bool bipartite(int V,vector<int>adj[]){
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,adj,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V=9;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,2,6);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,6,5);
    addEdge(adj,4,7);
    addEdge(adj,7,8);

    Solution obj;
    bool ans=obj.bipartite(V,adj);
    if(ans){
        cout<<"BIPARTITE GRAPH";
    }
    else{
        cout<<"NOT A BIPARTITE GRAPH";
    }
    return 0;
}

*/
bool dfs(int node,int start,vector<int>adj[],vector<int>color){
    color[node]=start;
    for(auto &it:adj[node]){
        if(color[it]==-1){
            if(dfs(it,1-start,adj,color)==false){
                return false;
            }
        }
        else if(color[it]==start){
            return false;
        }
    }
    return true;
}

bool bipartite(int V,vector<int>adj[]){
    vector<int>color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(dfs(i,0,adj,color)==false){
                return false;
            }
        }
    }
    return true;
}

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V=9;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,2,6);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,6,5);
    addEdge(adj,4,7);
    addEdge(adj,7,8);

    bool ans=bipartite(V,adj);
    if(ans){
        cout<<"BIPARTITE GRAPH";
    }
    else{
        cout<<"NOT A BIPARTITE GRAPH";
    }
    return 0;
}
