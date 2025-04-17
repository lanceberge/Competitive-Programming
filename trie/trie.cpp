#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
  vector<TrieNode *> children;
  bool isWord;

  TrieNode() {
    children = vector<TrieNode *>(26, nullptr);
    isWord = false;
  }
};

/**
   Trie to store lowercase words only
*/
class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *p = root;

    for (char &c : word) {
      int i = c - 'a';

      if (!p->children[i]) {
        p->children[i] = new TrieNode();
      }

      p = p->children[i];
    }

    p->isWord = true;
  }

  bool search(string word) {
    TrieNode *p = root;

    for (char &c : word) {
      int i = c - 'a';

      if (!p->children[i])
        return false;

      p = p->children[i];
    }

    return p->isWord;
  }

  bool startsWith(string prefix) {
    TrieNode *p = root;

    for (char &c : prefix) {
      int i = c - 'a';

      if (!p->children[i])
        return false;

      p = p->children[i];
    }

    return true;
  }
};
