#include "array_based_vector.hpp"
#include <iostream>

IntVector::IntVector() {
    cap = 16;
    int new_array[16];
    items = new_array;
    list_size = 0;
}

// WIP: May need to manually delete array, idk
IntVector::~IntVector() { }

void IntVector::insert(int index, int item) {
    try {
        if (!((0 <= index)&&(index <= size()))) {
            throw (index);
        }
        if (size() >= capacity()) {
            int new_cap = capacity()*2;
            resize(new_cap);
        }
    
        int *ptr = items;
        ptr += size()-1;
        int temp;
        
        // Shuffle items right until index^th item shuffled
        for (int i=size()-1; i >= index; i--) {
            // Init: ptr = &current_cell
            temp = *ptr;
            ptr++;
            *ptr = temp;
            ptr--;
            ptr--;
            // Term: ptr = &prev_cell
        }
        ptr++;
        *ptr = item;
        list_size++;
    }
    catch (int index) {
        std::cout << "Cannot insert, index " << index << " is out of range.\n";
    }
}

int IntVector::del(int index) {
    try {
        // Index must be in range (0 to size-1)
        if (!((0 <= index)&&(index <= size()-1))) {
            throw (index);
        }

        int *ptr = items;
        ptr += index+1;
        int output = *ptr;

        ptr++;
        int temp;
        // Shuffle items left until last item shuffled
        for (int i=index+1; i < list_size; i++) {
            // Init: ptr = &current_cell
            temp = *ptr;
            ptr--;
            *ptr = temp;
            ptr++;
            ptr++;
            // Term: ptr = &next_cell
        }

        list_size--;
        return output;
    }
    catch (int index) {
        std::cout << "Cannot delete, index " << index << " is out of range.\n";
        return 0;
    }
}

int IntVector::remove(int item) {
    int index = find(item);
    if (index == -1) {
        return index;
    }
    return del(index);
}

int IntVector::find(int item) {
    // Pointer starts at 0th index
    int *ptr = items;
    int index = 0;

    // Linear search of list
    while (index < list_size) {
        // Return current index if found
        if (*ptr == item) {
            return index;
        }
        // Else, Go to next item
        ptr++;
        index++;
    }

    // Item not found, return -1
    return -1;
}

int IntVector::at(int index) {
    try {
        // Index must be in range (0 to size-1)
        if (!((0 <= index)&&(index <= size()-1))) {
            throw (index);
        }
        // Pointer goes to chosen index
        int *ptr = items;
        ptr += index;
        return *ptr;
    }
    catch (int index) {
        std::cout << "Cannot return item, index " << index << " is out of range.\n";
        return -1;
    }
}

// WIP: Create new array and copy items (maybe return address as new array)
void IntVector::resize(int const new_capacity) {
    int *old_ptr = items;
    int new_array[new_capacity];
    int *new_ptr = new_array;

    for (int n = -1; n < list_size; n++) {
        *new_ptr = *old_ptr;
        old_ptr++;
        new_ptr++;
    }

    cap = new_capacity;
    items = new_array;
}
