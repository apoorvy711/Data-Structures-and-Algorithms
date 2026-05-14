#include<bits/stdc++.h>
using namespace std;

vector<int>relativeSort(vector<int>&A,vector<int>&B){
    unordered_map<int,int>freq;
    for(auto x:A){
        freq[x]++;
    }
    vector<int>res;
    for(auto x:B){
        while(freq[x]>0){
            res.push_back(x);
            freq[x]--;
        }
    }
    vector<int>ans;
    for(auto x:freq){
        while(x.second >0){
            ans.push_back(x.first);
            x.second--;
        }
    }
    sort(ans.begin(),ans.end());
    res.insert(res.end(),ans.begin(),ans.end());
    return res;

}

int main(){
    vector<int>A={2,1,2,5,7,1,9,3,6,8,8};
    vector<int>B={2,1,8,3};
    vector<int>ans=relativeSort(A, B);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}