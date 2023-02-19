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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root) return {} ;
        vector<vector<int>>ans ;
        q.push(root);
        bool flag = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp ;
            for(int i = 0 ; i < sz; ++i){
                auto nd = q.front();
                q.pop();
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
                temp.push_back(nd->val);
            }
            if(flag) reverse(temp.begin(),temp.end());
            flag =!flag ;
            ans.push_back(temp);
        }
        return ans ;
    }
};
