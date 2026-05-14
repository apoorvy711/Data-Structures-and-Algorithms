#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    vector<int>topo_sort(int V,vector<int>adj[]){
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto &it:adj[i]){
                indegree[it]++;
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
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return result;
    }
};

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

int main(){
    int V=6;
    vector<int>adj[V];
    addEdge(adj,5,0);
    addEdge(adj,5,2);
    addEdge(adj,2,3);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,0);
   

    Solution obj;
    vector<int> ans=obj.topo_sort(V,adj);
    cout<<"the sorted nodes are "<<endl;
    for(auto &it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

*/

//KAHNs ALGORITHM

vector<int>topo_sort(int V, vector<int>adj[]){
    queue<int>q;
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>res;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return res;
}

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

int main(){
    int V=6;
    vector<int>adj[V];
    addEdge(adj,5,0);
    addEdge(adj,5,2);
    addEdge(adj,2,3);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,0);

    vector<int> ans=topo_sort(V,adj);
    cout<<"the sorted nodes are "<<endl;
    for(auto &it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

