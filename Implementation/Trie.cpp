class Trie {
    struct Node{
        Node*links[26] ;
        bool end ;

        bool contains(char c){
            return links[c-'a'];
        }
        void put(char c,Node*node){
            links[c-'a'] = node ;
        }

    };
public:
    Node*root ;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*node = root ;
        for(int i= 0 ; i< word.size(); ++i){
            if(!node->contains(word[i])){
                node->put(word[i],new Node()) ;
            }
            
            node = node->links[word[i]-'a'];
        }
        node->end = 1;
        
    }
    
    bool search(string word) {
        Node*node = root ;
        for(int i = 0; i<word.size(); ++i){
            if(!node->contains(word[i])){
                return 0 ;
            }
            node = node->links[word[i]-'a'];
        }
        return node->end ;
    }
    
    bool startsWith(string word) {
         Node*node = root ;
        for(int i = 0; i<word.size(); ++i){
            if(!node->contains(word[i])){
                return 0 ;
            }
            node = node->links[word[i]-'a'];
        }
        return 1 ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
