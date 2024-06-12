class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        diameter(root,result);  
        return result;
    }

    int diameter(TreeNode* root,int &result){
        if(!root)
            return 0;
        
        int left = diameter(root->left,result);
        int right = diameter(root->right,result);

        result = max(result,left+right);
        return max(left,right) + 1;
    }
};
