#include<bits/stdc++.h>
using namespace std;

int main(){
    int year=2000;
    if(((year%4==0) && (year%100!=0)) ||  (year%400 == 0)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO";
    }
    return 0;
}