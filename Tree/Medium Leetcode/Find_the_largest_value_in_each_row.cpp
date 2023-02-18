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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(!root) return {};
        // q.push(root->val);
        q.push(root);
        while(!q.empty()){
           
           int ansd = INT_MIN;
            // q.pop();
            int sz = q.size();
            for(int i = 0 ; i < sz ; ++i){
                TreeNode* k = q.front();
                if(k->right)
                q.push(k->right);
                if(k->left)
                q.push(k->left);
                q.pop();
                ansd = max(ansd,k->val);
            }
            ans.push_back(ansd);
        }
        return ans ;
    }
};
