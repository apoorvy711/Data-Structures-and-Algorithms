#include <bits/stdc++.h>
using namespace std;

//Reverse an array
int Rarray(int arr[],int n,int i){
    if(i>=n/2){
        return 0 ;
    }
    swap(arr[i],arr[n-i-1]);
    Rarray(arr,n,i+1);
}
int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Rarray(arr,n,0);
    for(int i=0;i<n;i++){
        cout<<"the array is"<<" "<<arr[i];
    }
    
    return 0;
}


//Palindrome
bool Pal(int i,string &s){
    if(i>=s.size()/2){
        return true;
    }
    if(s[i] !=s[s.size()-i-1]){
        return false;
    }
    return Pal(i+1,s);
}
int main(){
    string s="MMOEKJFEFS";
    cout<<Pal(0,s);
    return 0;
}
    