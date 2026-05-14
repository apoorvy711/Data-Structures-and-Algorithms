#include<bits/stdc++.h>
using namespace std;

void freq(vector<int>&arr){
    unordered_map<int,int>MAP;
    for(int i=0;i<arr.size();i++){
        MAP[arr[i]]++;
    }
    for(auto x:MAP){
        cout<<x.first<<" "<<x.second<<" "<<endl;
    }
}

int main(){
    vector<int>arr={2,3,3,5,1,3,7,8,3};
    freq(arr);
    return 0;
}