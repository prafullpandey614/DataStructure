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
    private:
    // TreeNode*prev = NULL;
public:
    
    void flatten(TreeNode* root) {
        if(!root) return ;
       stack<TreeNode*>st ;
        st.push(root);
        while(st.size()){
            auto x = st.top();
            st.pop();
            if(x->right){
                st.push(x->right) ;
            }
            if(x->left){
                st.push(x->left);
            }
            if(!st.empty())
            x->right=  st.top();
            x->left = NULL; 
            
        }
        // return root ;
    }
    
};
