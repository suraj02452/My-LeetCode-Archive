class Trie {
    struct Node {
        Node* next[26] = {nullptr};
        bool isEnd = false;
    };
    Node* root;

    Node* find(const string& s) {
        Node* node = root;
        for (char c : s) {
            node = node->next[c - 'a'];
            if (!node) return nullptr;
        }
        return node;
    }

public:
    Trie() : root(new Node()) {}

    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->next[i]) node->next[i] = new Node();
            node = node->next[i];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = find(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};