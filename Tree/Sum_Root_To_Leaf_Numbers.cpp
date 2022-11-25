class Solution {
public:
    int dfs(TreeNode*root,int num){
        if(!root) return  0;
        if(root->left==NULL && !root->right){
            return num*10+root->val;
        }
        num = num*10+root->val ;
        return dfs(root->left,num)+dfs(root->right,num);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};
//Iterative approach with same time complexity
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
    int dfs(TreeNode*root,int num){
        if(!root) return  0;
        if(root->left==NULL && !root->right){
            return num*10+root->val;
        }
        num = num*10+root->val ;
        return dfs(root->left,num)+dfs(root->right,num);
    }
    int sumNumbers(TreeNode* root) {
       stack<pair<TreeNode*,int>>st; //Node and Current Sum 
       st.push({root,0});
        int sum = 0;
        while(!st.empty()){
            auto x = st.top();
            st.pop();
            if(x.first->left==NULL && x.first->right==NULL)
              sum+= x.second*10+x.first->val ;
            if(x.first->left)
            st.push({x.first->left,x.second*10+x.first->val });
            if(x.first->right)
            st.push({x.first->right,x.second*10+x.first->val }) ;
            
        }
        return sum;
    }
};
