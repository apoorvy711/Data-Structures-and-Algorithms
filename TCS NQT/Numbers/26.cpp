#include<bits/stdc++.h>
using namespace std;

void abundant(int n){
    int sum=0;
    int num=n;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i == n/i){
                sum+=i;
            }
            else{
                sum +=i;
                sum +=n/i;
            }
        }
    }
    sum -=n;
    if (sum > n) {
        cout << "Abundant Number" << "\n";
    }
    else {
        cout << "Not Abundant Number" << "\n";
    }
}

int main(){
    int n=18;
    abundant(n);
    return 0;
}