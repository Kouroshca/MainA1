#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"

int main() {
    // Unordered array test
    UnorderedArray<int> unorderedArray;
    unorderedArray.Push(5);
    unorderedArray.Push(2);
    unorderedArray.Push(8);

    std::cout << "Unordered array: ";
    for (int i = 0; i < unorderedArray.GetSize(); ++i) {
        std::cout << unorderedArray[i] << " ";
    }
    std::cout << std::endl;

    // Ordered array test without duplicates
    OrderedArray<int> orderedArray(2, false);  // Prevent duplicates
    orderedArray.Push(3);
    orderedArray.Push(1);
    orderedArray.Push(3);  // Duplicate, should not be added
    orderedArray.Push(2);

    std::cout << "Ordered array (no duplicates): ";
    for (int i = 0; i < orderedArray.GetSize(); ++i) {
        std::cout << orderedArray[i] << " ";
    }
    std::cout << std::endl;

    // Ordered array test with duplicates
    OrderedArray<int> orderedArrayWithDupes(2, true);  // Allow duplicates
    orderedArrayWithDupes.Push(3);
    orderedArrayWithDupes.Push(1);
    orderedArrayWithDupes.Push(3);  // Duplicate, will be added
    orderedArrayWithDupes.Push(2);

    std::cout << "Ordered array (with duplicates): ";
    for (int i = 0; i < orderedArrayWithDupes.GetSize(); ++i) {
        std::cout << orderedArrayWithDupes[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
