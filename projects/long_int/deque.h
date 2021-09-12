#ifndef Deque_H
#define Deque_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Deque{
	private:
	struct Node{
		T val;
		Node* prev;
        Node* next;
	};
	
	Node* head;
	Node* tail;
	
	public:
	Deque();
	Deque(const Deque& rhs);
	~Deque();
	
	bool isEmpty() const;                // checks if a Deque is empty.
	int size() const;                    // retrieves # Deque Nodes
	const T &getFront() const;           // retrieve the front Node
	const T &getBack() const;            // retrieve the tail Node
	
	void clear();                              // clean up all Deque entries.
	void addFront(const T& obj);         // add a new Node to the front
	void addBack(const T& obj);          // add a new Node to the tail
	T removeFront();                      // remove the front Node
	T removeBack();                       // remove the tail Node
    Deque& operator=(const Deque& rhs);
	
};

template<typename T>
Deque<T>::Deque(){
	head = new Node;
	tail = new Node;
	head-> next = tail;
	tail-> prev = head;
}

template<typename T>
Deque<T>::Deque(const Deque& rhs){

	head = new Node;
	tail = new Node;
	head-> next = tail;
	tail-> prev = head;
	if (this == &rhs){
		return;
	}

    Node* current = rhs.head-> next;
    while(current != rhs.tail){
        addBack(current->val);
        current = current-> next;
    }
	
}

template<typename T>
Deque<T>::~Deque(){
	clear();
	delete head;
	delete tail;
}

template<typename T>
bool Deque<T>::isEmpty() const{
	return size() == 0;
}

template<typename T>
int Deque<T>::size() const{
	Node* current = head-> next;
	int count{0};
	while(current != tail){
		current = current-> next;
		count++;
	}
	
	return count;
}

template<typename T>
const T& Deque<T>::getFront() const{
	if (isEmpty()){
		throw invalid_argument("Deque is empty");
	}
	
	return head-> next-> val;
}

template<typename T>
const T& Deque<T>::getBack() const{
	if (isEmpty()){
		throw invalid_argument("Deque is empty");
	}
	
	return tail -> prev -> val;
}
template<typename T>
void Deque<T>::clear(){
	Node* current = head -> next;
	while (current != tail){
		Node* trash = current;
		current = current -> next;
		delete trash;
	}
	head-> next = tail;
	tail-> prev = head;
}

template<typename T>
void Deque<T>::addFront(const T& obj){
	Node* new_node = new Node{obj, head, head-> next};
	head->next-> prev = new_node;
	head -> next = new_node;
}

template<typename T>
void Deque<T>::addBack(const T& obj){
    Node* new_node = new Node{obj, tail-> prev, tail};
	tail-> prev -> next = new_node;
    tail-> prev = new_node;
    
}

template<typename T>
T Deque<T>::removeFront(){
        if (isEmpty()){
            throw invalid_argument("deque is empty");
        }

        T result = head-> next-> val;
        Node* trash = head-> next;
        head-> next = trash-> next;
        head->next->prev = head;
        delete trash;
        return result;
    }   

template<typename T>    
T Deque<T>::removeBack(){
    if (isEmpty()){
        throw invalid_argument("deque is empty");
    }

    T result = tail -> prev -> val;
    Node* trash = tail -> prev;
	trash-> prev -> next = tail;
	tail-> prev = trash-> prev;
	delete trash;
	return result;


}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque& rhs){

    if(this == &rhs || rhs.head == nullptr){
        return *this;
    }
    
   clear();
    Node* current = rhs.head-> next;
    while(current != nullptr && current != rhs.tail){
        addBack(current->val);
        current = current-> next;
    }

    return *this;
}



#endif
