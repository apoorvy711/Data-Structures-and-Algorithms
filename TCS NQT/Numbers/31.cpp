#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cnt++;
        }
    }
    return cnt == 2;
}
bool prime(int n){
    return isPrime(n) && isPrime(n-2);
}

int main(){
    int n = 19;
    if(prime(n)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}