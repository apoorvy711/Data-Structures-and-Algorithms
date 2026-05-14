#include<bits/stdc++.h>
using namespace std;
/*
//start
vector<int>add_el_start(vector<int>&arr, int el){
    arr.insert(arr.begin(),el);
    return arr;
}

int main(){
    vector<int>arr={1,2,3,4,5,5,6,7,8};
    int el=69;
    vector<int>ans=add_el_start(arr,el);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
*/
/*
//end
vector<int>add_el_end(vector<int>&arr, int el){
    arr.insert(arr.end(),el);
    return arr;
}

int main(){
    vector<int>arr={1,2,3,4,5,5,6,7,8};
    int el=69;
    vector<int>ans=add_el_end(arr,el);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


//kth
vector<int>add_el_kth(vector<int>&arr, int el, int k){
    arr.insert(arr.begin()+k,el);
    return arr;
}

int main(){
    vector<int>arr={1,2,3,4,5,5,6,7,8};
    int el=69;
    int k=4;
    vector<int>ans=add_el_kth(arr,el,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

*/


vector<int>repeating_el(vector<int>arr){
    int n=arr.size();
    vector<int>res;
    unordered_map<int,int>mpp;
    for(auto x:arr){
        mpp[x]++;
    }
    for(auto it:mpp){
        if(it.second ==1){
            res.push_back(it.first);
        }
    }
    return res;
}

int main(){
    vector<int>arr={1,1,2,3,4,5,6,7,7};
    vector<int>ans=repeating_el(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}