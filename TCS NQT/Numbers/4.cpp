#include<bits/stdc++.h>
using namespace std;
bool isarmstrong(int number){
    int sum=0;
    int k=to_string(number).length();
    int n=number;
    while(n>0){
        int w=n%10;
        sum=sum+pow(w,k);
        n=n/10;
    }
    return sum==number;
}

int main(){
    int number=371;
    if(isarmstrong(number)){
        cout<<number<<"is a armstrong number"<<endl;
    }
    else {
        cout<<number<<"is not an armstrong number"<<endl;
    }
    return 0;
}