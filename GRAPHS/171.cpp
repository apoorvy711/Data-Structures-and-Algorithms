#include <bits/stdc++.h>
using namespace std;

//BY RANK
vector<int>parent, rankarr;
int findUPar(int node){
    if(node==parent[node]) return node;
    return parent[node]=findUPar(parent[node]);
}

void unionbyRank(int u,int v){
    int pu=findUPar(u);
    int pv=findUPar(v);

    if(rankarr[pv] < rankarr[pu]){
        parent[pv]=pu;
    }
    else if(rankarr[pu] < rankarr[pv]){
        parent[pu]=pv;
    }
    else {
        parent[pv]=pu;
        rankarr[pu]++;
    }
}
int main(){
    int n=7;
    parent.resize(n+1);
    rankarr.resize(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    unionbyRank(1,2);
    unionbyRank(2,3);
    unionbyRank(4,5);
    unionbyRank(6,7);
    unionbyRank(5,6);
    if(findUPar(3) == findUPar(7)){
        cout<<"Same";
    }
    else {
        cout<<"Not Same";
    }
    unionbyRank(3,7);
    if(findUPar(3) == findUPar(7)){
        cout<<"Same";
    }
    else {
        cout<<"Not Same";
    }
    return 0;
}

//BY SIZE
vector<int>parent, sizearr;
int findUPar(int node){
    if(node==parent[node]) return node;
    return parent[node]=findUPar(parent[node]);
}
void unionbySize(int u,int v){
    int pu=findUPar(u);
    int pv=findUPar(v);

    if(sizearr[pv] < sizearr[pu]){
        parent[pv]=pu;
        sizearr[pu]+=sizearr[pv];

    }
    else { 
        // dono sizes same h to kisi ko bhi kisi jod sakte hai 
        // isme humne pv me pu add kr rahe hai/ jod rahe hai
        parent[pu]=pv;// parent[pu] yh choti value hai isiliye yh update ho rahi h
        sizearr[pv]+=sizearr[pu]; // pv parent h isiliye uska size badhega kyunki pu link ho raha h pv me aake

    }
}
int main(){
    int n=7;
    parent.resize(n+1);
    sizearr.resize(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    unionbySize(1,2);
    unionbySize(2,3);
    unionbySize(4,5);
    unionbySize(6,7);
    unionbySize(5,6);
    if(findUPar(3) == findUPar(7)){
        cout<<"Same";
    }
    else {
        cout<<"Not Same";
    }
    unionbySize(3,7);
    if(findUPar(3) == findUPar(7)){
        cout<<"Same";
    }
    else {
        cout<<"Not Same";
    }
    return 0;
}