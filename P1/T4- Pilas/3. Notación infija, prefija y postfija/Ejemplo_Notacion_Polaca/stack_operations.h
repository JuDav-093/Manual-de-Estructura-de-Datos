#pragma once

#include "Stack.h"
#include "Matematica.h"
#include <string>
#include <algorithm>
#include <cmath>

/***********************************************************************
 UFA - ESPE
 * Module: stack_operations.h
 * Author: Benavides Ruben
 * Modified: December 21, 2023
 * Purpose: Stack operations library
 ***********************************************************************/

template <typename T>
bool is_operator1(T value){
    if(value == "+" || value == "-" ||
       value == "*" || value == "/" ||
       value == "^"){
        return true;
    }else{
        return false;
       }
}

template <typename T>
bool is_operator2(T value){
    if(value == "r" ||
       value == "c" || value == "s" || value == "t"){
        return true;
    }else{
        return false;
       }
}

template <typename T>
double return_result(std::string operator_to, T operating1, T operating2, bool is_reverse){
    Matematica my_math_functions;
    double a = std::stod(operating1);
    double b = std::stod(operating2);
    if(is_reverse){
        if(operator_to == "+"){
            return a + b;
        }else if(operator_to == "-"){
            return b - a;
        }else if(operator_to == "*"){
            return a * b;
        }else if(operator_to == "/"){
            return b / a;
        }else if(operator_to == "^"){
            return my_math_functions.pow(b, a);
        }else if(operator_to == "r"){
            return my_math_functions.sqrt(a);
        }else if(operator_to == "s"){
            return my_math_functions.sin(a);
        }else if(operator_to == "c"){
            return my_math_functions.cos(a);
        }else if(operator_to == "t"){
            return my_math_functions.tan(a);
        }
    }else{
        if(operator_to == "+"){
            return a + b;
        }else if(operator_to == "-"){
            return a - b;
        }else if(operator_to == "*"){
            return a * b;
        }else if(operator_to == "/"){
            return a / b;
        }else if(operator_to == "^"){
            return my_math_functions.pow(a, b);
        }else if(operator_to == "r"){
            return my_math_functions.sqrt(a);
        }else if(operator_to == "s"){
            return my_math_functions.sin(a);
        }else if(operator_to == "c"){
            return my_math_functions.cos(a);
        }else if(operator_to == "t"){
            return my_math_functions.tan(a);
        }
    }
}

template <typename T>
int return_polish_hierarchy(T operator_to_valid){
    if(operator_to_valid == "+" || operator_to_valid == "-"){
        return 1;
    }else if(operator_to_valid == "*" || operator_to_valid == "/"){
        return 2;
    }else if(operator_to_valid == "^" || operator_to_valid == "r"){
        return 3;
    }else if(operator_to_valid == "c" || operator_to_valid == "s" || operator_to_valid == "t"){
        return 4;
    }else{
        return 10;
    }
}

int return_hierarchy_s(std::string operator_to_valid){
    if(operator_to_valid == "+"){
        return 1;
    }else if(operator_to_valid == "-"){
        return 2;
    }else if(operator_to_valid == "*" ){
        return 3;
    }else if(operator_to_valid == "/"){
        return 4;
    }else if(operator_to_valid == "^"){
        return 5;
    }else if(operator_to_valid == "r"){
        return 6;
    }else if(operator_to_valid == "c" || operator_to_valid == "s" || operator_to_valid == "t"){
        return 7;
    }else{
        return 0;
    }
}

template <typename T>
int return_hierarchy(T operator_to_valid){
    if(operator_to_valid == '+' || operator_to_valid == '-'){
        return 1;
    }else if(operator_to_valid == '*' || operator_to_valid == '/'){
        return 2;
    }else if(operator_to_valid == '^' || operator_to_valid == 'r'){
        return 3;
    }else if(operator_to_valid == 'c' || operator_to_valid == 's' || operator_to_valid == 't'){
        return 4;
    }
}

template <typename T>
int is_number(T expression){
    if(!is_operator1(expression) && !is_operator2(expression) && expression != "(" && expression != ")"){
        return true;
    }else{
        return false;
    }
}

template <typename T>
Stack<std::string> convert_to_infix_string_stack(Stack<T>& aux_infix_stack){
    invert_stack(aux_infix_stack);
    Node<T>* current_node = aux_infix_stack.get_top();
    Stack<std::string> string_stack;
    char value;
    std::string aux = "";

    auto get_number = [&](auto&& get_number)->void{
        if(isdigit(value)){
            aux = aux + value;
            current_node = current_node->get_below();
            if(current_node == nullptr ){
                value = '$';
            }else{
                value = current_node->get_value();
            }
            get_number(get_number);
        }else{
            //std::reverse(aux.begin(), aux.end());
            string_stack.aggregate(aux);
        }
    };

    auto convert_each = [&](auto&& convert_each)->void{
        if(current_node != nullptr){
            aux = "";
            value = current_node->get_value();
            if(isdigit(value)){
                get_number(get_number);
                if(current_node == nullptr){
                    convert_each(convert_each);
                }else{
                    aux = "";
                    string_stack.aggregate(aux + value);
                    current_node = current_node->get_below();
                    convert_each(convert_each);
                }
            }else{
                string_stack.aggregate(aux + value);
                current_node = current_node->get_below();
                convert_each(convert_each);
            }
        }
    };


    convert_each(convert_each);
    invert_stack(string_stack);
    return string_stack;
}

void return_expression_result(int counter, int TAM, Node<std::string>* temp1, Node<std::string>* temp2,
                              Node<std::string>* temp3, double value, std::string newValue, Stack<std::string>& expression_stack,
                              Node<std::string>* current_node){

    auto evaluate5 = [&](auto&& evaluate5)->void{
        if(counter < TAM-1){
            if(return_hierarchy_s(current_node->get_below()->get_value()) == 5){
                value = return_result("^", current_node->get_value(), (current_node->get_below()->get_below()->get_value()), false);
                newValue = std::to_string(value);
                temp1 = current_node->get_below();
                temp2 = current_node->get_below()->get_below();
                temp3 = temp2->get_below();
                temp1->set_below(nullptr);
                temp2->set_below(nullptr);
                current_node->set_value(newValue);
                current_node->set_below(temp3);
                current_node = expression_stack.get_top();
                counter = 0;
                TAM = expression_stack.get_stack_size();
                evaluate5(evaluate5);
            }else{
                counter++;
                current_node = current_node->get_below();
                if(current_node == nullptr){
                    counter = TAM;
                }
                evaluate5(evaluate5);
            }
        }
    };

    auto evaluate4 = [&](auto&& evaluate4)->void{
        if(counter < TAM-1){
            if(return_hierarchy_s(current_node->get_below()->get_value()) == 3 ||
               return_hierarchy_s(current_node->get_below()->get_value()) == 4){
                if(return_hierarchy_s(current_node->get_below()->get_value()) == 3){
                    value = stod(current_node->get_value())*(stod(current_node->get_below()->get_below()->get_value()));
                }else{
                    value = stod(current_node->get_value())/(stod(current_node->get_below()->get_below()->get_value()));
                }
                newValue = std::to_string(value);
                temp1 = current_node->get_below();
                temp2 = current_node->get_below()->get_below();
                temp3 = temp2->get_below();
                temp1->set_below(nullptr);
                temp2->set_below(nullptr);
                current_node->set_value(newValue);
                current_node->set_below(temp3);
                current_node = expression_stack.get_top();
                counter = 0;
                TAM = expression_stack.get_stack_size();
                evaluate4(evaluate4);
            }else{
                counter++;
                current_node = current_node->get_below();
                if(current_node == nullptr){
                    counter = TAM;
                }
                evaluate4(evaluate4);
            }

        }
    };

    auto evaluate3 = [&](auto&& evaluate3)->void{
        if(counter < TAM-1){
            if(return_hierarchy_s(current_node->get_below()->get_value()) == 1 ||
               return_hierarchy_s(current_node->get_below()->get_value()) == 2){
                if(return_hierarchy_s(current_node->get_below()->get_value()) == 1){
                    value = stod(current_node->get_value())+(stod(current_node->get_below()->get_below()->get_value()));
                }else{
                    value = stod(current_node->get_value())-(stod(current_node->get_below()->get_below()->get_value()));
                }
                newValue = std::to_string(value);
                temp1 = current_node->get_below();
                temp2 = current_node->get_below()->get_below();
                temp3 = temp2->get_below();
                temp1->set_below(nullptr);
                temp2->set_below(nullptr);
                current_node->set_value(newValue);
                current_node->set_below(temp3);
                current_node = expression_stack.get_top();
                counter = 0;
                TAM = expression_stack.get_stack_size();
                evaluate3(evaluate3);
            }else{
                counter++;
                current_node = current_node->get_below();
                if(current_node->get_below() == nullptr){
                    counter = TAM;
                }
                evaluate3(evaluate3);
            }
        }
    };


    evaluate5(evaluate5);

    current_node = expression_stack.get_top();
    counter = 0;
    TAM = expression_stack.get_stack_size();

    evaluate4(evaluate4);

    current_node = expression_stack.get_top();
    counter = 0;
    TAM = expression_stack.get_stack_size();

    evaluate3(evaluate3);

    //std::cout<<expression_stack.get_top()->get_value() << std::endl;
}

void return_expression(Stack<std::string>& expression_stack, Node<std::string>* before_beginning, Node<std::string>* beginning,
                                                             Node<std::string>* ending, Node<std::string>* after_ending){
    int counter = 0;
    int TAM = expression_stack.get_stack_size();
    Node<std::string>* current_node = expression_stack.get_top();
    Node<std::string>* temp1;
    Node<std::string>* temp2;
    Node<std::string>* temp3;
    double value;
    std::string newValue;
    std::string trashValue = "40";

    return_expression_result(counter, TAM, temp1, temp2, temp3, value, newValue, expression_stack, current_node);

    std::string value_to_replace = expression_stack.get_top()->get_value();


    if(before_beginning == nullptr){
        beginning->set_value(value_to_replace);
        beginning->set_below(after_ending);
    }else{
        ending->set_below(nullptr);
        if(return_hierarchy_s(before_beginning->get_value()) == 6 || return_hierarchy_s(before_beginning->get_value()) == 7){

            before_beginning->set_value(std::to_string(return_result(before_beginning->get_value(),
                                                                     value_to_replace, trashValue,
                                                                     false)));
            before_beginning->set_below(after_ending);
        }else{
            beginning->set_value(value_to_replace);
            beginning->set_below(after_ending);
        }

    }

}



Stack<char> upgrade_char_stack(Stack<char>& char_stack){

    invert_stack(char_stack);
    Stack<char> new_char_stack;
    char value;
    int counter = 0;

    auto convert_each = [&](auto&& convert_each)->void{
        if(counter < char_stack.get_stack_size()){
            value = char_stack.get_top()->get_value();
            new_char_stack.aggregate(value);
            if(value == 'r'){
                char_stack.delete_of_stack();
                char_stack.delete_of_stack();
                char_stack.delete_of_stack();
                char_stack.delete_of_stack();
            }else if(value == 'c' || value == 's' || value == 't'){
                char_stack.delete_of_stack();
                char_stack.delete_of_stack();
                char_stack.delete_of_stack();
            }else if(value == 'p'){
                char_stack.delete_of_stack();
                char_stack.delete_of_stack();
            }else{
                char_stack.delete_of_stack();
            }
            convert_each(convert_each);
        }
    };

    convert_each(convert_each);
    return new_char_stack;
}

template <typename T>
void take_operators_P(Stack<T>& operators_stack, Stack<T>& polishStack,
                    T& operator_value, bool delete_parenthesis, int hierarchy){

    Node<T>* aux_parenthesis = operators_stack.get_top();
    int TAM = operators_stack.get_stack_size();
    int counter = 0;

    auto take_off = [&](auto&& take_off)->void{
        if(counter < TAM){
            if(aux_parenthesis->get_value() == ")"){
                if(delete_parenthesis){
                    if(aux_parenthesis->get_below() != nullptr){
                        operator_value = aux_parenthesis->get_below()->get_value();
                    }else{
                        operator_value = "&";
                    }
                    operators_stack.delete_of_stack();
                }else{
                    operator_value = ")";
                }
                counter = TAM;
                take_off(take_off);
            }else{
                if(hierarchy <= return_polish_hierarchy(aux_parenthesis->get_value())){
                    polishStack.aggregate(aux_parenthesis->get_value());
                    operators_stack.delete_of_stack();
                    aux_parenthesis = operators_stack.get_top();
                    counter++;
                    take_off(take_off);
                }else{
                    counter = TAM;
                    take_off(take_off);
                }
            }
        }
    };

    take_off(take_off);

}

template <typename T>
void take_operators_R(Stack<T>& operators_stack, Stack<T>& reverse_polish_stack,
                    T& operator_value, bool delete_parenthesis, int hierarchy){

    Node<T>* aux_parenthesis = operators_stack.get_top();
    int TAM = operators_stack.get_stack_size();
    int counter = 0;

    auto take_off = [&](auto&& take_off)->void{
        if(counter < TAM){
            if(aux_parenthesis->get_value() == "("){
                if(delete_parenthesis){
                    if(aux_parenthesis->get_below() != nullptr){
                        operator_value = aux_parenthesis->get_below()->get_value();
                    }else{
                        operator_value = "&";
                    }
                    operators_stack.delete_of_stack();
                }else{
                    operator_value = "(";
                }
                counter = TAM;
                take_off(take_off);
            }else{
                if(hierarchy <= return_polish_hierarchy(aux_parenthesis->get_value())){
                    reverse_polish_stack.aggregate(aux_parenthesis->get_value());
                    operators_stack.delete_of_stack();
                    aux_parenthesis = operators_stack.get_top();
                    counter++;
                    take_off(take_off);
                }else{
                    counter = TAM;
                    take_off(take_off);
                }
            }
        }
    };

    take_off(take_off);

}

template <typename T>
void getPolishNotation(Stack<T>& originalStack, Stack<T>& polish_stack){

    if(!originalStack.is_stack_void()){
        invert_stack(originalStack);
        Stack<T> originalStackCopy;
        Stack<T> operators_stack;
        Node<T>* aux = operators_stack.get_top();
        T operator_value;
        bool delete_parenthesis = false;
        int TAM = originalStack.get_stack_size();
        T value = originalStack.get_top()->get_value();

        auto is_there_second_value = [](Node<T>* aux){
            if(aux != nullptr){
                return true;
            }else{
                return false;
            }
        };

        int counter = 0;

        auto go_over = [&](auto&& go_over)->void{
            if(counter < TAM){
                originalStackCopy.aggregate(originalStack.get_top()->get_value());
                if(is_number(value)){
                    polish_stack.aggregate(value);
                }else{
                    if(is_there_second_value(aux)){
                        if(value == "("){
                            take_operators_P(operators_stack, polish_stack, operator_value, true,
                                             0);
                        }
                        else if(return_polish_hierarchy(value) <= return_polish_hierarchy(operator_value)){
                            take_operators_P(operators_stack, polish_stack, operator_value, false,
                                             return_polish_hierarchy(value));
                            operators_stack.aggregate(value);
                            operator_value = value;

                        }
                        else{
                            if(return_polish_hierarchy(value) == 4){
                                polish_stack.aggregate(value);
                            }else{
                                operators_stack.aggregate(value);
                                operator_value = value;
                            }
                        }
                    }else{
                        operator_value = value;
                        operators_stack.aggregate(value);
                    }
                }
                counter++;
                if(counter == TAM){
                    if(!operators_stack.is_stack_void()){
                        take_operators_P(operators_stack, polish_stack, operator_value, true, 0);
                    }
                    go_over(go_over);
                }else{
                    originalStack.delete_of_stack();
                    value = originalStack.get_top()->get_value();
                    aux = operators_stack.get_top();
                    go_over(go_over);
                }

            }
        };

        go_over(go_over);
        polish_stack.print_lineal_stack();
        originalStack = originalStackCopy;
    }

}

template <typename T>
void getReversePolishNotation(Stack<T>& originalStack, Stack<T>& reverse_polish_stack){
    if(!originalStack.is_stack_void()){

        Stack<T> originalStackCopy;
        Stack<T> operators_stack;
        Node<T>* aux = operators_stack.get_top();
        T operator_value;
        bool delete_parenthesis = false;
        int TAM = originalStack.get_stack_size();
        T value = originalStack.get_top()->get_value();

        auto is_there_second_value = [](Node<T>* aux){
            if(aux != nullptr){
                return true;
            }else{
                return false;
            }
        };

        int counter = 0;

        auto go_over = [&](auto&& go_over)->void{
            if(counter < TAM){
                originalStackCopy.aggregate(originalStack.get_top()->get_value());
                if(is_number(value)){
                    reverse_polish_stack.aggregate(value);
                }else{
                    if(is_there_second_value(aux)){
                        if(value == ")"){
                            take_operators_R(operators_stack, reverse_polish_stack, operator_value, true,
                                             0);
                        }
                        else if(return_polish_hierarchy(value) <= return_polish_hierarchy(operator_value)){
                            if(return_polish_hierarchy(value) == 4){
                                reverse_polish_stack.aggregate(value);
                            }else{
                                take_operators_R(operators_stack, reverse_polish_stack, operator_value, false,
                                                 return_polish_hierarchy(value));
                                operators_stack.aggregate(value);
                                operator_value = value;
                            }
                        }
                        else{
                            if(return_polish_hierarchy(value) == 4){
                                reverse_polish_stack.aggregate(value);
                            }else{
                                operators_stack.aggregate(value);
                                operator_value = value;
                            }
                        }
                    }else{
                        if(return_polish_hierarchy(value) == 4){
                            reverse_polish_stack.aggregate(value);
                        }else{
                            operator_value = value;
                            operators_stack.aggregate(value);
                        }

                    }
                }
                counter++;
                if(counter == TAM){
                    if(!operators_stack.is_stack_void()){
                        take_operators_R(operators_stack, reverse_polish_stack, operator_value, true, 0);
                    }
                    go_over(go_over);
                }else{
                    originalStack.delete_of_stack();
                    value = originalStack.get_top()->get_value();
                    aux = operators_stack.get_top();
                    go_over(go_over);
                }

            }
        };


        go_over(go_over);
        invert_stack(reverse_polish_stack);
        reverse_polish_stack.print_lineal_stack();
        originalStack = originalStackCopy;
    }
}

template <typename T>
Stack<std::string> convert_to_polish_string_stack(Stack<T>& aux_polish_stack){
    invert_stack(aux_polish_stack);
    Node<T>* current_node = aux_polish_stack.get_top();
    Stack<std::string> string_stack;
    char value;
    std::string aux = "";

    auto get_number = [&](auto&& get_number)->void{
        if(value != '$'){
            aux = aux + value;
            current_node = current_node->get_below();
            if(current_node == nullptr ){
                value = '$';
            }else{
                value = current_node->get_value();
            }
            get_number(get_number);
        }else{
            std::reverse(aux.begin(), aux.end());
            string_stack.aggregate(aux);
        }
    };

    auto convert_each = [&](auto&& convert_each)->void{
        if(current_node != nullptr){
            aux = "";
            value = current_node->get_value();
            if(isdigit(value)){
                get_number(get_number);
                if(current_node == nullptr){
                    convert_each(convert_each);
                }else if(value = '$'){
                    current_node = current_node->get_below();
                    convert_each(convert_each);
                }
            }else{
                if(value != '$'){
                    string_stack.aggregate(aux + value);
                }
                current_node = current_node->get_below();
                convert_each(convert_each);
            }
        }
    };

    convert_each(convert_each);
    string_stack.print_stack();
    return string_stack;
}

template <typename T>
Stack<std::string> calculate_infix(Stack<T>& aux_infix_stack){
    if(!aux_infix_stack.is_stack_void()){
            invert_stack(aux_infix_stack);
        Node<T>* current_node = aux_infix_stack.get_top();
        Stack<std::string> string_stack;
        Stack<std::string> expression_stack;
        Node<std::string>* aux_node;
        bool trig_funcs = false;
        char value;
        std::string aux = "";

        auto is_there_trig_funcs = [&](auto&& is_there_trig_funcs, Node<std::string>* aux_trig_funcs)->void{
            if(aux_trig_funcs != nullptr){
                if(aux_trig_funcs->get_value() == "c" || aux_trig_funcs->get_value() == "s" || aux_trig_funcs->get_value() == "t"){
                    trig_funcs = true;
                    aux_trig_funcs = nullptr;
                }else{
                    aux_trig_funcs = aux_trig_funcs->get_below();
                }
                is_there_trig_funcs(is_there_trig_funcs, aux_trig_funcs);
            }
        };

        auto get_number = [&](auto&& get_number)->void{
            if(isdigit(value)){
                aux = aux + value;
                current_node = current_node->get_below();
                if(current_node == nullptr ){
                    value = '$';
                }else{
                    value = current_node->get_value();
                }
                get_number(get_number);
            }else{
                //std::reverse(aux.begin(), aux.end());
                string_stack.aggregate(aux);
            }
        };

        auto convert_each = [&](auto&& convert_each)->void{
            if(current_node != nullptr){
                aux = "";
                value = current_node->get_value();
                if(isdigit(value)){
                    get_number(get_number);
                    if(current_node == nullptr){
                        convert_each(convert_each);
                    }else{
                        aux = "";
                        string_stack.aggregate(aux + value);
                        current_node = current_node->get_below();
                        convert_each(convert_each);
                    }
                }else{
                    string_stack.aggregate(aux + value);
                    current_node = current_node->get_below();
                    convert_each(convert_each);
                }
            }
        };


        convert_each(convert_each);
        invert_stack(string_stack);

        Node<std::string>* current_string_node;
        current_string_node = string_stack.get_top();
        if(current_string_node->get_below() != nullptr){
            if(current_string_node->get_value() == "-" &&
               (is_operator1(current_string_node->get_below()->get_value())) == false &&
                (is_operator2(current_string_node->get_below()->get_value())) == false &&
                    current_string_node->get_below()->get_value() != "("){

                Node<std::string>* temp = current_string_node->get_below()->get_below();
                current_string_node->get_below()->set_below(nullptr);
                current_string_node->set_value(std::to_string(-1*stod(current_string_node->get_below()->get_value())));
                current_string_node->set_below(temp);

            }
        }

        current_string_node = string_stack.get_top();
        auto change_to_one_number = [&](auto&& change_to_one_number)->void{
            //ACOMODAR STACK PARA QUE LOS RESTANTES ( - X ) SEAN ( -X ) SOLAMENTE
            if(current_string_node != nullptr){

                if(current_string_node->get_below() != nullptr){
                    if(current_string_node->get_below()->get_below() != nullptr){
                        if(current_string_node->get_below()->get_below()->get_below() != nullptr){
                            if(current_string_node->get_value() == "(" &&
                               current_string_node->get_below()->get_value() == "-" &&
                               (is_operator1(current_string_node->get_below()->get_below()->get_value())) == false &&
                                (is_operator2(current_string_node->get_below()->get_below()->get_value())) == false &&
                                current_string_node->get_below()->get_below()->get_value() != "("){

                                Node<std::string>* temp = current_string_node->get_below()->get_below()->get_below();
                                current_string_node->get_below()->get_below()->set_below(nullptr);
                                current_string_node->get_below()->set_value(std::to_string(-1*stod(current_string_node->get_below()->get_below()->get_value())));
                                current_string_node->get_below()->set_below(temp);




                            }
                        }
                    }
                }
                current_string_node = current_string_node->get_below();
                change_to_one_number(change_to_one_number);

            }
        };

        auto find_close_parenthesis = [&](auto&& find_close_parenthesis, Node<std::string>* node1, Node<std::string>* node2,
                                          Node<std::string>* node3, Node<std::string>* node4)->void{

            if(aux_node->get_value() != "("){
                expression_stack.aggregate(aux_node->get_value());
               }
            if(aux_node->get_below()->get_value() == ")"){
                //printf("--BEFORE--\n");
                //string_stack.print_stack();
                invert_stack(expression_stack);
                return_expression(expression_stack, node1, node2,
                                                    aux_node->get_below(), aux_node->get_below()->get_below());
                current_string_node = string_stack.get_top();
                //printf("--BET--");
                //string_stack.print_stack();
                change_to_one_number(change_to_one_number);
                current_string_node = string_stack.get_top();
                //printf("--AFTER--");
                //string_stack.print_stack();
            }else if(aux_node->get_below()->get_value() == "("){
                expression_stack.remove_all();
                current_string_node = current_string_node->get_below();
            }else{
                aux_node = aux_node->get_below();
                find_close_parenthesis(find_close_parenthesis, node1, node2, node3, node4);
            }
        };

        Node<std::string>* aux_trig_funcs = string_stack.get_top();

        auto send_each_expression = [&](auto&& send_each_expression)->void{

            //MANDAR LAS EXPRESIONES VALIDANDO () Y USANDO MI FUNCION DE RETURN EXPRESSION
            if(current_string_node != nullptr){
                if(current_string_node->get_below() != nullptr){
                    if(current_string_node->get_below()->get_below() != nullptr){
                        expression_stack.remove_all();
                        if((is_operator2(current_string_node->get_value()) ||
                            is_operator1(current_string_node->get_value()) ||
                            current_string_node->get_value() == "(") && current_string_node->get_below()->get_value() == "(" &&
                            current_string_node->get_below()->get_below()->get_value() != "("){

                            aux_trig_funcs = string_stack.get_top();
                            is_there_trig_funcs(is_there_trig_funcs, aux_trig_funcs);
                            if(return_hierarchy_s(current_string_node->get_value()) == 6 && trig_funcs == true){
                                current_string_node = current_string_node->get_below();
                                trig_funcs = false;
                            }else{
                                aux_node = current_string_node->get_below()->get_below();
                                find_close_parenthesis(find_close_parenthesis, current_string_node, current_string_node->get_below(),
                                                                               nullptr, nullptr);
                            }


                        }else if(current_string_node->get_value() == "("){
                            aux_node = current_string_node->get_below();
                            find_close_parenthesis(find_close_parenthesis, nullptr, current_string_node,
                                                                           nullptr, nullptr);
                        }else{
                            current_string_node = current_string_node->get_below();
                        }
                        send_each_expression(send_each_expression);

                    }

                }

            }

        };


        change_to_one_number(change_to_one_number);
        current_string_node = string_stack.get_top();
        send_each_expression(send_each_expression);


        Node<std::string>* temp1;
        Node<std::string>* temp2;
        Node<std::string>* temp3;
        current_string_node = string_stack.get_top();

        return_expression_result(0, string_stack.get_stack_size(), temp1, temp2, temp3, 0, "", string_stack, current_string_node);
        //string_stack.print_stack();


        current_string_node = string_stack.get_top();
        if(current_string_node->get_below() != nullptr){
            if(current_string_node->get_value() == "-" &&
               (is_operator1(current_string_node->get_below()->get_value())) == false &&
                (is_operator2(current_string_node->get_below()->get_value())) == false &&
               current_string_node->get_below()->get_value() != "("){

                Node<std::string>* temp = current_string_node->get_below()->get_below();
                current_string_node->get_below()->set_below(nullptr);
                current_string_node->set_value(std::to_string(-1*stod(current_string_node->get_below()->get_value())));
                current_string_node->set_below(temp);

            }
        }
        invert_stack(aux_infix_stack);
        std::cout << "RESULTADO:" << std::endl;
        string_stack.print_stack();
        return string_stack;
    }
}


void calculate_signs(Stack<std::string>& infix_stack){
    Node<std::string>* current_node = infix_stack.get_top();
    std::string aux = "";
    auto go_through = [&](auto&& go_through)->void{
        if(current_node != nullptr){

            if(current_node->get_value() == "+" || current_node->get_value() == "-"){
                if(aux == ""){
                    aux = current_node->get_value();
                }else{
                    if(aux == "+" && current_node->get_value() == "+"){
                        aux = "+";
                    }else if((aux == "+" && current_node->get_value() == "-") || (aux == "-" && current_node->get_value() == "+")){
                        aux = "-";
                    }else if(aux == "-" && current_node->get_value() == "-"){
                        aux = "+";
                    }
                }
            }

            current_node = current_node->get_below();
            go_through(go_through);

        }
    };

    go_through(go_through);

    std::cout << aux << std::endl;

}


