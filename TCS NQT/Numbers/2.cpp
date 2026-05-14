#include<bits/stdc++.h>
using namespace std;
bool palindrome(int number){
    int ans=number;
    int revN=0;
    while(number>0){
        int lDigit=number%10;
        revN=(revN*10)+lDigit;
        number=number/10;
    }
    return ans==revN;
}

int main(){
    int mini=10;
    vector<int>ans;
    int maxi=50;
    for(mini=10;mini<=50;mini++){
        if(palindrome(mini)){
            ans.push_back(mini);
        }
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}