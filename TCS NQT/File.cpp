#include<bits/stdc++.h>
using namespace std;
int print1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int print2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i ;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int print3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i ;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
int print4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i ;j++){
            cout<<i;
        }
        cout<<endl;
    }
}
int print5(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<(n-i+1) ;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
int print6(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n-i+1) ;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
int print7(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-i-1) ;j++){
            cout<<" ";
        }
        for(int j=0;j<(2*i+1);j++){
            cout<<"*";
        }
        for(int j=0;j<(n-i-1) ;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
int print8(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i ;j++){
            cout<<" ";
        }
        for(int j=0;j<(2*n)-(2*i+1);j++){
            cout<<"*";
        }
        for(int j=0;j<i ;j++){
            cout<<" ";
        }
        cout<< endl;
    }
}
int print9(int n){
    for(int i=1;i<=(2*n-1);i++){
        int stars =i;
        if(i>n){
            stars =2*n-i;
        }
        for(int j=1;j<=stars;j++){
            cout<<"*";
        }
        cout<< endl;
    }
}
int print11(int n){
    for(int i=0;i<n;i++){
        int start=1;
        if(i%2==0){
            start=1;
        }
        else{
            start=0;
        }
        for(int j=0;j<=i;j++){
            cout<<start;
            start=1-start;
        }
        cout<<endl;

    }
}
int print12(int n){
    int space=(2*(n-1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int j=1;j<=(2*(n-1));j++){
            cout<<" ";
        }

        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
        space -= 2;
    }
}
int print13(int n){
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<num<<" ";
            num=num+1;
        }
        cout<<endl;

    }
}
int print14(int n){
      for(int i=0;i<n;i++){
        for(char ch = 'A'; ch<='A'+i;ch++){
            cout<<ch<<" ";   
        }
        cout<<endl;

    }
}
int print15(int n){
      for(int i=0;i<n;i++){
        for(char ch = 'A'; ch<='A'+(n-i-1);ch++){
            cout<<ch<<" ";     
        }
        cout<<endl;
    }
}
int print19(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        for (int j = 0; j < 2 * (n - i); j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
int print19_1(int n){
   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=0;j<2*n-(2*i);j++){
            cout<<" ";
        }

        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    print19(n);
    print19_1(n);
}