#include "array_based_vector.hpp"

IntVector::IntVector(int capacity = 4) {
    // Non-zero capacity required
    if (capacity < 1) {
        throw std::out_of_range;
    }
    // Array contains size + items
    int array[capacity+1];
    // Set size = 0
    int *ptr = &array;
    *ptr = 0;
}

// WIP: May need to manually delete array, idk
IntVector::~IntVector() {
    // WIP
}

int IntVector::size() {
    // Pointer to array and thus size
    intr *ptr = &array;
    return *ptr;
}
inline int IntVector::capacity() { return capacity; }
inline bool IntVector::isEmpty() { return size() == 0 ? true : false; }

inline void IntVector::prepend(int item) { insert(0, item); }
inline void IntVector::push(int item) { insert(size(), item); }

// WIP: Actual insertion and shuffling right-items right
void IntVector::insert(int index, int item) {
    // Index must be in range (0 to size)
    if (not (0 <= index <= size())) {
        throw std::out_of_range;
    }
    // Resize if full
    if (size() >= capacity()) {
        int new_cap = capacity() * 2;
        resize(new_cap);
    }
    // Pointer starts at chosen index
    int *ptr = &array;
    ptr += index+1;
    // WIP
}

inline int IntVector::pop() { del(size()-1); }

// WIP: Actual deletion and shuffling right-items left
int IntVector::del(int index) {
    // Index must be in range (0 to size-1)
    if (not (0 <= index <= size()-1)) {
        throw std::out_of_range;
    }
    // Pointer starts at chosen index
    int *ptr = &array;
    ptr += index+1;
    // WIP
}

int IntVector::remove(int item) {
    // Find index of item and then delete it if found
    int index = find(item);
    if (index == -1) {
        return -1;
    }
    return del(index);
}

int IntVector::find(int item) {
    // Pointer starts at 0
    int *ptr = &array;
    ptr += 1;
    // Remember current index and size
    int index = 0;
    int list_size = size()

    // Linear search of list
    while (index < list_size) {
        // Return current index if found
        if (*ptr == item) {
            return index;
        }
        // Else, Go to next item
        ptr += 1;
        index += 1;
    }

    // Item not found, return -1
    return -1;
}

// WIP: Create new array and copy items (maybe return address as new array)
void IntVector::resize(int new_capacity) {
    // WIP
}
