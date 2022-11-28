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
    int mans = INT_MIN ;
    void dfs(TreeNode*root,int &maxDepth,int& val , int depth){
        if(!root) return ;
        
        if(root->left){
            dfs(root->left,maxDepth,val,depth+1);
        }
        if(root->right){
            dfs(root->right,maxDepth,val,depth+1);
        }
        if(depth>maxDepth){
            maxDepth = depth;
            val = root->val ;
        }
        return ;
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=root->val;
        int maxDepth = 0;
        
        dfs(root,maxDepth,ans,0);
        return ans;
    }
};
