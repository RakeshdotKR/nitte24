class Solution {
public:
    void traverse(TreeNode* root,vector<int> &vec){
        if(root==NULL)
            return ;
        traverse(root->left,vec);
        vec.push_back(root->val);
        traverse(root->right,vec);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;

        traverse(root1,tree1);
        traverse(root2,tree2);

        vector<int> v;

        int n = tree1.size();
        int m = tree2.size();

        int i=0,j=0;
        while(i<n && j<m){
            if(tree1[i] <= tree2[j]){
                v.push_back(tree1[i]);
                i++;
            }
            else{
                v.push_back(tree2[j]);
                j++;
            }
        }
        while(i<n){
            v.push_back(tree1[i]);
            i++;
        }
        while(j<m){
            v.push_back(tree2[j]);
            j++;
        }
        return v;
    }
};
