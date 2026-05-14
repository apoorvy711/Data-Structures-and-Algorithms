#include <bits/stdc++.h>
using namespace std;
/*
//BRUTE
int func(string s,int k){
    int maxLEN=INT_MIN;
    int n=s.size();
    for(int i=0;i<n;i++){
        int hash[26]={0};
        
        int maxFREQ=0;
        for(int j=i;j<n;j++){
            hash[s[j]-'A']++;
            maxFREQ=max(maxFREQ,hash[s[j]-'A']);
            int changes=(j-i+1)-maxFREQ;

            if(changes<=k){
                maxLEN=max(maxLEN,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxLEN;
}

int main(){
    string s="AABABBA";
    int k=2;
    int ans=func(s,k);
    cout<<"the longest repeating character replacement is "<<ans;
    return 0;
}

*/

int func(string s,int k){
    int n=s.size();
    int l=0;
    int r=0;
    int maxLEN=0;
    int max_freq=0;
    int hash[26]={0};
    while(r<n){
        hash[s[r]-'A']++;

        max_freq=max(max_freq,hash[s[r]-'A']);

        while((r-l+1)- max_freq>k){
            hash[s[l]-'A']--;
            max_freq=0;
            for(int i=0;i<25;i++){
                max_freq=max(max_freq,hash[i]);
                l++;
            }
        }
        if((r-l+1)-max_freq <k){
            maxLEN=max(maxLEN,r-l+1);
        }
        r++;
    }
    return maxLEN;
}

int main(){
    string s="AABABBA";
    int k=2;
    int ans=func(s,k);
    cout<<"the longest repeating character replacement is "<<ans;
    return 0;
}

//OPTIMAL
#include <bits/stdc++.h>
using namespace std;

int func(string s, int k) {
    int n = s.size();
    int l = 0, r = 0;
    int maxLEN = 0;
    int max_freq = 0;
    int hash[26] = {0};

    while (r < n) {
        hash[s[r] - 'A']++;
        max_freq = max(max_freq, hash[s[r] - 'A']);

        // If the current window is invalid, shrink it
        if ((r - l + 1) - max_freq > k) {
            hash[s[l] - 'A']--;
            l++;
        }

        maxLEN = max(maxLEN, r - l + 1);
        r++;
    }
    return maxLEN;
}

int main() {
    string s = "AABABBA";
    int k = 2;
    int ans = func(s, k);
    cout << "The longest repeating character replacement is " << ans;
    return 0;
}


