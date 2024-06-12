class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) 
            return true;

        return symmetryCheck(root->left,root->right);
    }
    bool symmetryCheck(TreeNode* p,TreeNode* q){ //p = leftNode , q = rightNode 
        if(p==NULL && q==NULL)
            return true;
        else if(p==NULL || q==NULL)
            return false;
        else if(p->val!=q->val)
            return false;
        
        return symmetryCheck(p->left,q->right) && symmetryCheck(p->right,q->left);
    }
};
