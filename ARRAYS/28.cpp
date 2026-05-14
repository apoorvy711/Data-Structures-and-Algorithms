#include<bits/stdc++.h>
using namespace std;

vector<int> leader_array(vector<int> &arr,int n){
    int maxi=INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi=max(maxi,arr[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> arr={10,22,12,3,0,6};
    int n=arr.size();

    vector <int> leaders= leader_array(arr,n);
    cout<<"the leaders are"<<" ";
    for(int i=0;i<leaders.size();i++){
        cout<<leaders[i]<<" ";
    }
    cout<<endl;
    return 0;
}