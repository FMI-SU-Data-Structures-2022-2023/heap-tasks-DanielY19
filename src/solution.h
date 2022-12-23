#ifndef WEEK7_TREE_H

class Trie {
private:
    struct Node {
        const static size_t MAX_ALPHABET = 26;

        bool isWord;
        Node *next[26];

        Node() : isWord(false) {
            this->null();
        }

        static void insert(const char *, Node *);

        static bool search(const char *, Node *);

        static void destroy(Node *);

        void null();
    };

    Node *start;
public:
    Trie() : start(new Node) {}

    void insert(const char *);

    bool search(const char *);

    Trie &operator=(const Trie &other) = delete;

    ~Trie();
};

#define WEEK7_TREE_H

#endif //WEEK7_TREE_H
