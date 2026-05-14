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
    if(pu==pv) return;
    if(sizearr[pv] < sizearr[pu]){
        parent[pv]=pu;
        sizearr[pu]+=sizearr[pv];
    }
    else{
        parent[pu]=pv;
        sizearr[pv]+=sizearr[pu];
    }
}

vector<int>number_of_islands_at_each_operations(int n , int m,vector<vector<int>>&operations){
    vector<vector<int>>vis(n,vector<int>(m,0));
    parent.resize(n*m);
    sizearr.resize(n*m,1);
    for(int i=0;i<n*m;i++){
        parent[i]=i;
    }
    vector<int>ans;
    int cnt=0;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    for(auto &it:operations){
        int r=it[0];
        int c=it[1];
        if(vis[r][c]==1){
            ans.push_back(cnt);
            continue;
        }
        vis[r][c]=1;
        cnt++;
        int nodeNo=r*m+c;
        for(int i=0;i<4;i++){
            int nr=r+delrow[i];
            int nc=c+delcol[i];
            if( ((nr>=0 && nr<n) && (nc>=0 && nc<m)) && vis[nr][nc]==1){
                int adjnodeNo=nr*m+nc;
                if(findUPar(nodeNo) != findUPar(adjnodeNo)){
                    cnt--;
                    unionbySize(nodeNo,adjnodeNo);
                }
            } 
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main(){
    int n=4;
    int m=5;
    vector<vector<int>>operations={
        {0,0},
        {0,0},
        {1,1},
        {1,0},
        {0,1},
        {0,3},
        {1,3},
        {0,4},
        {3,2},
        {2,2},
        {1,2},
        {0,2}
    };
    vector<int>ans=number_of_islands_at_each_operations(n,m,operations);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}