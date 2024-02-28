#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iostream>
using namespace std;

template <class Type>
struct Node
{
    Type data;
    Node *next;
};

template <class Type>
class Stack;

template <class Type>
std::ostream& operator<<(std::ostream&, const Stack<Type>& stack);


template <class Type>
class Stack
{
protected:
    Node<Type>* top_;
    int count;
public:
    Stack();
    Stack(const Stack& other);
    Stack<Type>& operator=(const Stack<Type>& other);
    ~Stack();
    int size() const;
    bool empty() const;
    Type top() const;
    void push(const Type&);
    void pop();
    void pop(int n);
    Type topPop();
    void clear();
    friend std::ostream& operator<< <>(std::ostream&, const Stack<Type>& list);
};

template <class Type>
Stack<Type>::Stack()
{
    top_ = nullptr;
    count = 0;
}

template <class Type>
Stack<Type>::Stack(const Stack<Type>& other)
{
    //create temp node
    Node<Type>* temp = nullptr;
    //set count
    count = other.count;
    //set top to null
    top_ = nullptr;
    //create new temp Node to other.top
    Node<Type>* newTemp = other.top_;
    for(int i = 0; i < count; i++){
        //if other.top == null, break
        if(newTemp == nullptr){
            break;
        }
        //create node
        auto node = new Node<Type>();
        //set data from newTemp (which has other.top)
        node->data = newTemp->data;
        //set next to null
        node->next = nullptr;
        //if newTemp == top
        if(newTemp == other.top_){
            //top will become the new node
            top_ = node;
        }//else the next will be the node
        else{
            temp->next = node;
        }
        //set temp to node
        temp = node;
        // go to next newTemp
        newTemp = newTemp->next;
    }

}

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& other)
{
    //same as copy, just clear and return *this
    clear();
    //create temp node
    Node<Type>* temp = nullptr;
    //set count
    count = other.count;
    //set top to null
    top_ = nullptr;
    //create new temp Node to other.top
    Node<Type>* newTemp = other.top_;
    for(int i = 0; i < count; i++){
        //if other.top == null, break
        if(newTemp == nullptr){
            break;
        }
        //create node
        auto node = new Node<Type>();
        //set data from newTemp (which has other.top)
        node->data = newTemp->data;
        //set next to null
        node->next = nullptr;
        //if newTemp == top
        if(newTemp == other.top_){
            //top will become the new node
            top_ = node;
        }//else the next will be the node
        else{
            temp->next = node;
        }
        //set temp to node
        temp = node;
        //go to next newTemp
        newTemp = newTemp->next;
    }
    return *this;
}

template <class Type>
Stack<Type>::~Stack()
{
    //call clear
    clear();
}

template <class Type>
int Stack<Type>::size() const
{
    //return count
    return count;
}

template <class Type>
bool Stack<Type>::empty() const
{
    //if count = 0, true
    if(count == 0){
        return true;
    }else{
        return false;
    }
}

template <class Type>
Type Stack<Type>::top() const
{
    //returns data from top
    if(count == 0){
        throw std::logic_error("Stack is empty");
    }

    return top_->data;
}

template <class Type>
void Stack<Type>::push(const Type& item)
{
    //had to change this
    //create temp
    auto *temp = new Node<Type>;
    //set data in temp to the item
    temp->data = item;
    //set the next position to the top
    temp->next = top_;
    //set the top to temp
    top_ = temp;
    count++;
}

template <class Type>
void Stack<Type>::pop()
{
    //if count isn't 0
    if(count != 0){
        //temp = top
        auto temp = top_;
        //next top will be the new top
        top_ = top_->next;
        //delete temp for memory
        delete temp;
        count--;
    }

}

template <class Type>
void Stack<Type>::pop(int n)
{
    //loop through n times and pop
    for(int i = 0; i < n; i++){
        //if not n items, remove until empty
        if(i == count && empty()){
            return;
        }
        pop();
    }
}

template <class Type>
Type Stack<Type>::topPop()
{
    if(count == 0){
        throw logic_error("Stack is empty");
    }
    //temp = data from top
    auto temp = top_->data;
    //pop the top
    pop();
    //return the data
    return temp;

}

template <class Type>
void Stack<Type>::clear()
{
    //while top isn't null
    while(top_ != nullptr){
        //set temp to top
        Node<Type> *temp = top_;
        //top is next node
        top_ = top_->next;
        //delete temp
        delete temp;
    }
    //set count to 0
    count = 0;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const Stack<Type>& list)
{
    //if list empty, print empty
    if(list.empty()){
        out << "";
        return out;
    }
    //if list size is 1, print the node
    if(list.size() == 1){
        out << list.top();
        return out;
    }//else print off the whole stack
    else{
        Stack<Type> other(list);
        other.pop();
        Type temp = list.top();
        out << other << "->" << temp;
        return out;
    }

}
#endif