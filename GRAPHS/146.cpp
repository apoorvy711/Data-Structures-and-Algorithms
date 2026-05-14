#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    void dfs(int start,vector<int>adj[],vector<int>&visited,stack<int>&st){
        visited[start]=1;
        for(auto &it:adj[start]){
            if(!visited[it]){
                dfs(it,adj,visited,st);
            }
        }
        st.push(start);
    }

    vector<int>topo_sort(int V,vector<int>adj[]){
        vector<int>visited(V,0);
        stack<int>st;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
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
   
void dfs(int start,vector<int>adj[],vector<int>&visited,stack<int>&st){
    visited[start]=1;
    for(auto &it:adj[start]){
        if(!visited[it]){
            dfs(it,adj,visited,st);
        }
    }
    st.push(start);
}
vector<int>topo_sort(int V,vector<int>adj[]){
    vector<int>visited(V,0);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
    vector<int>result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    return result;
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
 
