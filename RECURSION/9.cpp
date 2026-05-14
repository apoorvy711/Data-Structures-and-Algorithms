#include<bits\stdc++.h>
using namespace std;

void combineSUMII(int index, vector<int> &arr,int target, vector<int> &ds, vector<vector<int>> &ans){
    int n=arr.size();
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=index;i<n;i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        combineSUMII(i+1,arr,target-arr[i],ds,ans);
        ds.pop_back();
    }   
}

int main(){
    vector<int> arr={1,1,1,2,2};
    vector<vector<int>>ans;
    vector<int>ds;
    int target=4;
    sort(arr.begin(),arr.end());
    combineSUMII(0,arr,target,ds,ans);
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
