#include<bits/stdc++.h>
using namespace std;
/*
class Solution{
    private:
    vector<int>topo_sort(vector<int>adj[],int K){
        vector<int>indegree(K,0);
        for(int i=0;i<K;i++){
            for(auto &it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>result;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto &it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }              
            }
        }
        return result;                
    }

    public:
    string alien_dictionary(string dict[],int N,int K){
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int p=0;p<len;p++){
                if(s1[p] != s2[p]){
                    adj[s1[p]-'a'].push_back(s2[p]-'a');
                    break;
                }
            }
        }
        vector<int>topo=topo_sort(adj,K);
        string ans="";
        for(auto &it:topo){
            ans=ans+(char)(it+'a');
        }
        return ans;
    }
   
};

int main(){
    int N=5;
    int K=4;
    string dict[]={ "baa","abcd","abca","cab","cad"};
    Solution obj;
    string ans=obj.alien_dictionary(dict,N,K);
    cout<<"the order is ";
    for(auto &it:ans){
        cout<<it<<' ';
        cout<<endl;
    }
    return 0;
}

*/
vector<int>topo_sort(vector<int>adj[], int K){
    vector<int>indegree(K,0);
    for(int i=0;i<K;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    vector<int>result;
    queue<int>q;
    for(int i=0;i<K;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        result.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return result;
}

string alien_dictionary(string dict[],int N,int K){
    vector<int>adj[K];
    for(int i=0;i<N-1;i++){
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        for(int p=0;p<len;p++){
            if(s1[p] != s2[p]){
                adj[s1[p]-'a'].push_back(s2[p]-'a');
                break;
            }
        }
    }
    vector<int>topo=topo_sort(adj,K);
    string ans="";
    for(auto &it:topo){
        ans=ans+(char)(it+'a');
    }
    return ans;
}
int main(){
    int N=5;
    int K=4;
    string dict[]={ "baa","abcd","abca","cab","cad"};
    string ans=alien_dictionary(dict,N,K);
    cout<<"the order is ";
    for(auto &it:ans){
        cout<<it<<' ';
        cout<<endl;
    }
    return 0;
}



