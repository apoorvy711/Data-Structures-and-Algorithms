#include<bits/stdc++.h>
using namespace std;

vector<int> un_duplicates(vector<int>&arr){
    unordered_map<int,bool>seen;
    vector<int>res;
    for(int x:arr){
        if(!seen[x]){
            res.push_back(x);
            seen[x]=true;
        }
    }
    return res;
}

int main(){
    vector<int>arr={3,6,8,1,2,2,3,3,4,5};
    vector<int> ans=un_duplicates(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}