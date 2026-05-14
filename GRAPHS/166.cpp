#include <bits/stdc++.h>
using namespace std;
/*
class Solution{
    public:
    vector<int>ford_algo(vector<vector<int>>&edges,int n,int sn){
        vector<int>dist(n,1e8);
        dist[sn]=0;
        for(int i=0;i<n;i++){
            for(auto &it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u] + wt < dist[v] && dist[u] !=1e8){
                    dist[v]=dist[u]+wt;
                }
            }
        }

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u] + wt < dist[v] && dist[u] !=1e8){
                return {-1};
            }
        }
        return dist;
    }
};

int main(){
    int n=6;
    int m=7;
    vector<vector<int>>edges={{0,1,5},{1,2,-2},{1,5,-3},{5,3,1},
                              {3,2,6},{3,4,-2},{2,4,3}};
    int sn=0;
    Solution obj;
    vector<int>res=obj.ford_algo(edges,n,sn);
    for(auto &it:res){
        cout<<it<<" ";
    }                 
    cout<<endl;
    return 0;         
}

*/
vector<int>ford_algo(vector<vector<int>>edges,int n,int sn){
    vector<int>dist(n,1e8);
    dist[sn]=0;
    for(int i=0;i<n-1;i++){
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u] !=1e8 && wt + dist[u] < dist[v]){
                dist[v]=wt + dist[u];
            }
        }
    }
    for(auto &it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if( dist[u] !=1e8 && wt + dist[u] < dist[v]){
            return {-1};
        }
    }
    return dist;
}

int main(){
    int n=6;
    int m=7;
    vector<vector<int>>edges={{0,1,5},{1,2,-2},{1,5,-3},{5,3,1},
                              {3,2,6},{3,4,-2},{2,4,3}};
    int sn=0;
    vector<int>res=ford_algo(edges,n,sn);
    for(auto &it:res){
        cout<<it<<" ";
    }                 
    cout<<endl;
    return 0;         
}
