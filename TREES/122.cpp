#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
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

struct BSTiterator{
    stack<TreeNode*>st;
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            node=node->left;
        }
    }
    BSTiterator(TreeNode* root){
        pushAll(root);
    }
    int next(){
        TreeNode* node=st.top();
        st.pop();
        if(node->right){
            pushAll(node->right);
        }
        return node->data;
    }
    bool hasNext(){
        return !st.empty();
    }
};

void printTree(TreeNode* root){
    TreeNode * node=root;
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            TreeNode * ans=q.front();
            q.pop();
            cout<<ans->data<<" ";
            if(ans->left) q.push(ans->left);
            if(ans->right) q.push(ans->right);
        }
        cout<<endl;
    }
}

int main(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(1);
    root->left->right->left = new TreeNode(5);
    root->left->right->left->left = new TreeNode(4);
    root->right->left = new TreeNode(9);
    root->right->left->left = new TreeNode(8);
    printTree(root);
    BSTiterator it(root);
    while(it.hasNext()){
        cout<<it.next()<<" ";
    }
    return 0;
}