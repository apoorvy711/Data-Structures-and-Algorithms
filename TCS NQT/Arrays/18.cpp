#include<bits/stdc++.h>
using namespace std;

vector<int>by_freq(vector<int>&arr){
    unordered_map<int,int>freq;
    for(int x:arr){
        freq[x]++;
    }
    vector<pair<int,int>>p;
    for(auto it:freq){
        p.push_back({it.second,it.first});
    }
    vector<int>res;
    sort(p.rbegin(),p.rend());
    for(auto it:p){
        for(int i=0;i<it.first;i++){
            res.push_back(it.second);
        }
    }
    return res;
}

int main(){
    vector<int>arr={4,6,2,6,4,4,2};
    vector<int>ans=by_freq(arr);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}