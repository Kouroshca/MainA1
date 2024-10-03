#pragma once
#include "Array.h"

template <typename T>
class OrderedArray : public Array<T> {
private:
    bool m_preventDuplicates;

    bool Contains(const T& value) const {
        for (int i = 0; i < this->m_size; i++) {
            if (this->m_array[i] == value) {
                return true;
            }
        }
        return false;
    }

public:
    OrderedArray(bool preventDuplicates = false, int capacity = 2)
        : Array<T>(capacity), m_preventDuplicates(preventDuplicates) {}

    // Inserts in an ordered manner, preventing duplicates if the flag is set
    void Push(const T& value) override {
        if (this->m_size >= this->m_capacity) {
            this->Expand();
        }

        if (m_preventDuplicates && Contains(value)) {
            std::cout << "Duplicate value prevented: " << value << std::endl;
            return;
        }

        int i;
        for (i = this->m_size - 1; (i >= 0 && this->m_array[i] > value); i--) {
            this->m_array[i + 1] = this->m_array[i];
        }
        this->m_array[i + 1] = value;
        this->m_size++;
    }
};
