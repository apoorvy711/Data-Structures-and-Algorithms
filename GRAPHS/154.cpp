#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:

    int wordladderlength(string startWord,string lastWord,vector<string>&wordList){
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({startWord,1});

        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==lastWord) return steps;

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a'; ch <='z';ch++){
                    word[i]=ch;
                    if(st.find(word) !=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};

int main(){
    vector<string>wordList={"hot","dot","dog","lot","log","cog"};
    string startWord="hit";
    string lastWord="cog";
    Solution obj;
    int ans=obj.wordladderlength(startWord,lastWord,wordList);
    cout<<"the length is "<<ans;
    cout<<endl;
    return 0;
}