#include<bits/stdc++.h>
using namespace std;

//LONGEST COMMON PREFIX
string longestCommonPrefix(string strs[], int n){
    string ans="";
    for(int i=0;i<n;i++){
        char ch=strs[0][i];
        for(int j=1;j<n;j++){
            if(i >= strs[j].size() || strs[j][i] !=ch){
                return ans;
            }
        }
        ans+=ch;
    }
    return ans;
}

int main(){
    string strs[]={"flower","flow","flight"};
    int n=3;
    cout<<longestCommonPrefix(strs,n);
    return 0;
}
/*
//LONGEST NON REEATING SUBSTRING 
int longestSubstring(string s){
    unordered_set<char>st;
    int maxlen=0;
    int right=0;
    int left=0;
    while(right<s.size()){
        if(st.find(s[right])==st.end()){
            st.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        else{
            st.erase(s[left]);
            left++;
        }
    }
    return maxlen;
}
int main(){
    string s = "abcabcbb";
    cout << longestSubstring(s);
    return 0;
}

//SHORTEN THE STRING
string compress(string s){
    string ans="";
    int cnt=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            cnt++;
        }
        else{
            ans+=s[i-1];
            ans+=to_string(cnt);
            cnt=1;
        }
    }
    ans+=s[s.size()-1];
    ans+=to_string(cnt);
    if(ans.size() < s.size()){
        return ans;
    }
    return s;
}
int main(){
    string s = "aabbcccccaaa";
    cout << compress(s);
    return 0;
}


//LONBGEST PALINDROMIC STRING
bool isPalindrome(string sub){
    int l=0;
    int r=sub.size()-1;
    while(l<r){
        if(sub[l]!=sub[r]) return false;
        l++;
        r--;
    }
    return true;
}

string longestpalindromestring(string s){
    string ans="";
    int n=s.size()-1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string sub=s.substr(i,j-i+1);
            if(isPalindrome(sub) && sub.size()>ans.size()){
                ans=sub;
            }
        }
    }
    return ans;
}

int main(){
    string s="babad";
    string ans=longestpalindromestring(s);
    cout<<ans;
    return 0;
}

//ONE ROTATION OF OTHER STRING
bool isRotation(string s1, string s2){
    if(s1.size() !=s2.size()) return false;
    string temp =s1 + s1;
    return temp.find(s2) != string :: npos;
}

int main(){
    string s1="abcde";
    string s2="cdeab";
    if(isRotation(s1,s2)){
        cout<<"TRUE";
    }
    else{
        cout<<"FALSE";
    }
    return 0;
}

//FIND ALL PERMUTATIONS OF A STRING
void permute(string s,int l,int r,vector<string>&ans){
    if(l==r){
        ans.push_back(s);
        return;
    }
    for(int i=l;i<=r;i++){
        swap(s[l],s[i]);
        permute(s,l+1,r,ans);
        swap(s[l],s[i]);
    }
}

int main(){
    string s="ABC";
    int n=s.size()-1;
    vector<string>ans;
    permute(s,0,n,ans);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

*/

//