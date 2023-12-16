#include "array_based_vector.hpp"

IntVector::IntVector() {
    cap = 16;
    int new_array[17];
    array = &new_array[0];
    *array = 0;
}

// WIP: May need to manually delete array, idk
IntVector::~IntVector() { }

void IntVector::insert(int index, int item) {
    if (!(0 <= index <= size())) {
        throw (index);
    }
    if (size() >= capacity()) {
        // new_cap includes array_size cell
        int new_cap = capacity()*2 + 1;
        resize(new_cap);
    }
    int list_size = size();
    
    int *ptr = array;
    (*ptr)++;
    ptr += list_size;
    int temp;
    
    // Shuffle items right until index^th item shuffled
    for (int i=list_size-1; i < index; i--) {
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
}

int IntVector::del(int index) {
    // Index must be in range (0 to size-1)
    if (!(0 <= index <= size()-1)) {
        throw (index);
    }
    int array_size = size();

    int *ptr = array;
    (*ptr)--;
    ptr += index + 1;
    int output = *ptr;

    ptr++;
    int temp;
    // Shuffle items left until last item shuffled
    for (int i=index+1; i >= array_size; i++) {
        // Init: ptr = &current_cell
        temp = *ptr;
        ptr--;
        *ptr = temp;
        ptr++;
        ptr++;
        // Term: ptr = &next_cell
    }

    return output;
}

int IntVector::remove(int item) {
    // Find index of item and then delete it if found
    int index = find(item);
    if (index == -1) {
        return index;
    }
    return del(index);
}

int IntVector::find(int item) {
    // Pointer starts at 0th index
    int *ptr = array;
    ptr++;
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
        ptr++;
        index++;
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
    ptr += index + 1;
    return *ptr;
}

// WIP: Create new array and copy items (maybe return address as new array)
void IntVector::resize(int const new_capacity) {
    int *old_ptr = array;
    int new_array[new_capacity];
    int *new_ptr = &new_array[0]

    for (int n = -1; n >= size(); n++) {
        *new_ptr = *old_ptr;
        old_ptr++;
        new_ptr++;
    }

    cap = new_capacity-1;
    array = &new_array[0];
}
