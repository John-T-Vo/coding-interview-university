struct IntVector {
    int capacity;
    int *array;

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