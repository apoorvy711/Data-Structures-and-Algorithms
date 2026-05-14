#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int data1) {
        data = data1;
        next = nullptr;
        bottom = nullptr;
    }
};

// Merge two sorted lists using bottom pointers
Node* mergeBottomLists(Node* a, Node* b) {
    Node dummy(-1);
    Node* tail = &dummy;

    while (a && b) {
        if (a->data < b->data) {
            tail->bottom = a;
            a = a->bottom;
        } else {
            tail->bottom = b;
            b = b->bottom;
        }
        tail = tail->bottom;
    }

    if (a) tail->bottom = a;
    else tail->bottom = b;

    return dummy.bottom;
}

Node* flattenLinkedList(Node* root) {
    if (!root || !root->next) return root;

    // Recurse for the list on right
    root->next = flattenLinkedList(root->next);

    // Merge current list with right list
    root = mergeBottomLists(root, root->next);

    return root;
}

// Output the flattened list using bottom pointers
void outputFlattened(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

// Optional: visual debug to show original structure
void printOriginalLinkedList(Node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;

        if (head->bottom) {
            cout << " -> ";
            printOriginalLinkedList(head->bottom, depth + 1);
        }

        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }

        head = head->next;
    }
}

int main() {
    // Creating the multilevel list as per your example
    Node* head = new Node(5);
    head->bottom = new Node(14);
    
    head->next = new Node(10);
    head->next->bottom = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->bottom = new Node(20);
    head->next->next->bottom->bottom = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->bottom = new Node(17);

    cout << "Original linked list:\n";
    printOriginalLinkedList(head, 0);

    Node* flattened = flattenLinkedList(head);
    cout << "\n\nFlattened linked list:\n";
    outputFlattened(flattened);

    return 0;
}
