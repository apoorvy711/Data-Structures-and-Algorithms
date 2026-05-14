#include<bits/stdc++.h>
using namespace std;
/*
//Nth Root of a Numbe
//BRUTE
int Nth_root(int n,int m){
    int ans=1;
    for(int i=1;i<=m;i++){
        int val=pow(i,n);
        if(val==m) return i;
        if(val>m) break;
    }
    return -1;
}
int main(){
    int n=3;
    int m=27;
    //int ans=Nth_root(n,m);
    //cout<<"the Nth root of the number is "<<ans;
    return 0;
}
*/

//OPTIMAL
int func(int mid,int n,int m){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans> m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}
int Nth_root1(int n,int m){
    int low=1;
    int high=m;
    while(low<=high){
        int mid=low + (high - low) / 2; 
        int midN=func(mid,n,m);
        if(midN==1) {
            return mid;
        }
        else if(midN==0) {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n=3;
    int m=27;
    int ans=Nth_root1(n,m);
    cout<<"the Nth root of the number is "<<ans;
    return 0;
}
