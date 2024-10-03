#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
protected:
    T* m_array;
    int m_size;
    int m_capacity;

    // Expands the array by powers of two: 2, 4, 8, etc.
    void Expand() {
        m_capacity = (m_capacity == 0) ? 2 : m_capacity * 2;
        T* newArray = new T[m_capacity];
        for (int i = 0; i < m_size; i++) {
            newArray[i] = m_array[i];
        }
        delete[] m_array;
        m_array = newArray;
    }

public:
    Array(int capacity = 2) : m_size(0), m_capacity(capacity) {
        m_array = new T[m_capacity];
    }

    virtual ~Array() {
        delete[] m_array;
    }

    virtual void Push(const T& value) = 0; // Pure virtual function for derived classes

    int Size() const {
        return m_size;
    }

    T operator[](int index) const {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of bounds");
        }
        return m_array[index];
    }

    void Print() const {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }
};
