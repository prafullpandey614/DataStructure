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
    void solve(TreeNode*curr , TreeNode*parent , bool isleft){
        
        if(curr->left!=NULL){
            solve(curr->left , curr, true);
        }
        if(curr->right!=NULL){
            solve(curr->right , curr, false);
        }
        if(curr->right==NULL && curr->left==NULL && curr->val==0){
           if(isleft)  parent->left = NULL;
           else  parent->right = NULL ;
         
        }
        
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1) ;
        dummy->left = root ;
        solve(dummy->left,dummy,true);
        if(dummy->left==NULL) return NULL;
        return root;
    }
};
