#include<bits/stdc++.h>
using namespace std;


int majority_element(vector<int> &arr,int n){
    int cnt=0;
    int el;
    for(int i=0;i<arr.size();i++){
        if(cnt == 0 ){
            cnt =1;
            el=arr[i];
        }
        else if (el==arr[i]){
            cnt++;
        }
        else {
            cnt--;
        }
    }  
    int cnt1=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]== el){
            cnt1++;
        }
    }
    if(cnt1 > (arr.size() / 2)){
        return el;
    }
    return -1;
}
int  main(){
    vector<int> arr={0,1,1,0,1,2,1,2,0,0,0,0};
    int n=arr.size();
    int ans=majority_element(arr,n);
    cout<<"ans is"<<ans;
    return 0;
}
