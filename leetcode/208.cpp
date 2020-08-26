/*
Implement Trie (Prefix Tree)
Medium

1563

31

Favorite

Share
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
#include "header.h"

class Trie {
   private:
    class TrieNode {
       private:
        vector<unique_ptr<TrieNode>> children;
        bool word;

       public:
        TrieNode() : children(26), word(false) {}

        // add node "c" to children
        void addNode(char c) {
            if (!hasNode(c)) {
                children[c - 'a'] = make_unique<TrieNode>();
            }
        }

        // return if "c" is a child
        bool hasNode(char c) const { return bool(children[c - 'a']); }

        // return a child
        const unique_ptr<TrieNode>& getNode(char c) const { return children[c - 'a']; }

        // set the node to be the ending of a word
        void setWord() { word = true; }

        // return if the node ends a word
        bool isWord() const { return word; }
    };

    unique_ptr<TrieNode> root;

   public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = root.get();
        for (auto c : word) {
            node->addNode(c);
            node = node->getNode(c).get();
        }
        node->setWord();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto endNode = findNode(word);
        return endNode != nullptr && endNode->isWord();
    }

    // return the ending node of the specified prefix or nullptr if the prefix not found
    const TrieNode* findNode(string prefix) const{
        auto found = true;
        auto node = root.get();
        for (auto c : prefix) {
            if (node->hasNode(c)) {
                node = node->getNode(c).get();
            } else {
                found = false;
                break;
            }
        }

        return found ? node : nullptr;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return findNode(prefix) != nullptr;
    }
};

int main(){}