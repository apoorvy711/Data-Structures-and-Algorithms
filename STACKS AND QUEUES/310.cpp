#include <bits/stdc++.h>
using namespace std;

string func(string &num,int k){
    stack<int>st;
    for(int digit:num){
        while(!st.empty() && k>0 && st.top()>digit){
            st.pop();
            k--;
        }
        st.push(digit);
    }
    while(!st.empty() && k>0){
        st.pop();
        k--;
    }
    string res="";
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(),res.end());
    int i=0;
    while(i<res.size() && res[i]=='0'){
        i++;
    }
    res=res.substr(i);

    return res.empty()?"0":res;

}

int main(){
    string num="1432219";
    int k=3;
    string ans=func(num,k);
    cout<<"the left string is "<<ans<<endl;
    return 0;
}