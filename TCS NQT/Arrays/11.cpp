#include<bits/stdc++.h>
using namespace std;

int duplicates(vector<int>&arr){
    int i=0;
    for(int j=1;j<arr.size();j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;
}

int main(){
    vector<int>arr={1,1,2,2,2,3,3,4,5};
    int ans=duplicates(arr);
    for(int i=0;i<ans;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}