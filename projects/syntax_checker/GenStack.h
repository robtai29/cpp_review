#include <iostream>
#include <stdexcept> 


template <class Item>
class GenStack{
    private:
    inline static const int INITIAL_CAPACITY = 5;
    Item* arr = nullptr;
    int size_;
    int capacity_;
    void clear();
    void expand();
    public:
    GenStack(int capacity_ = INITIAL_CAPACITY);
    ~GenStack();
    void push(const Item&);
    bool empty();
    int size();
    void pop();
    Item top();


};

template <class Item>
GenStack<Item>::GenStack(int capacity){
    capacity_ = capacity;
    size_ = 0;
    arr = new Item[capacity];
}

template <class Item>
GenStack<Item>::~GenStack(){
    clear();
}

template <class Item>
void GenStack<Item>::clear(){
    delete [] arr;
    arr = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template <class Item>
void GenStack<Item>::push(const Item& item){
    if (size_ == capacity_){
        expand();
    }
    arr[size_] = item;
    size_++;
}

template <class Item>
void GenStack<Item>::expand(){
    int newCap = capacity_ * 2;
    Item* newArr = new Item[newCap];
    for (int i = 0; i < size_; i++){
        newArr[i] = arr[i];
    }

    delete [] arr;
    arr = newArr;
    newArr = nullptr;
    capacity_ = newCap;
}

template <class Item>
bool GenStack<Item>::empty(){
    return size_ == 0;
}

template <class Item>
int GenStack<Item>::size(){
    return size_;
}

template <class Item>
Item GenStack<Item>::top(){
    if (size_ == 0){
        throw std::invalid_argument("empty stack");
    }

    return arr[size_-1];
}

template <class Item>
void GenStack<Item>::pop(){
    if (size_ == 0){
        throw std::invalid_argument("empty stack");
    }

    size_--;
}

