void preOrd(Node*root,vector<int>&ans){
    if(root==NULL) return;
    
    ans.push_back(root->data);
    preOrd(root->left,ans);
    preOrd(root->right,ans);
}

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
    vector<int>ans;
    preOrd(root,ans);
    return ans;
    
  // Your code here
}
