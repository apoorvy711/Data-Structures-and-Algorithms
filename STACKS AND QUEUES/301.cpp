#include<bits/stdc++.h>
using namespace std;

//BRUTE
vector<int>nextgreaterelementBRUTE(vector<int>&arr){
    int n=arr.size();
    vector<int>nge(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                nge[i]=arr[j];
                break;
            }
        }
    }
    return nge;
}

int main(){
    vector<int> arr={6,0,8,1,3};
    vector<int>ans=nextgreaterelementBRUTE(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

//OPTIMAL
vector<int>findNGE(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>nge(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]>st.top()){
            st.pop();
        }

        if(st.empty()) nge[i]=-1;
        else nge[i]=st.top();

        st.push(arr[i]);
    }
    return nge;
}

int main(){
   vector<int>arr={4,12,5,3,1,2,5,3,1,2,4,6};
   vector<int>ans=findNGE(arr);
   for(int i=0;i<arr.size();i++){
    cout<<"the next greater element of "<<arr[i]<<" is ->"<<ans[i]<<endl;
   } 
   cout<<"the next greater element at index 3 is "<<ans[3];
   return 0;
}
