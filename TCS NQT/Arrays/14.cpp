#include<bits/stdc++.h>
using namespace std;

vector<int>print_duplicates(vector<int>&arr){
    unordered_map<int,int>repeat;
    vector<int>res;
    for(auto x:arr){
        repeat[x]++;
    }
    for(auto i:repeat){
        if(i.second>1){
            res.push_back(i.first);
        }
    }
    return res;
}

int main(){
    vector<int>arr={1,2,2,3,3,4,5,6,6,7,7,7};
    vector<int>ans=print_duplicates(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}