#include "solution.h"

void Trie::Node::insert(const char *word, Node *traverse) {
    size_t index = *word - 'a';

    if (!traverse->next[index])
        traverse->next[index] = new Node;

    if (*(word + 1) == '\0') {
        traverse->next[index]->isWord = true;
        return;
    }

    return insert(++word, traverse->next[index]);
}

void Trie::insert(const char *word) {
    if (!word)
        return;

    Trie::Node::insert(word, this->start);
}

bool Trie::Node::search(const char *word, Node *traverse) {
    if (*word == '\0') {
        if (traverse->isWord)
            return true;
        else return false;
    }

    size_t index = *word - 'a';

    if (!traverse->next[index])
        return false;

    return search(++word, traverse->next[index]);
}

bool Trie::search(const char *word) {
    if (!word)
        return false;

    return Trie::Node::search(word, this->start);
}

void Trie::Node::destroy(Node *traverse) {
    for (size_t i = 0; i < Trie::Node::MAX_ALPHABET; i++) {
        if (traverse->next[i])
            destroy(traverse->next[i]);
    }
    delete traverse;
}

Trie::~Trie() {
    Trie::Node::destroy(this->start);
}

void Trie::Node::null() {
    for (size_t i = 0; i < Trie::Node::MAX_ALPHABET; i++)
        this->next[i] = nullptr;
}
