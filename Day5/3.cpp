class Solution {
public:
    int checkBalance(TreeNode* root){
        if(!root) return 0;

        int leftHeight = checkBalance(root->left);
        if(leftHeight == -1) return -1;

        int rightHeight = checkBalance(root->right);
        if(rightHeight == -1) return -1;

        if(!(abs(leftHeight-rightHeight)<=1))
            return -1;

        return max(leftHeight,rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) !=-1;
    }
};
