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
    
    int widthOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(q.size()){
            int sz = q.size() ;   
            int mmin= q.front().second;
            int fi,se;
            for(int i = 0 ; i  <sz ;++i){
                 auto t = q.front();
                 q.pop();
                int cur_ind = t.second-mmin;
                if(i==0) fi = cur_ind;
                if(i==sz-1) se=cur_ind;
                if(t.first->left)
                 q.push({t.first->left,cur_ind*1LL*2+1});
                 
                if(t.first->right)
                 q.push({t.first->right,cur_ind*1LL*2+2});
               
            }
             ans = max(ans,se-fi+1);;
        }
        return (ans) ;
    }
};
