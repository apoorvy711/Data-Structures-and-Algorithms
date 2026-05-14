#include<bits/stdc++.h>
using namespace std;
//PARAMETERIZED WAY
/* 
void f(int i ,int sum){
    if(i<1){
     cout<<sum<<endl;   
     return;
    }
   f(i-1,sum+i);
}
int main(){
   int n;
   cin>>n;
   f(n,0);
   return 0;
}
*/
//FUNCTIONAL RECURSION
/*
int sum(int n){
    if(n==0)
    return 0;    
    return n+sum(n-1);
    }

int main(){
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
    return 0;
}

//FACTORIAL RECURSION
int fact(int n){
    if(n==0 || n==1)
    return 1;    
    return n*fact(n-1);
    }

int main(){
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}

*/

  