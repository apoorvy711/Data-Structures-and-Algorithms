#include<bits/stdc++.h>
using namespace std;

vector<int>findNGE( vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>nge(n);
    for(int i=(2*n-1);i>=0;i--){
        while(!st.empty() && arr[i%n]>=st.top()){
            st.pop();
        }
        if(i<n){
            nge[i]=st.empty() ? -1 : st.top();
        }
        st.push(arr[i%n]);
    }
    return nge;
}

int main(){
    vector<int>arr={2,10,12,1,11};
    vector<int> ans=findNGE(arr);
    for(int i=0;i<ans.size();i++){
        cout<<"the next greater element is  "<<ans[i]<<endl;
    }
    return 0;

}