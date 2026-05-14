#include<bits/stdc++.h>
using namespace std;

vector<int>findPSE(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>pse(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i] <= st.top()){
            st.pop();
        }
        pse[i]=st.empty() ? -1:st.top();
        st.push(arr[i]);
    }
    return pse;

}

int main(){
    vector<int>arr={5,7,9,6,7,4,5,1,3,7};
    vector<int> ans=findPSE(arr);
    for(int i=0;i<ans.size();i++){
        cout<<"the previous smaller element is  "<<ans[i]<<endl;
    }
    return 0;

}


//NSE

vector<int> findNSE(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n);

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[i] <= st.top()) {
            st.pop();
        }
        nse[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return nse;
}

int main() {
    vector<int> arr = {5, 7, 9, 6, 7, 4, 5, 1, 3, 7};
    vector<int> ans = findNSE(arr);

    for(int i = 0; i < ans.size(); i++) {
        cout << "The next smaller element for " << arr[i] << " is " << ans[i] << endl;
    }

    return 0;
}
