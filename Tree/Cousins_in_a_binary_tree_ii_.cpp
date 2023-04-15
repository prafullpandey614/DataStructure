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
    unordered_map<TreeNode*,TreeNode*>par ;
    map<TreeNode*,int>dpth;
    map<int,vector<TreeNode*>>dp,pr;
    // vector<int>depth(10001,-1);
    void dfs(TreeNode*root){
        if(!root) return ; 
        
        
        if(root->left){
            // depth[root->left] = depth[root]+1 ;
            dpth[root->left] = dpth[root]+1;
            dp[dpth[root->left]].push_back(root->left); 
            par[root->left] = root ;
            dfs(root->left);
        }
         if(root->right){
            dpth[root->right] = dpth[root]+1 ;
             dp[dpth[root->right]].push_back(root->right);
             par[root->right] = root ;
              dfs(root->right);
        }
        
        
    }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        dpth[root] = 0 ;
        dp[0].push_back(root);
        par[root] = root;
        dfs(root);
        // for(auto x:dp){
        //     cout<<x.first<<endl;
        //     cout<<"_______"<<endl;
        //     for(auto df:x.second){
        //         cout<<df->val<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto x:dp){
            unordered_map<TreeNode*,int>mp;
            for(auto d:x.second){
                mp[par[d]] +=d->val;
            }
            int sum = 0 ;
            for(auto ds:mp){
                sum+=ds.second ;
            }
            // cout<<mp.size()<<endl;
            if(mp.size()==1){
                for(auto d:x.second){
                    d->val= 0 ;
                 }
            }
            else{
                for(auto d:x.second){
                    // cout<<"Here"<<endl;
                     d->val = sum-mp[par[d]];
                 }
            }
        }
        return root ;
    }
};
