class TrieNode{
	public:
		TrieNode* links[26] = {NULL};
		int eow = 0;
		int cp = 0;
};

class Trie{

    public:
	TrieNode* root = NULL;
    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode* curr = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (!curr->links[word[i] - 'a']){
				curr->links[word[i] - 'a'] = new TrieNode();
			}
			curr = curr->links[word[i] - 'a'];
			curr->cp++;
		}
		curr->eow++;
    }

    int countWordsEqualTo(string &word){
        TrieNode* curr = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (curr->links[word[i] - 'a']){
				curr = curr->links[word[i] - 'a'];
			}
			else
				return 0;
		}
		return curr->eow;
    }

    int countWordsStartingWith(string &word){
        TrieNode* curr = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (curr->links[word[i] - 'a']){
				curr = curr->links[word[i] - 'a'];
			}
			else 
				return 0;
		}
		return curr->cp;
    }

    void erase(string &word){
        TrieNode* curr = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (curr->links[word[i] - 'a']){
				curr = curr->links[word[i] - 'a'];
				curr->cp--;
			}
			else
				return;
		}
		curr->eow--;
    }
};
