#include<bits/stdc++.h>
using namespace std;
/*
//Allocate Minimum Number of Pages
//BRUTE
int cnt_studs(vector<int> &pages,int pages_per_stud){
    int n=pages.size();
    int cntSTUDENTS=1;
    int pageSTUDENTS=0;
    for( int i=0;i<n;i++){
        if( pageSTUDENTS + pages[i] <= pages_per_stud ){
            pageSTUDENTS +=pages[i];
        }
        else{
            cntSTUDENTS++;
            pageSTUDENTS = pages[i];
        }
    }
    return cntSTUDENTS;
}
int allocate_books( vector<int> &pages , int no_studs_given ,int no_books_given){

    if(no_studs_given > no_books_given) return -1;

    int low  = *max_element(pages.begin(),pages.end());
    int high = accumulate(pages.begin(),pages.end(),0);

    for(int pages_per_stud = low ; pages_per_stud <= high; pages_per_stud++){
        if(cnt_studs( pages, pages_per_stud) == no_studs_given){
            return pages_per_stud;
        }
    }
    return low;
}
int main(){
    vector<int> pages={25, 46, 28, 49, 24};
    int no_studs_given=4;
    int no_books_given=5;

    int ans=allocate_books(pages,no_studs_given,no_books_given);
    cout<<"the number of pages allocated to a student is"<<ans;
    return 0;
}

//OPTIMAL
int cnt_studs(vector<int> &pages,int pages_per_stud){
    int n=pages.size();
    int cntSTUDENTS=1;
    int pageSTUDENTS=0;
    for( int i=0;i<n;i++){
        if( pageSTUDENTS + pages[i] <= pages_per_stud ){
            pageSTUDENTS +=pages[i];
        }
        else{
            cntSTUDENTS++;
            pageSTUDENTS = pages[i];
        }
    }
    return cntSTUDENTS;
}
int allocate_books( vector<int> &pages , int no_studs_given ,int no_books_given){
    
    if(no_studs_given > no_books_given) return -1;

    int low  = *max_element(pages.begin(),pages.end());
    int high = accumulate(pages.begin(),pages.end(),0);

    while( low <= high ){
        int mid=(low+high)/2;
        int no_studs=cnt_studs(pages,mid);
        if(no_studs > no_studs_given){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;

}
*/

int count_stud(vector<int>arr,int pages){
    int n=arr.size();
    int student=1;
    long long pagesStudents=0;
    for(int i=0;i<n;i++){
        if(pagesStudents+arr[i] <= pages){
            pagesStudents+=arr[i];
        }
        else{
            student++;
            pagesStudents=arr[i];
        }
    }
    return student;
}

int allocate_books(vector<int>arr,int n,int m){
 
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int students=count_stud(arr,mid);
        if(students>n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}


int main(){
    vector<int> pages={25, 46, 28, 49, 24};
    int no_studs_given=4;
    int no_books_given=5;

    int ans=allocate_books(pages,no_studs_given,no_books_given);
    cout<<"the number of pages allocated to a student is"<<ans;
    return 0;
}