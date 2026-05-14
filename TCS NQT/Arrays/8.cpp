#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>&arr, int d){
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());
}

int main(){
    vector<int>arr={2,3,4,5,6};
    int d=2;
    rotate(arr,d);
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}