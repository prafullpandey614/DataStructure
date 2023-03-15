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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool flag = 0 ;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(!t) flag = true ;
            else{
                if(flag) return 0 ;
                q.push(t->left);
                q.push(t->right);
            }

        }
        return 1 ;
    }
};
