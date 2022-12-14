#include "catch2/catch_all.hpp"
#include "solution.h"
#include "Heap.hpp"

using namespace std;

TEST_CASE("Validate Heap") {

    Heap<int> heap;
    CHECK(heap.isEmpty() == true);
    for (int i = 100; i >= 10; i--) {
        heap.insert(i);
        CHECK(heap.isEmpty() == false);
    }
    CHECK(heap.getTop() == 10);
    for (int i = 10; i <= 100; i++) {
        heap.removeTop();
        if (i != 100) {
            CHECK(heap.getTop() == (i + 1));
        }
    }
    CHECK(heap.isEmpty() == true);
}


TEST_CASE("Validate Trie") {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("one");
    trie.insert("two");
    trie.insert("asdasdasdasd");
    trie.insert("asdasdasdasdasd");

    CHECK(trie.search("hello"));
    CHECK(trie.search("asdasdasdasd"));
    CHECK_FALSE(trie.search("nothing"));
    CHECK_FALSE(trie.search("worl"));
    CHECK_FALSE(trie.search("asdasdasdasdas"));
}