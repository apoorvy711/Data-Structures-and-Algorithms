#include<bits/stdc++.h>
using namespace std;

vector<int>parent, sizearr;

int findUPar(int node){
    if(node==parent[node]) return node;
    return parent[node]=findUPar(parent[node]);
}

void unionbySize(int u , int v){
    int pu=findUPar(u);
    int pv=findUPar(v);
    if(pu==pv) return ;
    if(sizearr[pv] < sizearr[pu]){
        parent[pv]=pu;
        sizearr[pu]+=sizearr[pv];
    }
    else{
        parent[pu]=pv;
        sizearr[pv]+=sizearr[pu];
    }
}

int maxRemove(vector<vector<int>>stones, int n){
    int maxrow=0;
    int maxcol=0;
    for(auto &it:stones){
        maxrow=max(maxrow,it[0]);
        maxcol=max(maxcol,it[1]);
    }
    int totalNodes=maxrow+maxcol+2;
    parent.resize(totalNodes);
    sizearr.resize(totalNodes,1);
    for(int i=0;i<totalNodes;i++){
        parent[i]=i;
    }
    unordered_set<int> nodes;
    for(auto &it:stones){
        int row=it[0];
        int col=it[1]+maxrow+1;
        unionbySize(row,col);
        nodes.insert(row);
        nodes.insert(col);
    }
    int cnt=0;
    for(auto node:nodes){
        if(findUPar(node) == node){
            cnt++;
        }
    }
    return n-cnt;
}

int main(){
    vector<vector<int>> stones = {
    {0,0},
    {0,2},
    {1,3},
    {3,1},
    {3,2},
    {4,3}
    };
    int n = stones.size();
    cout << maxRemove(stones, n);
    return 0;

}