#include<bits/stdc++.h>
using namespace std;

//palindrome number
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int revNum=0;
    int dup=n;
    while(n>0){
        int id=n%10;
        revNum=(revNum*10)+id;
        n=n/10;
    }
    if(revNum==dup){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false";
    }
return 0;    
}

//COUNT DIGITS
//Normal Approach
int count_digits(int n){
    int cnt=0;
    while(n > 0){
        cnt++;
        n=n/10;
    }
    return cnt;
}

//Optimal Approach
int count_digits(int n){
    int cnt=(int)(log10(n)+1);
    return cnt;
} 

int main(){
    int n=125467875;
    cout<<"N :" <<n;
    int digits=count_digits(n);
    cout<<"the number of digits are :"<<digits<<endl;
    return 0;
}

//Reverse a number
int revNum(int n){
    int Num=0;
    while(n>0){
        int w=n%10;
        n=n/10;
        Num=(Num*10) + w;
    }
    return Num;
}

int main(){
    int n=9875;
    cout<<"the number is"<<n;
    cout<<endl;
    int ans=revNum(n);
    cout<<"the reversed number is"<<ans;
    return 0;
}

//Palindrome number
bool palindrome(int n){
    int revNum=0;
    int dup=n;
    while(n>0){
        int w=n%10;
        n=n/10;
        revNum= ( revNum * 10 ) + w;
    }
    if(dup == revNum){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int number=131;
    if(palindrome(number)){
        cout<<number<<" is a palindrome "<<endl;
    }
    else {
        cout<<number<<" is not a palindrome"<<endl;
    }
    return 0;
}

//GCD 
int gcd_num(int a,int b){

    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }
        else {
            b=b%a;
        }
    }
    if(a==0){
        return b;
    }
    return a;
}

int main(){
    int n1=20, n2=15;
    int gcd=gcd_num(n1,n2);
    cout<<"the gcd of "<<n1<<" and "<<n2<<" is :"<<gcd<<endl;
    return 0;

}
 
//Armstrong number
bool isarmstrong(int num){
    int sum=0;
    int k=to_string(num).length();
    int n=num;
    while(n>0){
        int w=n%10;
        sum +=pow(w,k);
        n=n/10;
    }
    return sum==num ;
}

int main(){
    int number=371;
    if(isarmstrong(number)){
        cout<<number<<" is a armstrong number"<<endl;
    }
    else {
        cout<<number<<" is not an armstrong number"<<endl;
    }
    return 0;
}

//Prime number
bool prime_num(int num){
    int cnt=0;
    for(int i=1;i<=num;i++){
        if(num%i == 0){
            cnt=cnt+1;
        }
    }
    if( cnt ==2){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int num=13;
    bool isprime= prime_num(num);
    if(isprime){
        cout<<num<<"is a prime number"<<endl;
    }
    else {
        cout<<num<<"is not a prime number"<<endl;
    }
    return 0;
}

//Print all Divisors of a given Number
vector<int> divisors(int num){
    vector<int>divi;
    int sqrnN=sqrt(num);
    for(int i=1;i<=sqrnN;i++){
        if(num%i==0){
            divi.push_back(i);

            if(i !=num/i){
                divi.push_back(num/i);
            }
        }
    }
    return divi;
}

int  main(){
    int num=12;
    vector<int> DIVISORS=divisors(num);
    cout<<"the divisors are:"<<num<<endl;
    for(int DIv:DIVISORS){
        cout<<DIv<<" "<<endl;
    }
    return 0;
    
}