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

int makeConnected(int n,vector<vector<int>>&connections ){
    int cntextras=0;
    parent.resize(n);
    sizearr.resize(n,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(auto &it:connections){
        int u=it[0];
        int v=it[1];
        if(findUPar(u) == findUPar(v)){
            cntextras++;
        }
        else{
            unionbySize(u,v);
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(parent[i]==i) cnt++;
    }
    int ans=cnt-1;
    if(cntextras >=ans) return ans;
    return -1;
}

int main() {
    int n = 6;
    vector<vector<int>> connections = {
    {0,1},{0,2},{0,3},{1,4},{2,3}
};
   
    cout << makeConnected(n, connections) << endl;
    return 0;
}