#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
		// Fill the distance matrix with direct edges
		for (auto edge : edges) {
			int u = edge[0], v = edge[1], wt = edge[2];
			dist[u][v] = wt;
			dist[v][u] = wt; // undirected graph
		}

		// Distance from node to itself is zero
		for (int i = 0; i < n; i++) dist[i][i] = 0;

		// Floyd-Warshall Algorithm
		for (int via = 0; via < n; via++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
				}
			}
		}

		int minReachable = n;
		int resultCity = -1;

		for (int i = 0; i < n; i++) {
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (dist[i][j] <= distanceThreshold)
					count++;
			}

			// If tie, prefer the city with greater number (as per problem)
			if (count <= minReachable) {
				minReachable = count;
				resultCity = i;
			}
		}
		return resultCity;
	}
};

int main() {
	int n = 4, m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}
*/
int findCity(int n,int m,vector<vector<int>>&edges,int distanceThreshold){
	vector<vector<int>>dist(n,vector<int>(n,1e9));
	for(auto it:edges){
		int u=it[0];
		int v=it[1];
		int wt=it[2];
		dist[u][v]=wt;
		dist[v][u]=wt;
	}
	for(int i=0;i<n;i++){
		dist[i][i]=0;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][k]==1e9 || dist[k][j]==1e9) continue;
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	int minreachcity=n;
	
	int city_no=-1;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(dist[i][j] <= distanceThreshold){
				cnt++;
			}
		}
		if(cnt<=minreachcity){
			minreachcity=cnt;
			city_no=i;
		}
	}
	return city_no;
}

int main() {
	int n = 4, m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	int cityNo =findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}