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

//**********************************Binary Search Tree*******************************************************/
#include <iostream>
using namespace std;

// Define the structure for a node in the binary search tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Class for Binary Search Tree
class BST {
private:
    TreeNode* root;

    // Helper function to insert a value in the BST
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    
// Helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
// Helper function to delete a value from the BST
    TreeNode* deleteNode(TreeNode* node, int val) {
        if (node == nullptr) {
            return node;
        }
        if (val < node->val) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->val) {
            node->right = deleteNode(node->right, val);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = findMin(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }
        return node;
    }

    // Helper function to search a value in the BST
    bool search(TreeNode* node, int val) {
        if (node == nullptr) {
            return false;
        }
        if (val < node->val) {
            return search(node->left, val);
        } else if (val > node->val) {
            return search(node->right, val);
        } else {
            return true;
        }
    }

    // Helper function for inorder traversal
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    // Helper function for preorder traversal
    void preorder(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

  
  // Helper function for postorder traversal
    void postorder(TreeNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }

public:
    BST() : root(nullptr) {}

    // Public function to insert a value in the BST
    void insert(int val) {
        root = insert(root, val);
    }

    // Public function to delete a value from the BST
    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    // Public function to search a value in the BST
    bool search(int val) {
        return search(root, val);
    }

    // Public function for inorder traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Public function for preorder traversal
    void preorder() {
        preorder(root);
        cout << endl;
    }

    // Public function for postorder traversal
    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Inorder traversal
    cout << "Inorder traversal: ";
    bst.inorder();

    // Preorder traversal
    cout << "Preorder traversal: ";
    bst.preorder();

    // Postorder traversal
    cout << "Postorder traversal: ";
    bst.postorder();

    // Search for an element
    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (bst.search(25) ? "Found" : "Not Found") << endl;

    // Delete an element
    bst.deleteNode(20);
    cout << "Inorder traversal after deleting 20: ";
    bst.inorder();

    return 0;
}
