#include <bits/stdc++.h>
using namespace std;

vector<int>max_min_window(vector<int>&arr){
    int n=arr.size();
    vector<int>pse(n);
    vector<int>nse(n);
    stack<int>st;
    int len=0;

    //PSE
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] >=arr[i]) st.pop();
        pse[i]=st.empty()?-1:st.top();
        st.push(i);
    }

    //NSE
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >=arr[i]) st.pop();
        nse[i]=st.empty()?n:st.top();
        st.push(i);
    }

    //window size
    vector<int>res(n+1,INT_MIN);
    for(int i=0;i<n;i++){
        len=nse[i]-pse[i]-1;
        res[len]=max(res[len],arr[i]);
    }

    //MISSING VALUES
    for(int i=n-1;i>=1;i--){
        res[i]=max(res[i],res[i+1]);
    } 
    //ignore res[0]
    res.erase(res.begin());
    return res;

}

int main(){
    vector<int>arr={10,20,30,50,10,70,30};

    vector<int>ans=max_min_window(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}