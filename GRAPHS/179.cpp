#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>>&adj,vector<int>&visited, stack<int>&st){
    visited[i]=1;
    for(auto &it:adj[i]){
        if(!visited[it]){
            dfs(it,adj,visited,st);
        } 
    }
    st.push(i);
}

void dfsReverse(int node,vector<vector<int>>&adjReverse,vector<int>&visited){
    visited[node]=1;
    for(auto &it:adjReverse[node]){
        if(!visited[it]){
            dfsReverse(it,adjReverse,visited);
        } 
    }
}

int kosaraju(int v,vector<vector<int>>&adj){
    vector<int>visited(v,0);
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
    vector<vector<int>>adjReverse(v);
    for(int i=0;i<v;i++){
        for(auto &it:adj[i]){
            adjReverse[it].push_back(i);
        }
    }
    int cntscc=0;
    fill(visited.begin(), visited.end(), 0);
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            dfsReverse(node,adjReverse,visited);
            cntscc++;
        }
    }
    return cntscc;
}

int main(){
    int V = 11; // A to K
    vector<vector<int>> adj(V);
    adj[0].push_back(1); // A → B
    adj[1].push_back(2); // B → C
    adj[2].push_back(0); // C → A
    adj[1].push_back(3); // B → D
    adj[3].push_back(4); // D → E
    adj[4].push_back(5); // E → F
    adj[5].push_back(3); // F → D
    adj[5].push_back(6); // F → G
    adj[6].push_back(7); // G → H
    adj[7].push_back(8); // H → I
    adj[8].push_back(9); // I → J
    adj[9].push_back(6); // J → G
    adj[9].push_back(10); // J → K
    cout << kosaraju(V, adj);
    return 0;
}