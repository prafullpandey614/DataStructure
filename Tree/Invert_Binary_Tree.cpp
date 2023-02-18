/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode*root,TreeNode*newRoot){
        if(!root) return ;
        if(root->left){
            TreeNode*right = new TreeNode(root->left->val);
            newRoot->right = right  ;
            dfs(root->left,newRoot->right);
        }
        if(root->right){
            TreeNode*left = new TreeNode(root->right->val);
            newRoot->left = left  ;
            dfs(root->right,newRoot->left);
        }


    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode*newRoot = new TreeNode(root->val) ;
        dfs(root,newRoot);
        return newRoot ;
    }
};
