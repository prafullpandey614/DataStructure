  void inOrd(Node*root, vector<int>&ans){
        if(root==NULL) return;
        
        inOrd(root->left,ans);
        ans.push_back(root->data);
        inOrd(root->right,ans);
        
    }
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>ans;
        inOrd(root,ans);
        return ans;
    }
