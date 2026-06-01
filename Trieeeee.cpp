#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (!node->children[index])
                node->children[index] = new TrieNode();

            node = node->children[index];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (!node->children[index])
                return false;

            node = node->children[index];
        }

        return node->isEnd;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("banana");

    cout << trie.search("apple") << endl;
    cout << trie.search("orange") << endl;

    return 0;
}
