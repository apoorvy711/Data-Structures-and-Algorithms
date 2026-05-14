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


//BRUTE
class Solution1{
    public:
    int print_TREEI(TreeNode* root,int k){
        vector<int>arr;
        inorder(root,arr);
        int kSmallest=arr[k-1];
        return kSmallest;
    }

    int print_TREEII(TreeNode* root,int k){
        vector<int>arr;
        inorder(root,arr);
        int n=arr.size();
        int kLargest=arr[n-k];
        return kLargest;
    }

    void inorder(TreeNode* root,vector<int>&arr){
        if(!root){
            return ;
        }
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
        return ;
    }
};
//OPTIMAL
class Solution2{
    public:
    int print_TREEi(TreeNode* root,int k){
        if(!root) return -1;
        int kSmallest=INT_MIN;
        int counter=0;
        INORDER(root,counter,k,kSmallest);
        return kSmallest;
    }

    int print_TREEii(TreeNode* root,int k){
        if (!root) return -1;
        int kLargest=INT_MAX;
        int counter=0;
        REVERSEINORDER(root,counter,k,kLargest);
        counter=0;
        return kLargest;

    }

    void REVERSEINORDER(TreeNode* root,int &counter,int k,int& kLargest){
        if(!root || counter>=k) return;
        REVERSEINORDER(root->right,counter,k,kLargest);
        counter++;
        if (counter == k) {
            kLargest = root->data;
            return;
        }
        REVERSEINORDER(root->left,counter,k,kLargest);
    }

    void INORDER(TreeNode* root,int &counter,int k,int& kSmallest){ 
        if(!root || counter>=k) return;
        INORDER(root->left,counter,k,kSmallest);
        counter++;
        if (counter == k) {
            kSmallest = root->data;
            return;
        }
        INORDER(root->right,counter,k,kSmallest);
    }

};


void print_tree(TreeNode* root){
    if (!root) return;
    print_tree(root->left);
    cout<<root->data;
    print_tree(root->right);
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

    cout<<"THE ORIGINAL BST IS"<<endl;
    print_tree(root);
    cout<<endl;

    Solution1 solution1;
    int k=3;
    int ANSI=solution1.print_TREEI(root,k);
    cout<<"THE kth smallest of BST is"<<ANSI;
    cout<<endl;
    int ANSII=solution1.print_TREEII(root,k);
    cout<<"THE kth largest of BST is"<<ANSII;
    cout<<endl;

    Solution2 solution2;
    int ANSi = solution2.print_TREEi(root,k);
    cout<<"THE kth smallest of BST is"<<ANSI;
    cout<<endl;
    int ANSii=solution2.print_TREEii(root,k);
    cout<<"THE kth largest of BST is"<<ANSii;
    cout<<endl;

}