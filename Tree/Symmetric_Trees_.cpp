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
    bool dfs(TreeNode*lef,TreeNode*rig){
        if(!lef && rig) return 0;
        if(!rig && lef) return 0;
        if(!rig && !lef) return 1;
        bool ans =1;
        if(lef->val!=rig->val){
            return 0;
        }
       
        ans&=dfs(lef->right,rig->left);
        ans&=dfs(lef->left,rig->right);
        
        
        return ans ;
    }
    bool isSymmetric(TreeNode* root) {
        // if(!root) return 1;
        return dfs(root->left,root->right);
    }
};
