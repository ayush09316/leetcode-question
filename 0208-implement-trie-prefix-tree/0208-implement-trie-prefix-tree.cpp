class Trie {
    public:

    class Node{
        public:  
        Node* next[26];
        bool end;
        Node(){
            end=false;
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
        }      
    };

    Node* root;

    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        int i=0;
        Node* it=root;
        while(i<word.length()){
            if(it->next[word[i]-'a']==NULL)
                it->next[word[i]-'a']=new Node();
            it=it->next[word[i]-'a'];
            i++;
        }
        it->end=true;
    }
    
    bool search(string word) {
        int i=0;
        Node* it=root;
        while(i<word.length()){
            if(it->next[word[i]-'a']==NULL)
                return false;
            it=it->next[word[i]-'a'];
            i++;
        }
        return it->end;
    }
    
    bool startsWith(string prefix) {
        int i=0;
        Node* it=root;
        while(i<prefix.length()){
            if(it->next[prefix[i]-'a']==NULL)
                return false;
            it=it->next[prefix[i]-'a'];
            i++;
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