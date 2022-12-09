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
    int maxAncestorDiff(TreeNode* root,int mx=0,int mn=100000) {
        return (!root) ? mx-mn :
        max(maxAncestorDiff(root->left,max(root->val,mx),min(root->val,mn)),maxAncestorDiff(root->right,max(root->val,mx),min(root->val,mn)));

    }
};
