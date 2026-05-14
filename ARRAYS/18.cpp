#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter number of elements in array";
    cin>>n;
    int arr[n];
    cout<<"the array is"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;

    cout<<"rotated array";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}


int main(){
    int n,k;
    cout<<"enter number of elements in array";
    cin>>n;
    cout<<"enter shift number";
    cin>>k;
    
    int arr[n];
    cout<<"the array is"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    k=k%n;
    int temp[k];
    for(int i=0 ; i<k ; i++){
        temp[i]=arr[i];
    }

    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }

    for(int i=0;i<k;i++){
        arr[n-k+i]=temp[i];
    }
    cout<<"the new array is";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}

//LINEAR SEARCH

int main(){
    int n;
    int arr[]={1,2,3,4,5};
    int num=4;
   
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            cout << "Element found at index: " << i << endl;
            return i; //
        }    
    }
    cout << "Element not found!" << endl;
    return -1;  
}

//UNION OF TWO SORTED ARRAYS
    void Findunion(int arr1[],int n,int arr2[],int m){
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(arr1[i]);
        }
        for(int j=0;j<m;j++){
            s.insert(arr2[j]);
        }
        for(int x:s){
            cout<<x<<" ";
            cout<<endl;
        }
    }
 int main(){
    int arr1[]={1,2,3,4,5};
    int arr2[]={1,4,3,6,7,8};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    cout<<"union of two sorted arrays";
    Findunion(arr1,n,arr2,m);
    return 0;
}

//INTERSECTION OF TWO ARRAYS
    void interS(int arr1[],int n,int arr2[],int m){
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(arr1[i]);
        }
        cout<<"intersection";
        for(int j=0;j<m;j++){
            if(s.find(arr2[j]) !=s.end()){
                cout<<arr2[j]<<" ";
                s.erase(arr2[j]);
            }
        }
    }
 int main(){
    int arr1[]={1,2,4,5,6};
    int arr2[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    interS(arr1,n,arr2,m);
    return 0;
 }


//LEFT ROTATE AN ARRAY BY ONE PLACE
void left_rotate(vector<int> &arr,int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];   
    }
    arr[n-1]=temp;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"the array is ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    left_rotate(arr,n);
    cout<<"the new array is ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}


//LEFT ROTATE AN ARRAY BY d PLACE
//better solution

void left_rotate(vector<int> &arr,int n){
    int d;
    cin>>d;
    d=d%n;
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
  
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"the array is ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    left_rotate(arr,n);
    cout<<"the new array is ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}

//LEFT ROTATE AN ARRAY BY d PLACE
//optimal solution
void left_rotate(vector<int> &arr,int n,int d){
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d+1, arr.end());
    reverse(arr.begin(), arr.end());
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"the array is ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cin>>d;
    left_rotate(arr,n,d);
    cout<<"the new array is ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}


//PUT ZEROES AT THE END

void movezeros(vector <int> &arr,int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i] ==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i] !=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    if (j == -1) return;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"the array is";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    movezeros(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}

//LINEAR SEARCH
int linear_search(vector<int> &arr,int n){
    int num;
    cout<<"the number is :";
    cin>>num;
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int news=linear_search(arr,n);
    cout<<"the number index is"<<news;
    return 0;  
}
