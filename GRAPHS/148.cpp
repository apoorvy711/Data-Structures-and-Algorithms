#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    bool cycle(int V,vector<int>adj[]){
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
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==V) return false;
        return true;
    }
};

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

int main(){
    int V=6;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,2);
    addEdge(adj,3,5);
   
    Solution obj;
    bool ans=obj.cycle(V,adj);
    if(ans){
        cout<<"the cycle is present in the graph";
    }
    else{
        cout<<"the cycle is absent in the graph";
    }
    cout<<endl;
    return 0;
}

*/


bool cycle(int V, vector<int>adj[]){
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        cnt++;
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(cnt==V) return false;
    return true;
}

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

int main(){
    int V=6;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,2);
    addEdge(adj,3,5);
    bool ans=cycle(V,adj);
    if(ans){
        cout<<"the cycle is present in the graph";
    }
    else{
        cout<<"the cycle is absent in the graph";
    }
    cout<<endl;
    return 0;
}