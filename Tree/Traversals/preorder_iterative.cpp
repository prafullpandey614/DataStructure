 vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        st.push(root);
        vector<int>ans;
        if(!root) return ans;
        while(!st.empty()){
            root = st.top(); st.pop();
            ans.push_back(root->val);
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
            
           
        }
        return ans;
    }
