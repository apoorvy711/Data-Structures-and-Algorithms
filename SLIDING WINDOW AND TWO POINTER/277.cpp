#include <bits/stdc++.h>
using namespace std;

//BETTER
int longestSubstringKDistinct(string s, int k) {
    int left = 0, right = 0;
    int n = s.size();
    unordered_map<char, int> freq;
    int maxLen = 0;

    while (right < n) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}

int main() {
    string s = "aaabbccd";
    int k = 2;
    cout << "The length of the longest substring with at most " << k << " distinct characters is "
         << longestSubstringKDistinct(s, k);
    return 0;
}

//OPTIMAL
int longestSubstringKDistinct(string s, int k) {
    int left = 0, right = 0;
    int n = s.size();
    unordered_map<char, int> freq;
    int maxLen = 0;

    while (right < n) {
        freq[s[right]]++;

        if(freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}

int main() {
    string s = "aaabbccd";
    int k = 2;
    cout << "The length of the longest substring with at most " << k << " distinct characters is "
         << longestSubstringKDistinct(s, k);
    return 0;
}