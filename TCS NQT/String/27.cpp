#include <iostream>
using namespace std;

int find_text(string &text1, string &text2){
    int ans=text1.find(text2);
    return ans;
}

int main() {
    string text1= "hello world";
    string text2="world";
    int ans=find_text(text1,text2);
    cout<<ans;
}