#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string largest_odd_number_string_words(string s){
        int n=s.length();
        for(int i=n;i>=0;i--){
            if((s[i]-'0') % 2 !=0){
                return s.substr(0,i+1);
            }
        }
        return "";
    }
};

int main(){
    Solution solution;

    string s;
    cout<<"enter the string:";
    cin>>s;

    string output=solution.largest_odd_number_string_words(s);
    cout<<"after the string:"<<output<<endl;
    return 0;
}