#include<bits/stdc++.h>
using namespace std;
/*
bool palindrome(int i,string s){
    if(i>s.size()/2) return true;
    return palindrome(i+1,s);
}
int main(){
    string s="madam";
    bool ans=palindrome(0,s);
    cout<<ans;
    return 0;
}


void countii(string s){
    int n=s.size();
    int vowel=0;
    int consonant=0;
    int spaces=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'){
            vowel++;
        }
        else if(s[i]>='a' && s[i]<='z'){
            consonant++;
        }
        else if(s[i]==' '){
            spaces++;
        }
    }
    cout<<vowel<<endl;
    cout<<consonant<<endl;
    cout<<spaces<<endl;
}

int main(){
    string s="i am appo don duniya ka papa";
    countii(s);
    return 0;
}



string countii(string &s){
    int n=s.size();
    int vowel=0;
    string ans="";
    for(int i=0;i<n;i++){
        if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'){
            continue;
        }
        ans+=s[i];
    }
    return ans;
}

int main(){
    string s="i am appo don duniya ka papa";
    string ans=countii(s);
    cout<<ans;
    return 0;
}

string countii(string &s){
    int n=s.size();
    int vowel=0;
    string ans="";
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            continue;
        }
        ans+=s[i];
    }
    return ans;
}

int main(){
    string s="i am appo don duniya ka papa";
    string ans=countii(s);
    cout<<ans;
    return 0;
}

string only_alpha(string s){
    int n=s.size();
    string res="";
    for(auto c:s){
        char lower=tolower(c);
        if(lower>='a' && lower<='z'){
            res+=lower;
        }
    }
    return res;
}

int main(){
    string s="abc@12De";
    string ans=only_alpha(s);
    cout<<ans;
}

string reverseee(string s){
    int n=s.size();
    int i=0;
    int r=n-1;
    while(i<r){
        swap(s[i],s[r]);
        i++;
        r--;
    }
    return s;
}

int main(){
    string s="ABCDE";
    string ans=reverseee(s);
    cout<<ans;
}
int num(string s){
    int n=s.size();
    int sum=0;
    for(auto x:s){
        if(x>='0' && x<='9'){
            sum+=x-'0';
        }
    }
    return sum;
}

int main(){
    string s="ABC23E0N1M1M2";
    int ans=num(s);
    cout<<ans;
    return 0;
}
string cap_small(string s){
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i-1]==' ' || i==0){
            s[i]=toupper(s[i]);
        }
        if(i==n-1 || s[i+1]==' '){
            s[i]=toupper(s[i]);
        }
    }
    return s;
}

int main(){
    string s="i hello mf yaar";
    string ans=cap_small(s);
    cout<<ans;
    return 0;
}

void count_freq(string s){
    int n=s.size();
    map<char,int>mpp;
    for(auto x:s){
        mpp[x]++;
    }
    for(auto it:mpp){
        cout<<it.first<<" - "<<it.second<<" "<<endl;
    }
}

int main(){
    string s="abcjjdksnabvqhrkce";
    count_freq(s);
}

void count_freq(string s){
    int n=s.size();
    map<char,int>mpp;
    for(auto x:s){
        mpp[x]++;
    }
    for(auto it:mpp){
        if(it.second==1){
            cout<<it.first<<" "<<endl;
        }
    }
}

int main(){
    string s="abcjjdksnabvqhrkce";
    count_freq(s);
}


bool anagramss(string s1,string s2){
    if(s1.size() != s2.size()) return false;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;

}
int main(){
    string s1="abcd";
    string s2="abdc";
    bool ans=anagramss(s1,s2);
    cout<<ans;
    return 0;
}

char max_char(string s){
    int maxi=INT_MIN;
    char maxchar='\0';
    map<char,int>mpp;
    for(auto x:s){
        mpp[x]++;
    }
    for(auto x:mpp){
        if(x.second > maxi){
            maxi=x.second;
            maxchar=x.first;
        }
    }
    return maxchar;
}

int main(){
    string s="aaanedcceaa";
    char ans=max_char(s);
    cout<<ans;
    return 0;
}

string dupli(string s){
    unordered_map<char,int>mpp;
    string res="";
    for(auto x:s){
        if(mpp.find(x)==mpp.end()){
            res+=x;
            mpp[x]=1;
        }
    }
    return res;
}

int main(){
    string s="aaccbed";
    string ans=dupli(s);
    cout<<ans;
    return 0;
}

string hihihi(string s1, string s2){
    unordered_map<char,bool>mpp;
    for(auto x:s2){
        mpp[x]++;
    }
    string res="";
    for(auto x:s1){
        if(!mpp[x]){
            res+=x;
        }
    }
    return res;
}

int main(){
    string s1="abcde";
    string s2="ae";
    string ans=hihihi(s1,s2);
    cout<<ans;
    return 0;
}

string lexico(string s){
    string res="";
    for(auto x:s){
        if(x=='z'){
            x='a';
        }
        else if(x=='Z'){
            x='A';
        }
        else if(isalpha(x)){
            x=x+1;
        }
        res+=x;
    }
    return res;
}

int main(){
    string s="abcde";
    string ans=lexico(s);
    cout<<ans;
    return 0;
}

string largestWord(string s){
    string largest="";
    string word="";
    for(int i=0;i<s.size();i++){
        if(s[i] != ' '){
            word+=s[i];
        }
        else{
            if(word.size() > largest.size()){
                largest=word;
            }
            word="";
        }
    }
    if(word.size() > largest.size()){
        largest=word;
    }
    return largest;
}

int main() {
    string s = "I love programming very much";
    string ans = largestWord(s);
    cout << "Largest word: " << ans;
    return 0;
}

void sortii_merge(string &s, int low,int mid, int high){
    int left=low;
    int right=mid+1;
    vector<char>temp;
    while(left<=mid && right <=high){
        if(s[left]<=s[right]){
            temp.push_back(s[left]);
            left++;
        }
        else{
            temp.push_back(s[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(s[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(s[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        s[i]=temp[i-low];
    }
}

void sortii(string &s, int low, int high){
    if(low>=high) return ;
    int mid=(low+high)/2;
    sortii(s,low,mid);
    sortii(s,mid+1,high);
    sortii_merge(s,low,mid,high);

}

int main(){
    string s="bdca";
    int n=s.size();
    sortii(s,0,n-1);
    cout<<s;
    return 0;
}

string maxRepeatingWord(string s){
    stringstream ss(s);
    string result="";
    string word;
    int maxrepeat=1;
    vector<char>freq(26,0);
    while(ss >> word){
        for(auto x:word){
            freq[x-'a']++;
        }
        int currmax=*max_element(freq.begin(),freq.end());
        if(currmax>maxrepeat){
            maxrepeat=currmax;
            result=word;
        }
    }
    return result;
}
int main() {
    string s = "today is a good day";
    cout << maxRepeatingWord(s);
}

int find_text(string text1,string text2){
    int ans= text1.find(text2);
    return ans;
}

int main() {
    string text1= "helloworld";
    string text2="world";
    int ans=find_text(text1,text2);
    cout<<ans;
}

string reversee(string s){
    stringstream ss(s);
    string res="";
    stack<string>st;
    string word;
    while(ss >> word){
        st.push(word);
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    res.pop_back();
    return res;
}

int main(){
    string s="hi im appo daddy";
    string ans=reversee(s);
    for(auto x:ans){
        cout<<x;
    }
    return 0;
}
vector<int>reversee(vector<int>&arr){
    int n=arr.size();
    int i=0;
    int r=n-1;
    while(i<r){
        swap(arr[i],arr[r]);
        i++;
        r--;
    }
    return arr;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    vector<int>ans=reversee(arr);
    for(auto x:ans){
        cout<<x;
    }
    return 0;
}
vector<int>dupli(vector<int>&arr){
    int n=arr.size();
    unordered_map<int,int>mpp;
    vector<int>res;
    for(auto x:arr){
        mpp[x]++;
    }
    for(auto x:mpp){
        if(x.second ==1){
            res.push_back(x.first);
        }
    }
    return res;
}

int main(){
    vector<int>arr={1,1,2,3,4,5,5};
    vector<int>ans=dupli(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

int max_prod(vector<int>arr){
    int pre=1;
    int suff=1;
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre*=arr[i];
        suff*=arr[n-i-1];
        ans=max(ans,max(pre,suff));
    }
    return ans;
}

int main(){
    vector<int>arr={1,0,2,3,-4,-5};
    int ans=max_prod(arr);
    cout<<ans;
    return 0;
}

vector<int>replace_byrank(vector<int>arr){
    int rank=1;
    vector<int>sortedArr=arr;
    vector<int>res;
    unordered_map<int,int>mpp;
    sort(sortedArr.begin(),sortedArr.end());
    for(auto x:sortedArr){
        if(mpp.find(x)==mpp.end()){
            mpp[x]=rank;
            rank++;
        }
    }
    for(auto x:arr){
        res.push_back(mpp[x]);
    }
    return res;
}

int main(){
    vector<int>arr={5,2,1,3,4};
    vector<int>ans=replace_byrank(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

int equilibriumIndex(vector<int> nums){
    int n=nums.size();
    int total=0;
    for(auto x:nums){
        total+=x;
    }
    int left=0;
    for(int i=0;i<n;i++){
        int right=total-left-nums[i];
        if(left==right){
            return i;
        }
        left+=nums[i];
    }
    return -1;
}

int main(){
    vector<int> nums = {1, 3, 5, 2, 2};
    cout << equilibriumIndex(nums);
}

vector<int>relativeSort(vector<int>A,vector<int>B){
    unordered_map<int,int>freq;
    vector<int>res;
    for(auto x:A){
        freq[x]++;
    }
    for(auto x:B){
        while(freq[x]>0){
            res.push_back(x);
            freq[x]--;
        }
    }
    vector<int>ans;
    for(auto x:freq){
        while(x.second>0){
            ans.push_back(x.first);
            x.second--;
        }
    }
    sort(ans.begin(),ans.end());
    res.insert(res.end(),ans.begin(),ans.end());
    return res;
}

int main(){
    vector<int>A={2,1,2,5,7,1,9,3,6,8,8};
    vector<int>B={2,1,8,3};
    vector<int>ans=relativeSort(A, B);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

bool present(vector<int>arr2,int n, int h){
    int low=0;
    int high=n-1;
    while(low<high){
        int mid=(low+high)/2;
        if(arr2[mid]==h){
            return true;
        }
        else if(arr2[mid]>h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
}

bool isSubset(vector<int>arr1, int n,vector<int>arr2 , int m){
    if(n>m) return false;
    for(int i=0;i<m;i++){
        bool ans=present(arr2,n,arr1[i]);
    }
    if(present==false) return false;
    return true;
}
int main(){
    vector<int>arr1={1,3,4,5,2};
    vector<int>arr2{2,4,3,1,7,5,15};
    int n=arr1.size();
    int m=arr2.size();
    bool ans=isSubset(arr1,n,arr2,m);
    if(ans==true) cout<<"yes";
    else cout<<"NO";
    return 0;
}
void factorss(int n){
    vector<int>ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            if(i != n/i){
                ans.push_back(n/i);
            }
        }
    }
    for(int x:ans){
        cout<<x<<" ";
    }
} 
int main(){
    int n=36;
    factorss(n);
    return 0;
}
vector<int>bubble_sort(vector<int>arr){
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return arr;
}
int main(){
    vector<int>arr={3,2,1,4,5};
    vector<int>ans=bubble_sort(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
vector<int>selection_sort(vector<int>arr){
    int n=arr.size();
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
    return arr;
}
int main(){
    vector<int>arr={3,2,1,4,5};
    vector<int>ans=selection_sort(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
vector<int>insertion_sort(vector<int>arr){
    int n=arr.size();
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
    return arr;
}
int main(){
    vector<int>arr={3,2,1,4,5};
    vector<int>ans=insertion_sort(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
int partition(vector<int>arr, int low,int n){
    int pivot=arr[low];
    int j=n;
    int i=low;
    while(i<j){
        while(arr[i]<=pivot && i<=n-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int>arr, int low,int n ){
    if(low<n) {
        int Pindex=partition(arr,low,n);
        qs(arr,low,Pindex-1);
        qs(arr,Pindex+1,n);
    }
}
int main(){
    vector<int>arr={3,2,1,4,5};
    int n=arr.size();
    qs(arr,0,n);
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}

void merge(vector<int>&arr, int l,int mid, int h){
    int n=arr.size();
    int left=l;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=h){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=h){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
}

void merge_sort(vector<int>&arr, int l, int h){
    if(l>=h) return ;
    int mid=(l+h)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,h);
    merge(arr,l,mid,h);
}

int main(){
    vector<int>arr={3,2,4,1,5};
    int n=arr.size();
    merge_sort(arr,0,n-1);
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}

*/