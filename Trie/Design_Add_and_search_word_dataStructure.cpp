class WordDictionary {
    struct Node{

        Node*links[26];
        bool end = 0 ;

        bool isContains(char c){
            return links[c-'a'];
        }
        void put(char c,Node*node){
            links[c-'a'] = node ;
        }
        
    };
public:
    Node*root = new Node(); 
    WordDictionary() {
        root= new Node();
    }
    
    void addWord(string word) {
        Node*node = root ;
        for(int i = 0 ; i < word.size(); ++i){
            if(!node->isContains(word[i])){
                node->put(word[i],new Node());
            }
            node = node->links[word[i]-'a'] ;
        }
        node->end = 1 ;
    }
    
    bool search(string word) {
        Node*node =root ;
        return ns(word,0,node);
    }
    bool ns(string &word,int ind,Node*node){
        if(ind==word.size()) return node->end;
        if(word[ind]=='.'){
            for(char c='a' ; c<='z'; ++c){
                word[ind]=c;
                if(node->links[c-'a']){
                    Node* nnode = node->links[c-'a'];
                    if(ns(word,ind+1,nnode)) return 1;
                }
                word[ind]='.';
                
            }
            return 0 ;
        }
        else{
            if(node->isContains(word[ind])){
                node = node->links[word[ind]-'a'];
                return ns(word,ind+1,node);
            }
            else return 0 ;
        }
        
    }
};
