class Solution{
  public:
  void deleteKey(trie_node_t *root, char key[])
  {
    //Code here
    trie_node_t*node= root ;
    for(int i = 0 ; i< strlen(key) ;  ++i){
        if(root->children[key[i]-'a']==NULL){
            return ;
        }
        else root = root->children[key[i]-'a'];
    }
    root->value = 0 ;
    root =node ;
    return  ;
    
  }
};
