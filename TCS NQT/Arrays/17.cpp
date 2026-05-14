#include<bits/stdc++.h>
using namespace std;

vector<int>ranki(vector<int>&arr){
    vector<int>sortedARR=arr;
    vector<int>res;
    unordered_map<int,int>rankmap;
    int rank=1;
    sort(sortedARR.begin(),sortedARR.end());
    for(int x:sortedARR){
        if(rankmap.find(x) == rankmap.end()){
            rankmap[x]=rank;
            rank++;
        }
    }
    for(int x:arr){
        res.push_back(rankmap[x]);
    }
    return res;
}

int main(){
    vector<int>arr={1, 5, 8, 15, 8, 25, 9};
    vector<int>ans=ranki(arr);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}