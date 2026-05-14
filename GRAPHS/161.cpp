#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    int distance(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        q.push({0, {source.first, source.second}});
        dist[source.first][source.second] = 0;

        while (!q.empty()) {
            auto it = q.front(); q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 4; ++i) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol]) {

                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }

        if (dist[destination.first][destination.second] == 1e9)
            return -1;
        return dist[destination.first][destination.second];
    }
};

int main() {
    pair<int, int> source = {0, 1}, destination = {2, 2};
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}
    };

    Solution obj;
    int res = obj.distance(grid, source, destination);
    cout << res << endl;
    return 0;
}



*/

int distance(vector<vector<int>>& grid,pair<int, int> source, pair<int, int> destination) {
    queue<pair<int,pair<int,int>>>q;
    int n=grid.size();
    int m=grid[0].size();
    if(grid[source.first][source.second]==0) return -1;
    if(source == destination) return 0;
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    q.push({0,{source.first,source.second}});
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    dist[source.first][source.second]=0;
    while(!q.empty()){
        auto it=q.front();
        int dis=it.first;
        int r=it.second.first;
        int c=it.second.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int mcol=c+delcol[i];
            if((nrow>=0 && nrow<n) &&(mcol>=0 && mcol<m) &&(grid[nrow][mcol]==1) &&(1+dis < dist[nrow][mcol])){
                dist[nrow][mcol]=1+dis;
                q.push({1+dis,{nrow , mcol}});
                if(nrow==destination.first && mcol ==destination.second){
                    return 1+dis;
                }
            }
        }
    }
    return -1;
};

int main() {
    pair<int, int> source = {0, 1}, destination = {2, 2};
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}
    };
    int res = distance(grid, source, destination);
    cout << res << endl;
    return 0;
}





