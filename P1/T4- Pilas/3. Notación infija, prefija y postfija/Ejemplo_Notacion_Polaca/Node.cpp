#include "Node.h"


/***********************************************************************
 UFA - ESPE
 * Module: Node.cpp
 * Author: Benavides Ruben
 * Modified: December 21, 2023
 * Purpose: Node Class Implementation
 ***********************************************************************/

template <typename T>
Node<T>::Node(){

}

template <typename T>
Node<T>::Node(T value, Node<T>*  below){
    this->value = value;
    this->below = below;
}

template <typename T>
void Node<T>::set_value(T value){
    this->value = value;
}

template <typename T>
void Node<T>::set_below(Node<T>* below){
    this->below = below;
}

template <typename T>
T Node<T>::get_value(){
    return value;
}

template <typename T>
Node<T>* Node<T>::get_below(){
    return below;
}

template <typename T>
Node<T>::~Node(){

}
