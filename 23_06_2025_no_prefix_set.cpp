#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    bool isWord;
    TrieNode* children[26];

    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

bool insert(TrieNode* root, const string& word) {
    TrieNode* curr = root;
    bool prefixExists = false;

    for (char c : word) {
        int index = c - 'a';
        if (!curr->children[index]) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
        if (curr->isWord) {
            prefixExists = true;
            break;
        }
    }

    if (curr->children[0] != nullptr || curr->children[1] != nullptr || curr->children[2] != nullptr ||
        curr->children[3] != nullptr || curr->children[4] != nullptr || curr->children[5] != nullptr ||
        curr->children[6] != nullptr || curr->children[7] != nullptr || curr->children[8] != nullptr ||
        curr->children[9] != nullptr || curr->children[10] != nullptr || curr->children[11] != nullptr ||
        curr->children[12] != nullptr || curr->children[13] != nullptr || curr->children[14] != nullptr ||
        curr->children[15] != nullptr || curr->children[16] != nullptr || curr->children[17] != nullptr ||
        curr->children[18] != nullptr || curr->children[19] != nullptr || curr->children[20] != nullptr ||
        curr->children[21] != nullptr || curr->children[22] != nullptr || curr->children[23] != nullptr ||
        curr->children[24] != nullptr || curr->children[25] != nullptr) {
        if (!prefixExists) {
            curr->isWord = true;
        }
    }
    else {
        if (!prefixExists) {
            curr->isWord = true;
        }
    }
    
    return prefixExists || (curr->children[0] != nullptr || curr->children[1] != nullptr || curr->children[2] != nullptr ||
        curr->children[3] != nullptr || curr->children[4] != nullptr || curr->children[5] != nullptr ||
        curr->children[6] != nullptr || curr->children[7] != nullptr || curr->children[8] != nullptr ||
        curr->children[9] != nullptr || curr->children[10] != nullptr || curr->children[11] != nullptr ||
        curr->children[12] != nullptr || curr->children[13] != nullptr || curr->children[14] != nullptr ||
        curr->children[15] != nullptr || curr->children[16] != nullptr || curr->children[17] != nullptr ||
        curr->children[18] != nullptr || curr->children[19] != nullptr || curr->children[20] != nullptr ||
        curr->children[21] != nullptr || curr->children[22] != nullptr || curr->children[23] != nullptr ||
        curr->children[24] != nullptr || curr->children[25] != nullptr);
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    TrieNode* root = new TrieNode();
    string badWord = "";
    bool found = false;

    for (int i = 1; i <= n; ++i) {
        string word;
        getline(cin, word);

        if (insert(root, word)) {
            badWord = word;
            found = true;
            break;
        }
    }

    if (found) {
        cout << "BAD SET" << endl;
        cout << badWord << endl;
    } else {
        cout << "GOOD SET" << endl;
    }

    return 0;
}