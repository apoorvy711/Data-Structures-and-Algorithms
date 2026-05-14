#include <bits/stdc++.h>
using namespace std;


/*
// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to get the Preorder,
// Inorder and Postorder traversal
// Of Binary Tree in One traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;

    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return {};
    }

    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;

    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it); 
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second = 3;
            st.push(it); 
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}


// Function to print the
// elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

*/

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

vector<vector<int>>Three_Traversals_in_one(Node* root){
    vector<int>preorder,inorder,postorder;
    stack<pair<Node*,int>>st;
    st.push({root,1});
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        int state=it.second;
        Node* node=it.first;
        if(state==1){
            preorder.push_back(node->data);
            st.push({node,2});
            if(node->left){
                st.push({node->left,1});
            }
        }
        else if(state==2){
            inorder.push_back(node->data);
            st.push({node,3});
            if(node->right){
                st.push({node->right,1});
            }
        }
        else{
            postorder.push_back(node->data);
        }
    }
    vector<vector<int>>res;
    res.push_back(preorder);
    res.push_back(inorder);
    res.push_back(postorder);
    return res;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    vector<vector<int>>ans=Three_Traversals_in_one(root);
    vector<int>PREORDER=ans[0];
    vector<int>INORDER=ans[1];
    vector<int>POSTORDER=ans[2];

    for(auto it:PREORDER){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:INORDER){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:POSTORDER){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}