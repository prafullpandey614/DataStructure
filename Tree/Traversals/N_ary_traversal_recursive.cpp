 vector<int> preorder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        if(!root) return ans ;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            reverse(root->children.begin(),root->children.end());
            for(auto x:root->children){
                st.push(x);
            }
            
        }
         return ans;
    }
