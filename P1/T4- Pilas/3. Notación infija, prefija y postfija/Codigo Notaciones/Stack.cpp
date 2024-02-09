/***********************************************************************
 * Module:  Stack.cpp
 * Author:  Edison Verdesoto
 * Modified: viernes, 19 de diciembre de 2023 15:05:38 a. m.
 * Purpose: Implementation of the class Stack
 ***********************************************************************/

#include "Stack.h"
#include "Node.cpp"
#include <iostream>

template <typename T>
Stack<T>::Stack(){
    this->top = nullptr;
}

template <typename T>
Stack<T>::Stack(Node<T>* top){
    this->top = top;
}

template <typename T>
void Stack<T>::set_top(Node<T>* top){
    this->top = top;
}

template <typename T>
Node<T>* Stack<T>::get_top(){
    return top;
}

template <typename T>
void Stack<T>::aggregate(T value){
    Node<T>* new_node = new Node<T>(value, nullptr);
    if(top == nullptr){
        top = new_node;
    }else{
        new_node->set_below(top);
        top = new_node;
    }
}

template <typename T>
void Stack<T>::aggregate(Node<T>* new_node){
    if(top == nullptr){
        new_node->set_below(nullptr);
        top = new_node;
    }else{
        new_node->set_below(top);
        top = new_node;
    }
}

template <typename T>
void Stack<T>::print(){
    if(is_stack_void()){
        printf("La pila esta vacia.\n");
    }
    else{
        Node<T>* aux = top;
        while(aux!=nullptr){
            std::cout<<aux->get_value()<<"\n";
            aux = aux->get_below();
        }
    }
}

template <typename T>
bool Stack<T>::is_stack_void(){
    if(top == nullptr){
        return true;
    }else{
        return false;
    }
}

template <typename T>
void Stack<T>::remove_top(){
    if(is_stack_void()){
        printf("La pila esta vacia.\n");
    }else{
        Node<T>* aux = top;
        if(top->get_below() == nullptr){
            top = nullptr;
        }else{
            top = top->get_below();
        }
        delete aux;
    }
}

template <typename T>
Node<T>* Stack<T>::take_off(){
    if(is_stack_void()){
        printf("La pila esta vacia.\n");
    }else{
        Node<T>* aux = top;
        if(top->get_below() == nullptr){
            top = nullptr;
        }else{
            top = top->get_below();
        }
        aux->set_below(nullptr);
        return aux;
    }
}

template <typename T>
void Stack<T>::remove_all(){
    if(!is_stack_void()){
        Node<T>* aux = top;
        if(top->get_below() == nullptr){
            top = nullptr;
        }else{
            top = top->get_below();
        }
        delete aux;
        remove_all();
    }
}

