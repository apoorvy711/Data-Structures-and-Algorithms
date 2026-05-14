#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>sym_pair(vector<pair<int,int>>&arr){
    int n=arr.size();
    unordered_map<int,int>mp;
    vector<pair<int,int>>res;
    for(int i=0;i<n;i++){
        int first=arr[i].first;
        int second=arr[i].second;
        if(mp.find(second) != mp.end() && mp[second] == first){
            res.push_back({first,second});
        }
        else{
            mp[first]=second;
        }
    }
    return res;
}

int main(){
    vector<pair<int,int>>arr={{1,2},{3,2},{2,1},{4,5},{5,4},{3,2},{5,6}};
    vector<pair<int,int>>ans=sym_pair(arr);
    for(auto p:ans){
        cout<<"("<<p.first<<","<<p.second<<")"<<" ";
    }
    return 0;
}