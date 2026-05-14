#include<bits/stdc++.h>
using namespace std;
/*
//COUNT FREQUENCY OF EACH ELEMNT
void freq(vector<int>arr){
    int n=arr.size();
    unordered_map<int,int>mpp;
    for(auto x:arr){
        mpp[x]++;
    }
    for(auto it:mpp){
        if(it.second!=0){
            cout<<it.first<<"-"<<it.second<<endl;
        }
    }
}

int main(){
    vector<int>arr={2,3,3,5,1,3,7,8,3};
    freq(arr);
    return 0;
}



int remove_duplicates(vector<int>&arr){
    int n=arr.size();
    vector<int>res;
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            i++;
            arr[i]=arr[j];
        }
    } 
    return i+1;
}    

int main(){
    vector<int>arr={1,1,2,2,3,4,5,5,5};
    int ans=remove_duplicates(arr);
    for(int i=0;i<ans;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

vector<int>un_duplicates(vector<int>arr){
    unordered_map<int,bool>mpp;
    vector<int>res;
    for(auto x:arr){
        if(!mpp[x]){
            res.push_back(x);
            mpp[x]=true;
        }
    }
    return res;
}

int main(){
    vector<int>arr={3,6,8,1,2,2,3,3,4,5};
    vector<int> ans=un_duplicates(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

vector<int>ranki(vector<int>arr){
    int n=arr.size();
    vector<int>sortedArr=arr;
    sort(sortedArr.begin(),sortedArr.end());
    unordered_map<int,int>mpp;
    int rank=1;
    vector<int>res;
    for(auto x:sortedArr){
        if(mpp.find(x) == mpp.end()){
            mpp[x]=rank;
            rank++;
        }
    }
    for(int x:arr){
        res.push_back(mpp[x]);
    }
    return res;
}

int main(){
    vector<int>arr={1, 5, 8, 15, 8, 25, 9};
    vector<int>ans=ranki(arr);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}

int equilibriumIndex(vector<int> nums){
    int left=0;
    int n=nums.size();
    int total=0;
    for(auto x:nums){
        total+=x;
    }
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



string remove_vowel(string s){
    int len=s.length();
    string res="";
    for(char x:s){
        char c=tolower(x);
        if(c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u'){
            continue;
        }
        res+=c;
    }
    return res;

}

int main(){
    string s = "Hello World";
    string ans=remove_vowel(s);
    cout<<ans;
    return 0;
}
*/


string capitalize(string s){
    string res;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(i==0 || s[i-1]==' '){
            s[i]=toupper(s[i]);
        }
        if(i==n-1 || s[n-1]==' '){
            s[i]=toupper(s[i]);
        }
    }
    return s;
}

int main(){
    string s = "hello world from dsa";
    cout << capitalize(s);
    return 0;
}