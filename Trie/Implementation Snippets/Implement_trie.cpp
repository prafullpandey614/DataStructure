class Trie {
    
    struct Node{
        Node* links[26];
        bool isEnd = 0;
        
       bool isContainsKey(char a){
          return links[a-'a'];
       }
        void put(char c, Node*node){
            
            links[c-'a'] = node ;
        }
        Node* get(char c){
            return links[c-'a'];
        }
        void setEnd(){
            isEnd = 1;
        }
        bool isThisEnd(){
            return isEnd ;
        }
    };
private: Node*root ;
public:
    Trie() {
     root = new Node();
        
    }
    
    void insert(string word) {
        Node *node = root ;
        for(int i = 0; i < word.size() ; ++i){
            if(!node->isContainsKey(word[i])){
                node->put(word[i],new Node());
            }
            node =  node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root ; 
        for(int i = 0; i <word.size() ;++i){
            if(!node->isContainsKey(word[i])){
                return 0 ;
            }
            node = node->links[word[i]-'a'];
        }
        
        return  node->isThisEnd();
    }
    
    bool startsWith(string prefix) {
        Node*node = root ;
        for(int i = 0 ; i < prefix.size() ;++i){
             if(!node->isContainsKey(prefix[i])){
                return 0 ;
            }
            node = node->links[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
