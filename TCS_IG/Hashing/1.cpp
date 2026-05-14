#include<bits/stdc++.h>
using namespace std;
/*
//COMMON ELEMNETS IN TWO ARRAYS
vector<int>common_el(vector<int>arr1,vector<int>arr2){
    unordered_map<int,int>mpp;
    int n=arr1.size();
    int m=arr2.size();
    for(auto x:arr1){
        mpp[x]++;
    }
    vector<int>res;
    for(int i=0;i<m;i++){
        if(mpp.find(arr2[i]) !=mpp.end()){
            res.push_back(arr2[i]);
            mpp.erase(arr2[i]);
        }
    }
    return res;
}

int main(){
    vector<int>arr1={1,2,2,3,4};
    vector<int>arr2={2,3,3,5};
    vector<int>ans=common_el(arr1,arr2);
    for(auto x:ans){
        cout<<x;
    }
    return 0;
}


//GROUP ANAGRAMS TOGETHER
vector<vector<string>>grp_anag(vector<string>strs){
    unordered_map<string, vector<string>>mpp;
    for(auto word:strs){
        string temp=word;
        sort(temp.begin(),temp.end());
        mpp[temp].push_back(word);
    }
    vector<vector<string>>ans;
    for(auto x:mpp){
        ans.push_back(x.second);
    }
    return ans;
}
int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>ans=grp_anag(strs);
    for(auto i:ans){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"]";
    }
    return 0;
}


//INDICES OF TARGET SUM
pair<int,int>subsub(vector<int>arr, int target){
    int left=0;
    int sum=0;

    for(int right=0;right<arr.size();right++){
        sum+=arr[right];
        while(sum>target){
            sum-=arr[left];
            left++;
        }
        if(sum==target){
            return {left,right};
        }
    }
    return {-1,-1};
}

int main(){
    vector<int>arr={1,4,20,3,10,5};
    int target=33;
    pair<int,int>ans=subsub(arr,target);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}

//LONGEST CONTINOUS SEQUENCE
int subsq(vector<int>arr){
    int n=arr.size();
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int longest=1;
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1) !=st.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    vector<int>arr={100,4,200,1,3,2};
    int ans=subsq(arr);
    cout<<ans;
    return 0;
}

*/