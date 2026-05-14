#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> mergeOverlappingintervals(vector<vector<int>> &arr){
    vector<vector<int>> ans;

    int n=arr.size();
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> arr={ {1, 3}, {8, 10}, {2, 6}, {15, 18} };
    vector<vector<int>> ans=mergeOverlappingintervals(arr);
    cout<<"the intervals are";
    for(int i=0;i<ans.size();i++){
        cout<<" [ "<<ans[i][0]<<","<<ans[i][1]<<"]"<<endl;
    }
    cout<<endl;
    return 0;

}