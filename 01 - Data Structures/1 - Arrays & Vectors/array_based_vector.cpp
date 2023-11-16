#include "array_based_vector.hpp"

IntVector::IntVector() {
    // Default capacity is 4
    this->capacity = 4;
    // Default size is 5 (4 + size value)
    int new_array[5];
    this->array = &new_array[0];
    // Set size = 0
    *array = 0;
}

// WIP: May need to manually delete array, idk
IntVector::~IntVector() { }

inline int IntVector::size() { return *array; }
inline int IntVector::capacity() { return this->capacity; }
inline bool IntVector::isEmpty() { return size() == 0 ? true : false; }

inline void IntVector::prepend(int item) { insert(0, item); }
inline void IntVector::push(int item) { insert(size(), item); }

// WIP: Actual insertion and shuffling right-items right
void IntVector::insert(int index, int item) {
    // Index must be in range (0 to size)
    if (!(0 <= index <= size())) {
        throw (index);
    }
    // Resize if full
    if (size() >= capacity()) {
        int new_cap = capacity() * 2;
        resize(new_cap);
    }
    // Pointer starts at chosen index
    int *ptr = array;
    ptr += index*32 + 32;
    // WIP
}

inline int IntVector::pop() { del(size()-1); }

// WIP: Actual deletion and shuffling right-items left
int IntVector::del(int index) {
    // Index must be in range (0 to size-1)
    if (!(0 <= index <= size()-1)) {
        throw (index);
    }
    // Pointer starts at chosen index
    int *ptr = array;
    ptr += index*32 + 32;
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
    // Pointer starts at 0th index
    int *ptr = array;
    ptr += 32;
    // Remember current index and size
    int index = 0;
    int list_size = size();

    // Linear search of list
    while (index < list_size) {
        // Return current index if found
        if (*ptr == item) {
            return index;
        }
        // Else, Go to next item
        ptr += 32;
        index += 1;
    }

    // Item not found, return -1
    return -1;
}

int IntVector::at(int index) {
    // Index must be in range (0 to size-1)
    if (!(0 <= index <= size()-1)) {
        throw (index);
    }
    // Pointer goes to chosen index
    int *ptr = array;
    ptr += index*32 + 32;
    return *ptr;
}

// WIP: Create new array and copy items (maybe return address as new array)
void IntVector::resize(int new_capacity) {
    // WIP
}
