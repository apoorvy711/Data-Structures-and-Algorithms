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

int main() {
    int number = 4574; 
    if (palindrome(number)) { 
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }
    return 0;
}