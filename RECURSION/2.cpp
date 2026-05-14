#include<bits/stdc++.h>
using namespace std;

//print names
void f(int i,int n){
    if(i>n)
    return;
    cout<<"AY";
    f(i+1,n);
}
int main(){
    int n;
    cin>>n;
    f(1,5);
    return 0;
}



//PRINT 1---N
void f(int i,int n){
    if(i>n)
    return;
cout<<i;
f(i+1,n);
}
int main(){
    int n;
    cin>>n;
    f(1,n);
    return 0;
}


 //PRINT N--1
void f(int i,int n){
    if(i<1)
    return;
cout<<i;
f(i-1,n);
}
int main(){
    int n;
    cin>>n;
    f(n,n);
    return 0;
}

//CALL NAME
void fname(int i,int n){
    if(i>n){
        return ;
    }
    cout<<"the name is apoorv"<<endl;
    fname(i+1,n);
}
int main(){
    int n;
    cin>>n;
    cout<<"entr number"<<n<<endl;
    fname(1,n);
    return 0;
    
}
//CALL NUM
void fnum(int i,int n){
    if(i>n){
        return ;
    }
    cout<<"the number is"<<i<<endl;
    fnum(i+1,n);
}
int main(){
    int n;
    cin>>n;
    cout<<"entr number"<<n<<endl;
    fnum(1,n);
    return 0;
    
}


void fnum(int i,int n){
    if(i<1){
        return ;
    }
    cout<<"the number is"<<i<<endl;
    fnum(i-1,n);
}
int main(){
    int n;
    cin>>n;
    cout<<"entr number"<<n<<endl;
    fnum(n,n);
    return 0;
    
}
