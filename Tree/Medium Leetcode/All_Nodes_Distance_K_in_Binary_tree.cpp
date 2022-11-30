/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*>parent; //key : son value : parent
    vector<bool>vis;
    // set<TreeNode*>vis;
    void findParent(TreeNode*root){
        if(!root) return ;
        
        if(root->left){
            parent[root->left] = root;
            findParent(root->left);
        }
        if(root->right){
            parent[root->right] = root ;
            findParent(root->right);
        }
        
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        vis.resize(510,0);
        findParent(root);
        dfs(target,k);
        return ans ;
        
    }
    vector<int>ans ;
    void dfs(TreeNode*root,int k){
        if(!root) return ;
        if(vis[root->val]) return ;
        vis[root->val]  =1;
        // if(vis.find(root)!=vis.end()) return ;
        // vis.insert(root);
        
        if(k==0){
            ans.push_back(root->val); return ;
        }
        dfs(root->left,k-1);
        dfs(root->right,k-1);
        if(parent[root]){
            dfs(parent[root],k-1);
        }
        
    }
    
};
