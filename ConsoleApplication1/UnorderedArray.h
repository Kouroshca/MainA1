// UnorderedArray.h
#ifndef UNORDEREDARRAY_H
#define UNORDEREDARRAY_H

#include "Array.h"

template <typename T>
class UnorderedArray : public Array<T> {
public:
    UnorderedArray(int initialCapacity = 2) : Array<T>(initialCapacity) {}

    void Push(const T& element) override {
        if (this->size >= this->capacity) {
            this->Expand();
        }
        this->data[this->size++] = element;
    }
};

#endif
