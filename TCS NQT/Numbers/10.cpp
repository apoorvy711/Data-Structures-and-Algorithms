#include<bits/stdc++.h>
using namespace std;

double gp_sum(double a, double r, int n){
    if (r==1) return a*n;
    return a*(pow(r,n)-1)/(r-1);
}
int main(){
    double a=3;
    double r=5;
    int n=2;
    double result=gp_sum(a,r,n);
    cout<<result<<" ";
    return 0;
}