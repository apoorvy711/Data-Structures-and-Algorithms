#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }

    TreeNode(int data,TreeNode* left1,TreeNode*right1){
        val=data;
        left=left1;
        right=right1;
    }

};

class Solution{
    public:
    void child_sum( TreeNode* root){
        if(root==NULL) return;
        int child=0;
        if(root->left){
            child +=root->left->val;
        }
        if(root->right){
            child +=root->right->val;
        }
        if(child >=root->val){
            root->val=child;
        }
        else{
            if(root->left){
                root->left->val=root->val;
            }
            else if(root->right){
                root->right->val=root->val;
            }
        }

        child_sum(root->left);
        child_sum(root->right);

        int tot=0;
        if(root->left){
            tot +=root->left->val;
        }
        if(root->right){
            tot +=root->right->val;
        }
        if(root->left or root->right){
            root->val=tot;
        }
    }

};

void inordertraversal(TreeNode* root){
    if(root==NULL) return;
    inordertraversal(root->left);
    cout<<root->val<<" ";
    inordertraversal(root->right);

}

int main(){
    TreeNode* root = new TreeNode(40);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(40);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);

    cout<<"the BT before the change ";
    inordertraversal(root);
    cout<<endl;

    Solution solution;
    solution.child_sum(root);

    cout<<"the BT after the change ";
    inordertraversal(root);
    cout<<endl;
    return 0;

}