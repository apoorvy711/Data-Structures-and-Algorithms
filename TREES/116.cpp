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
    TreeNode* delete_node(TreeNode* root,int key){
        if(root==NULL) return NULL;
        if(root->data==key) return helper(root);
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->data > key){
                if(root->left !=NULL && root->left->data==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right !=NULL && root->right->data==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            } 
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(root->right==NULL) return root->left;
        else if(root->left==NULL) return root->right;

        TreeNode* rightChild=root->right;
        TreeNode* lastRight=findLastright(root->left);
        lastRight->right=root->right;
        return root->left;
    }

    TreeNode* findLastright(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return findLastright(root->right);
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
    TreeNode* root=new TreeNode(9);
    root->left=new TreeNode(8);
    root->right=new TreeNode(12);
    root->left->left=new TreeNode(5);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(13);
    root->left->left->left=new TreeNode(3);
    root->left->left->right=new TreeNode(7);
    root->right->left->right=new TreeNode(11);
    root->left->left->left->left=new TreeNode(2);
    root->left->left->left->right=new TreeNode(4);
    root->left->left->right->left=new TreeNode(6);
    root->left->left->right->right=new TreeNode(14);
    root->left->left->left->left->left=new TreeNode(1);

    cout<<"the original BST is";
    printTREE(root);
    int key=5;
    Solution solution;
    TreeNode* ans=solution.delete_node(root,key);
    cout<<"the NEW BST is";
    printTREE(ans);
    cout<<endl;
    return 0;
}