#include<bits/stdc++.h>
using namespace std;

//BRUTE
//Finding Sqrt of a number
int square_root(int n){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i*i<=n){
            ans=i;
        }
        else {
            break;
        }
    }
    return ans;
}
int main(){
    int n=28;
    int ans=square_root(n);
    cout<<"the squar eroot of the element is "<<ans;
    return 0;
}

//OPTIMAL
int square_root(int n){
    int low=1;
    int high=n;
    int ans=0;
    while(low<=high){
        int mid=low + (high - low) / 2;
        if(mid*mid <= n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    int n=28;
    int ans=square_root(n);
    cout<<"the squar eroot of the element is "<<ans;
    return 0;
}