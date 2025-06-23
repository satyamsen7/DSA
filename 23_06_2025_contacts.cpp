#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int count;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        count = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void add(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
            current->count++;
        }
    }

    int find(const string& prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!current->children[index]) {
                return 0;
            }
            current = current->children[index];
        }
        return current->count;
    }
};

int main() {
    int n;
    cin >> n;

    Trie trie;

    for (int i = 0; i < n; ++i) {
        string operation, contact;
        cin >> operation >> contact;

        if (operation == "add") {
            trie.add(contact);
        } else if (operation == "find") {
            cout << trie.find(contact) << endl;
        }
    }

    return 0;
}