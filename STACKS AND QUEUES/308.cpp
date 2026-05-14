#include<bits/stdc++.h>
using namespace std;

//BRUTE
vector<int> findNSE(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    vector<int>nse(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        nse[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nse;
}

vector<int>findPSE(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    vector<int>pse(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        pse[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pse;    
}

int func(vector<int>arr){
    vector<int> pse=findPSE(arr);
    vector<int> nse=findNSE(arr);

    int maxi=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++){
        maxi=max(arr[i]*(nse[i]-pse[i]-1),maxi);
    }
    return maxi;

}

int main(){
    vector<int>arr={2,1,5,6,2,3};
    int ans=func(arr);
    cout<<"the largest rectangel area is "<<ans;
    return 0;
}

//OPTIMAL
int func(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    int maxAREA=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int el=st.top();
            st.pop();
            int nse=i;
            int pse=st.empty()?-1:st.top();
            maxAREA=max(arr[el]*(nse-pse-1),maxAREA);
        }
        st.push(i);
    }
    while(!st.empty()){
        int nse=n;
        int el=st.top();
        st.pop();
        int pse=st.empty()?-1:st.top();
        maxAREA=max(arr[el]*(nse-pse-1),maxAREA);
    }
    return maxAREA;
}

int main(){
    vector<int>arr={3,2,10,11,5,10,6,3};
    int ans=func(arr);
    cout<<"the largest rectangel area is "<<ans;
    return 0;
}
 