#include<bits/stdc++.h>
using namespace std;

void harshad(int n){
    int num=n;
    int sum=0;
    while(n>0){
        int w=n%10;
        sum=sum+w;
        n=n/10;
    }
    if(sum !=0 && num%sum==0){
        cout<<" a harshad number";
    }
    else{
        cout<<"not a harshad number";
    }
}

int main(){
    int n=378;
    harshad(n);
    return 0;
}