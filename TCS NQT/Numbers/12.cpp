#include<bits/stdc++.h>
using namespace std;

int main(){
    float a=2.3;
    float b=4.5;
    float c=5;

    if(a>b && a>c){
        cout<<"the greatest of two no is "<<a<<endl;
    }
    else if(b>a && b>c) {
       cout<<"the greatest of two no is "<<b<<endl; 
    }
    else{
        cout<<"the greatest of two no is "<<c<<endl;
    }
    return 0;
}