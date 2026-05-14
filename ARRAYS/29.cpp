#include<bits/stdc++.h>
using namespace std;

//BETTER SOLUTION
int longst_succssiveArray(vector <int> &arr, int n){
    int currnt_sum=0;
    int longest=1;
    n=arr.size();
    int last_smaller=INT_MIN;
    sort(arr.begin(),arr.end());
   
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]-1 == last_smaller){
            cnt +=1;
            last_smaller=arr[i];
        }
        else if(last_smaller != arr[i]){
            cnt =1;
            last_smaller=arr[i];
        }
        longest=max(longest,cnt);
    }
    return longest;

}
int main(){
    vector<int> arr={10,22,12,3,0,6};
    int n=arr.size();
    int longstARRAY=longst_succssiveArray(arr,n);
    cout<<"the longest consecutive array is"<<longstARRAY<<endl;
    return 0;
}

//OPTIMAL SOLUTION
int longst_succssiveArray(vector <int> &arr, int n){
    n=arr.size();
    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int i;
    for(auto it:st){
        if(st.find(it-1)== st.end()){
            int cnt=1;
            int x=it;
        
        while(st.find(x+1) != st.end()){
            int cnt=1;
            cnt =cnt +1;
        }
        longest=max(longest,cnt);
        }
    }
    return longest;
}
int main(){
    vector<int> arr={100,4,200,1,3,2};
    int n=arr.size();
    int longstARRAY=longst_succssiveArray(arr,n);
    cout<<"the longest consecutive array is"<<longstARRAY<<endl;
    return 0;
}
