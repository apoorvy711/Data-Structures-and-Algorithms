#include<bits/stdc++.h>
using namespace std;

void max_min_digit(int n){
    int maxi=0;
    int mini=9;
    while(n>0){
        int digit=n%10;
        if(digit>maxi) maxi=digit;
        if(digit<mini) mini=digit;
        n=n/10;
    }
    cout<<"the maximum number is"<<maxi<<endl;
    cout<<"the minimum number is"<<mini<<endl;
}

int main(){
    int n=1345;
    max_min_digit(n);
    return 0;
} 