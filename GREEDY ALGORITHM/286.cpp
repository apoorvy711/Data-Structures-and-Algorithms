#include <bits/stdc++.h>
using namespace std;

bool changeL(vector<int>&bills){
    int five=0;
    int ten=0;
    int n=bills.size();
    for(int i=0;i<n;i++){
        if(bills[i]==5){
            five+=1;
        }
        else if(bills[i]==10){
            if(five){
                ten=ten+1;
                five=five-1;
            }
            else return false;
        }
        else{
            if(five >=1 && ten >=1){
                five=five-1;
                ten=ten-1;
            }
            else if(five >=3){
                five -=3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int>bills={5,5,10,10,20};
    bool ans=changeL(bills);
    if(ans){
        cout<<"TRUE";
    }
    else{
        cout<<"FALSE";
    }
    return 0;
}