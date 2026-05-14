#include<bits\stdc++.h>
using namespace std;

void subsetSUM(int index,vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
    ans.push_back(ds);
    for(int i=index;i<arr.size();i++){
        if(i !=index && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        subsetSUM(i+1,arr,ds,ans);
        ds.pop_back();
    }
}

int  main(){
    vector<int> arr={2,1,2,3,2,3};
    vector<int>ds;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    subsetSUM(0,arr,ds,ans);
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
