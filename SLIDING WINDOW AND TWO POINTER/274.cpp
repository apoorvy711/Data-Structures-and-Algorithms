#include <bits/stdc++.h>
using namespace std;

//BRUTE
int solve(string s){
    int maxi=INT_MIN;
    int n=s.size();
    for(int i=0;i<n;i++){
        unordered_set<int>st;
        for(int j=i;j<n;j++){
            if(st.find(s[j]) != st.end()){
                maxi=max(maxi,j-i);
                break;
            }
            st.insert(s[j]);
        }
    }
    return maxi;
}

int main(){
    string s="takeuforward";
    int ans=solve(s);
    cout<<"the longest non repeating character number is"<<ans;
    return 0;
}

//BETTER
int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r ) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}


//OPTIMAL
int solve(string s){
    if(s.size()==0)
      return 0;
    vector<int>mp(256,-1);
    int left=0;
    int right=0;
    int n=s.size();
    int maxlen=INT_MIN;
    while(right < n){
        if(mp[s[right]] !=-1){
            left=max(mp[s[right]],left);
        }
        mp[s[right]]=right;
        maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}