#ifndef STACKS_MOVEMENTS_H_INCLUDED
#define STACKS_MOVEMENTS_H_INCLUDED
#include "Stack.h"


/***********************************************************************
 UFA - ESPE
 * Module: stack_movements.h
 * Author: Benavides Ruben
 * Modified: December 21, 2023
 * Purpose: Stack movements library
 ***********************************************************************/

template <typename T>
void invert_stack(Stack<T>& original_stack);

template <typename T>
void invert_stack(Stack<T>& original_stack){
    if(original_stack.is_stack_void()){
        printf("La pila esta vacia");
    }else{

        //Stack<T> aux = original_stack;
        Stack<T> stack1;
        Stack<T> stack2;

        int original_stack_size = original_stack.get_stack_size();
        T value;

        auto get_a_stack_copy = [&](auto&& get_a_stack_copy, Stack<T>& stack1, Stack<T>& stack2, int contador)->void{
            if(contador <= original_stack_size){
                value = stack1.get_top()->get_value();
                stack2.aggregate(value);
                stack1.delete_of_stack();
                get_a_stack_copy(get_a_stack_copy, stack1, stack2, contador + 1);
            }
        };

        /*auto clear_out = [&](auto&& clear_out, int contador)->void{
            if(contador <= original_stack_size){
                original_stack.delete_of_stack();
                clear_out(clear_out, contador + 1);
            }
        };*/

        //clear_out(clear_out, 1);
        //get_a_stack_copy(get_a_stack_copy, stack1, original_stack, 1);
        get_a_stack_copy(get_a_stack_copy, original_stack, stack1, 1);
        get_a_stack_copy(get_a_stack_copy, stack1, stack2, 1);
        get_a_stack_copy(get_a_stack_copy, stack2, original_stack, 1);
    }
}


#endif // STACKS_MOVEMENTS_H_INCLUDED
