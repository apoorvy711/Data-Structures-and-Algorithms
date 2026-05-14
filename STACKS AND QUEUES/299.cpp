#include<bits/stdc++.h>
using namespace std;

//INFIX TO POSTFIX
int priority(char s){
    if(s=='^') return 3;
    else if(s=='/' || s=='*') return 2;
    else if(s=='+' || s=='-') return 1;
    else return -1;
}

string infTOpost(string exp){
    stack<char>st;
    int i=0;
    string ans="";
    int n=exp.length();

    for(i=0;i<n;i++){
        char s=exp[i];
        if(( s >='A' && s<='Z') || ( s >='a' && s<='z') || ( s >='0' && s<='9')){
            ans+=s;
        }
        else if(s=='('){
            st.push('(');
        }
        else if(s==')'){
            while(! st.empty() && st.top() !='('){
                ans+=st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && priority(s)<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string exp="a+b*(c^d-e)";
    cout<<"infix expression is "<<exp<<endl;
    string ans=infTOpost(exp);
    cout<<"postfix expression is "<<ans<<endl;
    return 0;
}

//INFIX TO PREFIX
int priority(char s) {
    if (s == '^') return 3;
    else if (s == '/' || s == '*') return 2;
    else if (s == '+' || s == '-') return 1;
    else return -1;
}

string infixToPrefix(string exp) {
    reverse(exp.begin(),exp.end());
    for(char &it:exp){
        if(it=='(') it=')';
        else if(it==')') it='(';
    }

    stack<char>st;
    string ans="";
    int n=exp.length();
    for(int i=0;i<n;i++){
        char s=exp[i];
        if((s>='A' && s<='Z') || (s>='a' && s<='z') || (s>='0' && s<='9')){
            ans +=s;
        }
        else if(s=='('){
            st.push('(');
        }
        else if(s==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) {
                st.pop();
            }
        }
        else{
            while(!st.empty() && priority(s)<priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;

}

int main() {
    string exp = "(A+B)*C-D+F";
    cout << "Infix expression is " << exp << endl;
    string ans = infixToPrefix(exp);
    cout << "Prefix expression is " << ans << endl;
    return 0;
}

//POSTFIX TO INFIX
bool isOperator(char s) {
    return s == '*' || s == '+' || s == '-' || s == '/';
}

string PostfixToinfix(string exp) {
    stack<string> st;
    int n = exp.length();
    
    for (int i = 0; i < n; i++) {
        char s = exp[i];
        
        if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')) {
            st.push(string(1, s));  // convert char to string and push
        }
        else if (isOperator(s)) {
            string op2 = st.top(); st.pop(); // right operand
            string op1 = st.top(); st.pop(); // left operand
            string newExp = "(" + op1 + s + op2 + ")";
            st.push(newExp); // push the combined expression
        }
    }
    
    return st.top();
}
 
int main() {
    string exp = "AB-DE+F*/";
    cout << "Postfix expression is " << exp << endl;
    string ans =PostfixToinfix(exp);
    cout<<"Infix expression is " << ans << endl;
    return 0;
}

//PREFIX TO  INFIX
bool isOperator(char s) {
    return s == '*' || s == '+' || s == '-' || s == '/';
}

string PrefixToInfix(string exp) {
    stack<string> st;
    int n = exp.length();
    
    for (int i = n-1; i >= 0; i--) {
        char s = exp[i];
        
        if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')) {
            st.push(string(1, s));  // convert char to string and push
        }
        else if (isOperator(s)) {
            string op1 = st.top(); st.pop(); // right operand
            string op2 = st.top(); st.pop(); // left operand
            string newExp = "(" + op1 + s + op2 + ")";
            st.push(newExp); // push the combined expression
        }
    }
    
    return st.top();
}

int main(){
    string exp = "*+PQ-MN";
    cout << "Infix expression is " << exp << endl;
    string ans = PrefixToInfix(exp);
    cout << "Prefix expression is " << ans << endl;
    return 0;

}

//POSTFIX TO PREFIX
bool isOperator(char s) {
    return s == '*' || s == '+' || s == '-' || s == '/';
}

string  PostfixToPrefix(string exp) {
    stack<string> st;
    int n = exp.length();
    
    for (int i = 0; i < n; i++) {
        char s = exp[i];
        
        if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')) {
            st.push(string(1, s));  // convert char to string and push
        }
        else if (isOperator(s)) {
            string op2 = st.top(); st.pop(); // right operand
            string op1 = st.top(); st.pop(); // left operand
            string newExp =  s + op1  + op2 ;
            st.push(newExp); // push the combined expression
        }
    }
    
    return st.top();
}

int main(){
    string exp = "AB-DE+F*/";
    cout << "Postix expression is " << exp << endl;
    string ans = PostfixToPrefix(exp);
    cout << "Prefix expression is " << ans << endl;
    return 0;
}

//PREFIX TO POSTFIX
bool isOperator(char s) {
    return s == '*' || s == '+' || s == '-' || s == '/';
}

string  PostfixtoPrefix(string exp) {
    stack<string> st;
    int n = exp.length();
    
    for (int i =n-1; i >=0 ; i--) {
        char s = exp[i];
        
        if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')) {
            st.push(string(1, s));  // convert char to string and push
        }
        else if (isOperator(s)) {
            string op2 = st.top(); st.pop(); // right operand
            string op1 = st.top(); st.pop(); // left operand
            string newExp =  op2  + op1 + s ;
            st.push(newExp); // push the combined expression
        }
    }
    
    return st.top();
}

int main(){
    string exp = "/-AB*+DEF";
    cout << "Infix expression is " << exp << endl;
    string ans = PostfixtoPrefix(exp);
    cout << "Prefix expression is " << ans << endl;
    return 0;

}