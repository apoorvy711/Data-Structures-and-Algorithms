#include <bits/stdc++.h>
using namespace std;

vector<int>sliding_window_max(vector<int> &arr,int k){
    vector<int>result;
    deque<int>dq;

    for(int i=0;i<arr.size();i++){
        while(!dq.empty() && arr[dq.back()] < arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);

        if(dq.front() <= i-k){
            dq.pop_front();
        }

        if(i>=k-1){
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}




int main(){
    vector<int> arr={ 1,3,-1,-3,5,3,2,1,6};
    int k=3;
    vector<int>ans=sliding_window_max(arr,k);
    for(int &it:ans){
        cout<<it<<" ";
    }
    return 0;
}