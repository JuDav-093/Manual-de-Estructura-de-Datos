#include "Stack.h"
#include "Node.cpp"
#include <iostream>


/***********************************************************************
 UFA - ESPE
 * Module: Stack.cpp
 * Author: Benavides Ruben
 * Modified: December 21, 2023
 * Purpose: Stack Class Implementation
 ***********************************************************************/

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
bool Stack<T>::is_stack_void(){
    if(top == nullptr){
        return true;
    }else{
        return false;
    }
}

template <typename T>
void Stack<T>::delete_of_stack(){
    if(is_stack_void()){
        printf("La pila esta vacia.\n");
    }else{
        Node<T>* aux = top;
        top = top->get_below();
        aux->set_below(nullptr);
    }
}

template <typename T>
void Stack<T>::print_stack(){
    if(is_stack_void()){
        printf("La pila esta vacia.\n");
        printf("\n");
    }else{
        Node<T>* aux = top;
        while(aux != nullptr){
            printf("\n");
            std::cout << aux->get_value() << std::endl;
            aux = aux->get_below();
        }
    }
}

template <typename T>
int Stack<T>::get_stack_size(){
    int result = 0;
    if(is_stack_void()){
        return result;
    }else{
        Node<T>* aux = top;
        while(aux != nullptr){
            result++;
            aux = aux->get_below();
        }
        return result;
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

template <typename T>
void Stack<T>::print_lineal_stack(){
    if(is_stack_void()){
        printf("La pila esta vacia.\n");
    }else{
        Node<T>* aux = top;
        while(aux != nullptr){
            if(aux->get_value() == "c"){
                std::cout << "cos" << "  ";
            }
            else if(aux->get_value() == "s"){
                std::cout << "sen" << "  ";
            }
            else if(aux->get_value() == "t"){
                std::cout << "tan" << "  ";
            }
            else if(aux->get_value() == "r"){
                std::cout << "sqrt" << "  ";
            }else{
                std::cout << aux->get_value() << "  ";
            }
            aux = aux->get_below();
        }
        printf("\n");
    }
}
