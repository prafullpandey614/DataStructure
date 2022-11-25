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
    // int ans = 0;
    int fun(TreeNode*root,int& ans){
       if(!root) return 0;
        
        int le = fun(root->left,ans);
        int ri = fun(root->right,ans);
        ans = max(ans,le+ri);
        return 1+max(le,ri);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        fun(root,diameter);
        return diameter ;
    }
};
