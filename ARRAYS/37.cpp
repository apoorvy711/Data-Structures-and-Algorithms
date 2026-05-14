#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> four_sum(vector<int> &arr,int target){
    vector<vector<int>> ans;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j] == arr[j-1]) continue;

            int k=j+1;
            int l=n-1;

            while(k<l){
                long sum=arr[i];
                sum +=arr[j];
                sum +=arr[k];
                sum +=arr[l];
                if(sum == target){
                    vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k] == arr[k-1]) k++;
                    while(k<l && arr[l] == arr[l+1]) l--; 
                }
                else if(sum<target) k++;
                else l--;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> arr={4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target=9;
    vector<vector<int>> ans=four_sum(arr,target);
    cout<<"the numbers are:";
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"] \n";
    }
    cout<<endl;
    return 0;
}