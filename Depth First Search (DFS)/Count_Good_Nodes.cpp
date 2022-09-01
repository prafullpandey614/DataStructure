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
    int count = 0;
    void dfs(TreeNode* node , int prev ){
        if(node==NULL ){
            return ;
        }
        if(node->val>= prev){
            count++;
            prev = node->val ;
        }
            dfs(node->right,prev);
            dfs(node->left,prev);
        
    }
    
    int goodNodes(TreeNode* root) {
        count = 1;
        dfs(root->left,root->val);
        dfs(root->right,root->val);
        return count  ;
    }
};
