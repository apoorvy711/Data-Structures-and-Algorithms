#include <bits/stdc++.h>
using namespace std;

//left rotate
vector<int>rotate(vector<int>&arr, int d){
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());
    return arr;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    int d=2;
    vector<int>ans=rotate(arr,d);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}


