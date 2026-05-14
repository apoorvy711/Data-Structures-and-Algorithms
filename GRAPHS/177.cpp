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

int max_size_island(vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    parent.resize(n*m);
    int mx=0;
    sizearr.resize(n*m,1);
    for(int i=0;i<n*m;i++){
        parent[i]=i;
    }
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(grid[r][c]==0) continue;
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if( ((nr>=0 && nr<n)&&(nc>=0 && nc<m)) && (grid[nr][nc]==1)){
                    int nodeN=r*m+c;
                    int adjnodeNo=nr*m+nc;
                    unionbySize(nodeN,adjnodeNo);
                }
            }
        }
    }
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(grid[r][c]==1) continue;
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            set<int>components;
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if( (nr>=0 && nr<n)&&(nc>=0 && nc<m)){
                    if(grid[nr][nc]==1){
                        components.insert(findUPar(nr*m+nc));
                    }
                }
            }
            int totalSize=1;
            for(auto it:components){
                totalSize+=sizearr[it];
            }
            mx=max(mx,totalSize);
        }
    }
    for(int i=0;i<n*m;i++){
        mx=max(mx,sizearr[findUPar(i)]);
    }
    return mx;
}

int main(){
    vector<vector<int>> grid = {
    {1,1,0,1,1},
    {1,1,0,1,1},
    {1,1,0,1,1},
    {0,0,1,0,0},
    {0,0,1,1,1},
    {0,0,1,1,1}
    };
    int ans=max_size_island(grid);
    cout<<ans;
    return 0;
}