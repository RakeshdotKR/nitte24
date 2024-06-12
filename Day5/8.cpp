class Solution {
public:
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return validate(root);
    }
    TreeNode* prev;
    bool validate(TreeNode* root){
        if(root == NULL)
            return true;
        if(!validate(root->left)){
            return false;
        }
        if(prev!=NULL && (root->val <= prev->val)){
            return false;
        }
        prev = root;
        return validate(root->right);
    }
};
