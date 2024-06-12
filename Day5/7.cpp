class Solution {
public:
    void findkthsmallest(TreeNode* root,int &count,int &smallest,int k){
        if(root == NULL)
            return;
        findkthsmallest(root->left,count,smallest,k);
        count++;

        if(count == k){
            smallest = root->val;
            return;
        }
        findkthsmallest(root->right,count,smallest,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int smallest;
        findkthsmallest(root,count,smallest,k);
        return smallest;
    }
};
