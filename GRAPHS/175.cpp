#include<bits/stdc++.h>
using namespace std;

vector<int>parent, sizearr;

int findUPar(int node){
    if(node==parent[node]) return node;
    return parent[node]=findUPar(parent[node]);
}

void unionbySize(int u,int v){
    int pu=findUPar(u);
    int pv=findUPar(v);
    if(pu==pv) return;
    if(sizearr[pv] < sizearr[pu]){
        parent[pv]=pu;
        sizearr[pu]+=sizearr[pv];
    }
    else {
        parent[pu]=pv;
        sizearr[pv]+=sizearr[pu];
    }
}

vector<vector<string>>accounts_merge(vector<vector<string>>&details){
    unordered_map<string,int>mapmailNode;
    int n=details.size();
    sizearr.resize(n,1);
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<details[i].size();j++){
            string mail=details[i][j];
            if(mapmailNode.find(mail) == mapmailNode.end()){
                mapmailNode[mail]=i;
            }
            else{
                unionbySize(i,mapmailNode[mail]);
            }
        }
    }
    vector<string>mergedMail[n];
    for(auto it:mapmailNode){
        string mail=it.first;
        int node=findUPar(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>>ans;
    for(int i=0;i<n;i++){
        if(mergedMail[i].size()==0) continue;
        sort(mergedMail[i].begin(),mergedMail[i].end());
        vector<string>temp;
        temp.push_back(details[i][0]);
        for(auto &it:mergedMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    vector<vector<string>>details={{"John","j1@com","j2@com","j3@com"},
    {"John","j4@com"},
    {"Raj","r1@com","r2@com"},
    {"John","j1@com","j5@com"},
    {"Raj","r2@com","r3@com"},
    {"Mary","m1@com"}
    };
    vector<vector<string>>ans=accounts_merge(details);
    for(auto &it:ans){
        for(auto &iit:it){
            cout<<iit<<" ";
        }
        cout<<endl;
    }
    return 0;
}