#include<bits/stdc++.h>
using namespace std;

vector<int>parent, sizearr;

int findUPar(int node){
    if(node==parent[node]) return node;
    return parent[node]=findUPar(parent[node]);
}

void unionbySize(int u, int v){
    int pu=findUPar(u);
    int pv=findUPar(v);
    if(sizearr[pv] < sizearr[pu]){
        parent[pv]=pu;
        sizearr[pu]+=sizearr[pv];
    }
    else{
        parent[pu]=pv;
        sizearr[pv]+=sizearr[pu];
    }
}

int kruskalMST(int V,vector<vector<int>> adj[] ){
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            int adjnode=it[0];
            int wt=it[1];
            edges.push_back({wt,{i,adjnode}});
        }
    }
    sort(edges.begin(), edges.end());
    parent.resize(V);
    sizearr.resize(V,0);
    for(int i=0;i<V;i++) parent[i]=i;
    int mstwt=0;
    for(auto &it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(findUPar(u) != findUPar(v)){
            mstwt+=wt;
            unionbySize(u,v);
        }
    }
    return mstwt;  
}

int main(){
    int V = 5;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges = {
        {0,1,2}, {0,2,1}, {1,2,1}, {2,4,2}, {2,3,2}, {3,4,1}
    };
    for(auto &it : edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    cout << "Kruskal MST Weight: " << kruskalMST(V, adj) << endl;
    return 0;
}