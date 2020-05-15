/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        char val;
        int count;
        int endsHere;
        TrieNode *child[26];   
    };
    TrieNode *root;
    TrieNode *getNode(int index){
        TrieNode *newNode = new TrieNode;
        newNode->val = 'a'+26;
        newNode->count = 0;
        newNode->endsHere = 0;
        for(int i = 0; i < 26; ++i)
            newNode->child[i] = NULL;
        return newNode;
    }
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getNode('/'-'a');
        
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int index;
        TrieNode *curr  = root;
        for(char c : word){
            index = c-'a';
            if(curr->child[index] == NULL){
                curr->child[index] = getNode(index);
            }
            curr->child[index]->count+=1;
            curr = curr->child[index];
        }
        curr->endsHere+=1;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        int index;
        for(char c : word){
            index = c-'a';
            if(curr->child[index] == NULL)
                return false;
            curr = curr->child[index];
        }
        if(curr->endsHere > 0)
            return true;
        return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        int index;
        for(char c : prefix){
            index = c-'a';
            if(curr->child[index] == NULL)
                return false;
            curr = curr->child[index];
        }
        
        return (curr->count > 0);
        
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
