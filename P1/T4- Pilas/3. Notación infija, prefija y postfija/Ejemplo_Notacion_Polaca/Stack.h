#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Node.h"


/***********************************************************************
 UFA - ESPE
 * Module: Stack.h
 * Author: Benavides Ruben
 * Modified: December 21, 2023
 * Purpose: Stack Class Declaration
 ***********************************************************************/

template <typename T>
class Stack{
private:
    Node<T>* top;
public:
    Stack();
    Stack(Node<T>*);
    void aggregate(T);
    void delete_of_stack();
    void set_top(Node<T>*);
    Node<T>* get_top();
    bool is_stack_void();
    void print_stack();
    int get_stack_size();
    void remove_all();
    void print_lineal_stack();
};

#endif // STACK_H_INCLUDED
