#include<bits/stdc++.h>
using namespace std;

//R TO I
int romanTOintegers(string &s){
    unordered_map<char,int>roman={ {'V',5},{'X',10},{'D', 500},{'I',1},{'M',1000},{'L',50},{'C',100}};
    int result=0;

    for(int i=0;i<s.length();i++){
        if(i+1 < s.length() && roman[s[i]] < roman[s[i+1]] ){
            result -=roman[s[i]];
        }
        else{
            result+=roman[s[i]];
        }
    }
    return result;
}

int main(){
    string s="MCMXCIV";
    int result=romanTOintegers(s);
    cout<<"the number is "<<result;
    return 0;
}

//IN TO R
string intTOroman(int num){
    vector<pair<int,string>>roman={
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
        {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"}, {1, "I"}
    };
    string res="";

    for(auto & pairs:roman){
        if(num>=pairs.first){
            res += pairs.second;
            num -= pairs.first;
        }
    }
    return res;

}

int main(){
    int num=1994;
    string result=intTOroman(num);
    cout<<"the roman number is"<<result;
    return 0;
}