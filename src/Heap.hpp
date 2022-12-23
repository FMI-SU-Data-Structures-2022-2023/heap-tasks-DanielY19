#ifndef WEEK7_HEAP_H

#include <vector>

template<class T>
class Heap {
private:
    std::vector<T> array;
public:
    const T &getTop() {
        return this->array.at(0);
    }

    void insert(const T &key) {
        this->array.push_back(key);
        this->shiftUp(this->array.size() - 1);
    };

    void removeTop() {
        this->array.at(0) = this->array.back();
        this->array.pop_back();
        this->shiftDown(0);
    }

    bool isEmpty() {
        return this->array.size() == 0;
    }

    Heap &operator=(const Heap<T> &other) = delete;

    ~Heap() {};

private:
    void shiftUp(std::size_t index) {
        int parent = (index - 1) / 2;
        while (index > 0 && this->array.at(index) < this->array.at(parent)) {
            std::swap(this->array.at(index), this->array.at(parent));
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void shiftDown(std::size_t index) {
        while (true) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int min = index;

            std::size_t size = this->array.size();

            if (left < size && this->array.at(left) < this->array.at(min))
                min = left;

            if (right < size && this->array.at(right) < this->array.at(min))
                min = right;

            if (min == index)
                break;

            std::swap(this->array.at(index), this->array.at(min));
            index = min;
        }
    }
};

#define WEEK7_HEAP_H

#endif //WEEK7_HEAP_H
