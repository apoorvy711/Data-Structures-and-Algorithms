#include <bits/stdc++.h>
using namespace std;

bool jump(vector<int>&arr){
    int n=arr.size();
    int maxIndex=0;
    for(int i=0;i<n;i++){
        if(i>maxIndex) return false;
        maxIndex=max(maxIndex,i+arr[i]);
    }
    return true;
}

int main(){
    vector<int>arr={1,2,3,1,1,0,2,5};
    bool ans=jump(arr);
    if(ans){
        cout<<"TRUE";
    }
    else{
        cout<<"FALSE";
    }
    return 0;
}


