#ifndef ORDEREDARRAY_H
#define ORDEREDARRAY_H

#include "Array.h"

template <typename T>
class OrderedArray : public Array<T> {
private:
    bool allowDuplicates;

    // Helper function to check if element already exists (for duplicates)
    bool Contains(const T& element) {
        for (int i = 0; i < this->size; ++i) {
            if (this->data[i] == element) {
                return true;
            }
        }
        return false;
    }

public:
    // Constructor allows setting whether duplicates are allowed
    OrderedArray(int initialCapacity = 2, bool allowDuplicatesFlag = true)
        : Array<T>(initialCapacity), allowDuplicates(allowDuplicatesFlag) {}

    void Push(const T& element) override {
        // If duplicates are not allowed, check if the element already exists
        if (!allowDuplicates && Contains(element)) {
            return;  // Do not insert duplicate
        }

        if (this->size >= this->capacity) {
            this->Expand();
        }

        // Insert element in sorted order
        int i;
        for (i = this->size - 1; i >= 0 && this->data[i] > element; --i) {
            this->data[i + 1] = this->data[i];  // Shift elements to the right
        }

        this->data[i + 1] = element;  // Insert the new element in sorted position
        ++this->size;
    }
};

#endif
