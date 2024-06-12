#include <iostream>

// Structure definition for
// a node in a binary tree
struct Node {
    // Defining the value of
    // the node (integer data)
    int data;        
     // Reference pointer to
     // the left child node
    Node* left;      
    // Reference pointer to
    // the right child node
    Node* right;      

    // Method to initialize
    // the node with a value
    Node(int val) {
        // Set the value of the
        // node to the passed integer
        data = val;   
        // Initialize left and 
        //r ight pointers as NULL
        left = right = NULL;  
    }
};

int main() {
    // Creating a new node for the root of the 
    // binary tree using dynamic allocation
    Node* root = new Node(1);
    // Creating left and right child
    // nodes for the root node
    root->left = new Node(2);
    root->right = new Node(3);
    // Creating a right child node for
    // the left child node of the root
    root->left->right = new Node(5);
}


/*********************************************************************************************/
//pre_o,post_o,in_o

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define the structure for a node in the binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Function to perform inorder traversal of the binary tree
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Function to perform preorder traversal of the binary tree
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}


// Function to perform postorder traversal of the binary tree
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Function to perform level order traversal of the binary tree
void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Inorder Traversal of the binary tree: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal of the binary tree: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal of the binary tree: ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal of the binary tree: ";
    levelOrder(root);
    cout << endl;

    return 0;
}


//*************************BFS DFS******************************** *//
#include <iostream>
#include <queue>
using namespace std;

// Define the structure for a node in the binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Function to perform BFS traversal of the binary tree
void BFS(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    cout << endl;
}

// Function to perform DFS traversal of the binary tree
void DFS(TreeNode* root) {
    if (!root) return;

    // Print the current node
    cout << root->val << " ";

    // Recur for the left and right subtrees
    DFS(root->left);
    DFS(root->right);
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "BFS Traversal of the binary tree: ";
    BFS(root);

    cout << "DFS Traversal of the binary tree: ";
    DFS(root);
    return 0;
}

