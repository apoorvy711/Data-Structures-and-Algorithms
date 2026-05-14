#include<bits/stdc++.h>
using namespace std;

struct  TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }

    TreeNode(int val,TreeNode* left1,TreeNode* right1){
        data=val;
        left=left1;
        right=right1;
    }

};
/*
int floor_BST(TreeNode* root,int key){
        int floor=-1;
        while(root){
            if(root->data==key){
            floor=root->data;
            return floor;
        }
        if(key<root->data){
            root=root->left;
        }
        else{
            floor=root->data;
            root=root->right;
        }
        }
        return floor;        
}
*/

int floor_BST(TreeNode* root,int key){
    int floor=-1;
    while(root){
        if(root->data == key){
            floor=root->data;
            return floor;
        }
        if(key< root->data){
            root=root->left;
        }
        else{
            floor=root->data;
            root=root->right;
        }
    }
    return floor;
} 

void printTREE(TreeNode* ans){
    TreeNode* node=ans;
    queue<TreeNode*>q;
    q.push(node);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            TreeNode* root=q.front();
            q.pop();
            cout<<root->data<<" ";
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        cout<<endl;
    }
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    int key=8;
    printTREE(root);
    int ans=floor_BST(root,key);
    cout<<"the floor of key is "<<ans;
    cout<<endl;
    return 0;

}

