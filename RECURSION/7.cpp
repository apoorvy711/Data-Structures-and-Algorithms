#include<bits\stdc++.h>
using namespace std;

void combineSum(int index,vector<int>&arr,int target,vector<vector<int>> &ans,vector<int> &ds){
    int n=arr.size();
    if(index==n){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[index] <=target){
        ds.push_back(arr[index]);
        combineSum(index,arr,target-arr[index],ans,ds);
        ds.pop_back();
    }
    combineSum(index+1,arr,target,ans,ds);
}

int main(){
    vector<int> arr={2,3,6,7};
    int target=7;
    vector<vector<int>>ans;
    vector<int>ds;
    combineSum(0,arr,target,ans,ds);
    cout << "Combinations are: \n";
    for (auto &vec : ans) {
        cout << "[ ";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}

 