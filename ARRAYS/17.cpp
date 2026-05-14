#include <bits/stdc++.h>
using namespace std;

//Largest element in an array
void largest(vector<int>&arr,int n){
    int larg=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>larg){
            larg=arr[i];
        }
    }
    cout<<"largest element is"<<larg;
}
int main(){
    vector<int>arr={3,2,4,6,7,1,0,9};
    int n=arr.size();
    largest(arr,n);
    return 0;
}


//SECOND LARGEST
int Slargest(vector <int> &arr,int n){
    int largest=arr[0];
    int secondlargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i] >largest){
            secondlargest=largest;
            largest=arr[i];
        }
        else if(arr[i] < largest && arr[i] >secondlargest){
            secondlargest=arr[i];
        }
    }
    return secondlargest;
}
int main(){
    int n;
    cout<<"number of elements in an array"<<" ";
    cin>>n;
    vector<int>arr(n);
    cout<<"the arrray is: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;   
    int result=Slargest(arr,n);
    cout<<"the second largest element is"<<" "<<result<<endl;
    return 0;
}

//CHECK IF THE ARRAY IS SORTED
bool sorted(vector<int> &arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false ;
        }
    }
    return true;
}
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"the arrray is:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(sorted(arr,n)){
        cout<<"array is sorted";
    }
    else{
        cout<<"array is not sorted";
    }
    return 0;
}

//REMOVE DUPLICATES
int duplicates(vector<int> &arr,int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return (i+1);
}
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"the arrray is: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int news=duplicates(arr,n);
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < news; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

