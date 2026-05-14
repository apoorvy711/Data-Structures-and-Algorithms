#include<bits/stdc++.h>
using namespace std;


/*
//Course Schedule I 
class Solution{
    public:
    bool isPossible(int N,vector<pair<int, int>> prerequisites){
        vector<int>adj[N];
        for(auto &it:prerequisites){
            adj[it.first].push_back(it.second);
        }
        
        vector<int>indegree(N,0);
        for(int i=0;i<N;i++){
            for(auto &it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==N) return true;
        return false;
    }
};


//Course Schedule II 
class Solution{
    public:
    vector<int>isPossible(int V,vector<pair<int, int>>&prerequisites){
        vector<int>adj[V];
        for(auto &it:prerequisites){
            adj[it.second].push_back(it.first);
        }
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto &it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>result;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(result.size()==V) return result;;
        return {};
    }
};



int main() {

	vector<pair<int, int>> prerequisites;
	int N = 4;
	prerequisites.push_back({1, 0});
	prerequisites.push_back({2, 1});
	prerequisites.push_back({3, 2});

	Solution obj;
	vector<int> ans = obj.isPossible(N, prerequisites);

	if (ans) cout << "YES";
	else cout << "NO";
	cout << endl;


    for (auto task : ans) {
	cout << task << " ";
	}
	cout << endl;
	return 0;
}
*/

bool isPossible(int N,vector<pair<int, int>>&prerequisites){
    vector<int>adj[N];
    for(auto it:prerequisites){
        adj[it.second].push_back(it.first);
    }
    queue<int>q;
    vector<int>indegree(N,0);
    for(int i=0;i<N;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>res;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(res.size()==N) return true;
    return false;
}

int main(){
    vector<pair<int, int>> prerequisites;
	int N = 4;
	prerequisites.push_back({1, 0});
	prerequisites.push_back({2, 1});
	prerequisites.push_back({3, 2});

    bool ans=isPossible(N, prerequisites);

	if (ans) cout << "YES";
	else cout << "NO";
	cout << endl; 
}




vector<int>ispossible(int N,vector<pair<int, int>>&prerequisites){
    vector<int>adj[N];
    for(auto it:prerequisites){
        adj[it.second].push_back(it.first);
    }
    queue<int>q;
    vector<int>indegree(N,0);
    for(int i=0;i<N;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    vector<int>res;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(res.size()==N) return res;
    return {};
}

int main(){
    vector<pair<int, int>> prerequisites;
	int N = 4;
	prerequisites.push_back({1, 0});
	prerequisites.push_back({2, 1});
	prerequisites.push_back({3, 2});

    vector<int>ans=ispossible(N, prerequisites);
    for(auto it:ans){
        cout<<it<<" ";
    } 
    return 0;
}
