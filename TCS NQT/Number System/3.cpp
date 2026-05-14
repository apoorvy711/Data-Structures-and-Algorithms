#include<bits/stdc++.h>
using namespace std;
//Convert Decimal to Binary Number
int main(){
    string res="";
    int n=10;
    while(n>0){
        int rem=n%2;
        res +=(rem+'0');
        n=n/2;
    }
    reverse(res.begin(),res.end());
    cout<<res;
    return 0;
}