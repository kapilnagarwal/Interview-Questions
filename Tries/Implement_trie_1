class TrieNode{
public:
    TrieNode* links[26] = {NULL};
    bool eow = false;
};

class Trie {    
    TrieNode* root = NULL;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++){
            if (!curr->links[word[i] - 'a'])
                curr->links[word[i] - 'a'] = new TrieNode();
            curr = curr->links[word[i] - 'a'];
        }
        curr->eow = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++){
            if (curr->links[word[i] - 'a'])
                curr = curr->links[word[i] - 'a'];
            else
                return false;
        }
        return curr->eow;
    }
    
    bool startsWith(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++){
            if (curr->links[word[i] - 'a'])
                curr = curr->links[word[i] - 'a'];
            else
                return false;
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
