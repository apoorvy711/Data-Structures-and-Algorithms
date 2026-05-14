#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int MinimumEffort(vector<vector<int>> &heights){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        int delrow[]={-1, 0, 1, 0};
        int delcol[]={0, 1, 0, -1};
        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();
            if (r==n-1 && c==m-1) return diff;
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int mcol=c+delcol[i];
                if(nrow>=0 && nrow<n && mcol>=0 &&mcol<m){
                    int effort=max(abs(heights[r][c] - heights[nrow][mcol]),diff);
                    if(effort<dist[nrow][mcol]){
                        dist[nrow][mcol]=effort;
                        pq.push({effort,{nrow,mcol}});
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    // Driver Code.
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    Solution obj;
    int ans = obj.MinimumEffort(heights);
    cout << ans;
    cout << endl;
    return 0;
}