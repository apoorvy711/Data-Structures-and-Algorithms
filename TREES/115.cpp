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

class Solution{
    public:
    TreeNode* node_insert(TreeNode* root,int key){
        TreeNode* cur=root;
        if(root==NULL) return new TreeNode(key);
        while(true){
            if(cur->data<key){
                if(cur->right !=NULL){
                    cur=cur->right;
                }
                else{
                    cur->right=new TreeNode(key);
                    break;
                }   
            }
            else{
                if(cur->left !=NULL){
                    cur=cur->left;
                }
                else{
                    cur->left=new TreeNode(key);
                    break;
                }
            }
        }
        return root;
    }
};

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
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    int key=0;
    Solution solution;
    TreeNode* ans=solution.node_insert(root,key);
    cout<<"the new BST";
    printTREE(ans);
    cout<<endl;
    return 0;
}