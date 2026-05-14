#include <bits/stdc++.h>
using namespace std;

//BRUTE
int func(string s){
    int n=s.size();
    int count=0;
    for(int i=0;i<n;i++){
        int hash[3]={0,0,0};
        for(int j=i;j<n;j++){
            hash[s[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                count++;
            }
        }
    }
    return count;
}

int main(){
    string s="bbacba";
    int ans=func(s);
    cout<<"the number of strings are "<<ans;
    return 0;
}

//BETTER
int func(string s){
    int n=s.size();
    int count=0;
    for(int i=0;i<n;i++){
        int hash[3]={0,0,0};
        for(int j=i;j<n;j++){
            hash[s[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                count=count+(n-j);
                break;
            }
        }
    }
    return count;
}

int main(){
    string s="bbacba";
    int ans=func(s);
    cout<<"the number of strings are "<<ans;
    return 0;
}

//OPTIMAL
int func(string s){
    int n=s.size();
    int lastseen[3]={-1,-1,-1};
    int count=0;
    for(int i=0;i<n;i++){
        lastseen[s[i]-'a']=i;
        if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
            count=count+1+min({lastseen[0],lastseen[1],lastseen[2]});
        }
    }
    return count++;
}

int main(){
    string s="bbacba";
    int ans=func(s);
    cout<<"the number of strings are "<<ans;
    return 0;
}




