/* Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree - 
i. Insert new node ii. Find number of nodes in longest path from root iii. Minimum data value found in the tree iv. Change a tree so that the roles of the 
left and right pointers are swapped at every node v. Search a value. 
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insertNode(Node* root, int value) {
    if(root == NULL) root = createNode(value);
    else if(value <= root->data) root->left = insertNode(root->left, value);
    else root->right = insertNode(root->right, value);
    return root;
}
int findHeight(Node* root) {
    if(root == NULL) return -1;
    else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}
int findMin(Node* root) {
    if(root == NULL) {
        cout << "Error: Tree is empty!" << endl;
        return -1;
    }
    else if(root->left == NULL) return root->data;
    else return findMin(root->left);
}
Node* swapNodes(Node* root) {
    if(root == NULL) return NULL;
    else {
        Node* temp = root->left;
        root->left = swapNodes(root->right);
        root->right = swapNodes(temp);
        return root;
    }
}
bool search(Node* root, int value) {
    if(root == NULL) return false;
    else if(root->data == value) return true;
    else if(value <= root->data) return search(root->left, value);
    else return search(root->right, value);
}
void printMenu() {
    cout << "Menu:" << endl;
    cout << "1. Insert a new node" << endl;
    cout << "2. Find the number of nodes in longest path from root" << endl;
    cout << "3. Find the minimum data value in the tree" << endl;
    cout << "4. Swap the left and right pointers at every node" << endl;
    cout << "5. Search a value" << endl;
    cout << "6. Exit" << endl;
}

int main() {
    Node* root = NULL;
    int arr[] = { };
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++) { root = insertNode(root, arr[i]); }
    int choice = 0;
    int value;
    while(choice != 6) {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node inserted successfully!" << endl;
                break;
            case 2:
                cout << "The number of nodes in the longest path from root is: " << findHeight(root) << endl;
                break;
            case 3:
                cout << "The minimum data value in the tree is: " << findMin(root) << endl;
                break;
            case 4:
                root = swapNodes(root);
                cout << "The tree has been swapped successfully!" << endl;
                break;
            case 5:
                cout << "Enter the value to be searched: ";
                cin >> value;
                if(search(root, value)) cout << "The value " << value << " is present in the tree." << endl;
                else cout << "The value " << value << " is not present in the tree." << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Error: Invalid choice! Please enter a valid choice." << endl;
                break;
        }
        cout<<endl;
    }
    return 0;
}
