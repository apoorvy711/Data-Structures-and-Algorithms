#include <bits/stdc++.h>
using namespace std;

string concatee(string &str1,string &str2){
  str1=str1+str2;
  return str1;
}


int main() {
  string str1 = "Hello";
  string str2 = "World";
  string ans=concatee(str1,str2);
  cout << str1;
  return 0;
}