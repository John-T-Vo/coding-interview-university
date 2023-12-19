struct IntVector {
    int cap;
    int list_size;
    int *items;

    public:
        IntVector();
        ~IntVector();

        int size();
        int capacity();
        bool isEmpty();

        int at(int index);
        void prepend(int item);
        void push(int item);
        void insert(int index, int item);
        int pop();
        int del(int index);
        int remove(int item);
        int find(int item);
    
    private:
        void resize(int new_capacity);
};

inline int IntVector::size() {
    return list_size;
}
inline int IntVector::capacity() {
    return cap;
}
inline bool IntVector::isEmpty() {
    return size() == 0 ? true : false;
}

inline void IntVector::prepend(int item) {
    insert(0, item);
}
inline void IntVector::push(int item) {
    insert(size(), item);
}
inline int IntVector::pop() {
    return del(size()-1);
}
