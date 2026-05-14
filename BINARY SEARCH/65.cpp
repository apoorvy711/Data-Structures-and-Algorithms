#include<bits/stdc++.h>
using namespace std;
//Median of Two Sorted Arrays of different sizes
//BRUTE
int median(vector<int> &a,vector<int> &b){
    int n1=a.size();
    int n2=b.size();
    int n=n1+n2;
    int i=0,j=0;
    vector<int> arr3;
    while( i < n1 && j < n2 ){
        if(a[i]<b[j]) {
            arr3.push_back(a[i++]);
        }
        else{
            arr3.push_back(b[j++]);
        }
    }

    while(i<n1) arr3.push_back(a[i++]);
    while(j<n2) arr3.push_back(b[j++]);

    if (n % 2 == 1) {
        return arr3[n / 2];  // Odd length
    } else {
        return (arr3[n / 2] + arr3[(n / 2) - 1]) / 2.0;  // Even length
    }
}
int main(){
    vector<int> a={ 1, 4, 7, 10, 12};
    vector<int> b={ 2, 3, 6, 15};
    cout<<"the median of the arrays is "<<median(a,b)<<endl;
    return 0;
}