#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"

int main() {
    std::cout << "Unordered Array Example:" << std::endl;
    UnorderedArray<int> unorderedArray;
    unorderedArray.Push(10);
    unorderedArray.Push(5);
    unorderedArray.Push(20);
    unorderedArray.Print();  // Should print: 10 5 20

    std::cout << "\nOrdered Array Example (Allow Duplicates):" << std::endl;
    OrderedArray<int> orderedArray(false);  // Allow duplicates
    orderedArray.Push(10);
    orderedArray.Push(5);
    orderedArray.Push(20);
    orderedArray.Push(10);  // Duplicate allowed
    orderedArray.Print();  // Should print: 5 10 10 20

    std::cout << "\nOrdered Array Example (Prevent Duplicates):" << std::endl;
    OrderedArray<int> orderedArrayNoDupes(true);  // Prevent duplicates
    orderedArrayNoDupes.Push(10);
    orderedArrayNoDupes.Push(5);
    orderedArrayNoDupes.Push(20);
    orderedArrayNoDupes.Push(10);  // Duplicate prevented
    orderedArrayNoDupes.Print();  // Should print: 5 10 20

    return 0;
}
