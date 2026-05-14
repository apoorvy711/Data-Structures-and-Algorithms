#include<bits/stdc++.h>
using namespace std;

bool isPerfect(int number){
    int sum=1;
    for(int i=2;i*i<=number;i++){
        if(number%i==0){
            sum=sum+i;
            if(i != number/i){
                sum+=number/i;
            }
        }
    }
    return number==sum;
}

int main(){
    int number = 6;
    if(isPerfect(number))
        cout << number << " is Perfect";
    else
        cout << number << " is not Perfect";
}