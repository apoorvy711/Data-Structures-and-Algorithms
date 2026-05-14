#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>safe_nodes(int V,vector<int>adj[]){
        vector<int>adjRev[V];
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto &it:adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>result;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto &it:adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
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
    addEdge(adj,2,4);

    Solution obj;
    vector<int>ans=obj.safe_nodes(V,adj);
    for(auto & it:ans){
        cout<<it<<" "; 
    }
    cout<<endl;
    return 0;
}

