#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool dfs(int start,vector<int>adj[],vector<int>&visited,vector<int>&pathVisited,vector<int>&check){
        visited[start]=1;
        pathVisited[start]=1;
        check[start]=0;

        for(auto & it:adj[start]){
            if(!visited[it]){
                if(dfs(it,adj,visited,pathVisited,check)==true){
                    check[start]=0;
                    return true;
                }
            }
            else if(pathVisited[it]){
                check[start]=0;
                return true;
            }
        }
        check[start]=1;
        pathVisited[start]=0;
        return false;
    }

    vector<int> detect_cycle(int V,vector<int>adj[]){
        vector<int>visited(V,0);
        vector<int>pathVisited(V,0);
        vector<int>check(V,0);
        vector<int>safenodes;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,pathVisited,check)){
                }
            }
        }

        for(int i=0;i<V;i++){
            if(check[i]==1){
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

int main(){
    int V=12;
    vector<int>adj[V];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,3,5);
    addEdge(adj,5,6);
    addEdge(adj,6,7);
    addEdge(adj,8,9);
    addEdge(adj,9,10);
    addEdge(adj,10,8);
    addEdge(adj,8,1);
    addEdge(adj,4,6);
    addEdge(adj,11,9);

    Solution obj;
    vector<int> ans=obj.detect_cycle(V,adj);
    cout<<"the safe nodes are "<<endl;
    for(auto &it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

