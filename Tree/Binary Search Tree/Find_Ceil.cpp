void rec(Node*root,int d,int &c){
    if(root->data == d){
        c = root->data ;
        return ;
    }
    
    if(root->data<d){
        if(root->right)
        rec(root->right,d,c);
        return ;
    }
    if(root->data>d){
        c = root->data ;
        if(root->left)
        rec(root->left,d,c);
        return ;
    }
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int c = -1;
    rec(root,input,c);
    return c; 
    
    // Your code here
}
