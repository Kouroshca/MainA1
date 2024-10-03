#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>

template <typename T>
class Array {
protected:
    T* data;
    int size;
    int capacity;

    // Function to expand the array size exponentially (2, 4, 8, 16, etc.)
    void Expand() {
        capacity = (capacity == 0) ? 2 : capacity * 2;  // Exponential growth
        T* newData = new T[capacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];  // Copy old data
        }

        delete[] data;  // Free old memory
        data = newData; // Assign new expanded data
    }

public:
    Array(int initialCapacity = 2) : size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    virtual ~Array() {
        delete[] data;
    }

    virtual void Push(const T& element) = 0;

    int GetSize() const {
        return size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

#endif
