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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root) return {};
        map<int,int>mp; //level & val of right node at that level
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(q.size()){
            int sz = q.size();
            for(int i = 0 ; i < sz ; ++i){
                auto t = q.front();
                q.pop();
                mp[t.second] = t.first->val;
                if(t.first->left){
                    q.push({t.first->left,t.second+1});
                }
                if(t.first->right){
                    q.push({t.first->right,t.second+1});
                }
            }
        }
        for(auto x:mp){
            ans.push_back({x.second});
        }
        return ans ;
    }
};
