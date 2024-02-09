#ifndef STACKS_OPERATIONS_H_INCLUDED
#define STACKS_OPERATIONS_H_INCLUDED

#include "Stack.cpp"
#include "Node.h"
#include <string>

void reverse_stack(Stack<int>* original_stack){
    Stack<int>* aux_stack1 = new Stack<int>();
    Stack<int>* aux_stack2 = new Stack<int>();
    reverse_stack_rec(original_stack, aux_stack1, aux_stack2, false);
}

void reverse_stack_rec(Stack<int>* original_stack, Stack<int>* aux_stack1, Stack<int>* aux_stack2, bool is_reversing){
    if(!original_stack->is_stack_void() && !is_reversing){
        aux_stack1->aggregate(original_stack->take_off());
        reverse_stack_rec(original_stack, aux_stack1, aux_stack2, is_reversing);
    }
    else if(!aux_stack1->is_stack_void()){
        aux_stack2->aggregate(aux_stack1->take_off());
        reverse_stack_rec(original_stack, aux_stack1, aux_stack2, is_reversing);
    }
    else if(!aux_stack2->is_stack_void()){
        original_stack->aggregate(aux_stack2->take_off());
        reverse_stack_rec(original_stack, aux_stack1, aux_stack2, true);
    }
}
 bool es_operador(char op){
    if (op == '*')
        return true;
    else if (op == '+')
        return true;
    else if (op == '-')
        return true;
    else if (op == '/')
        return true;
    else if (op == '^')
        return true;
    else
        return false;
}

bool es_parentesis(char op){
    if (op == '('){
        return true;
        }
    else if (op == ')'){
        return true;
    }
    else
        return false;
}

int jerarquia(char operador) {
    if (operador == '+' || operador == '-') {
        return 1;
    }
    else if (operador == '*' || operador == '/') {
        return 2;
    }
    else if (operador == '^'){
        return 3;
    }
    return 0;
}


std::string polaca_inversa(const std::string& expresion, Stack<char>* operadores) {
    std::string resultado;
    for (int i = 0; i < expresion.length(); i++) {
        if (isdigit(expresion[i])) {
            resultado += expresion[i];
            if (i + 1 < expresion.length() && !isdigit(expresion[i+1]) )
                resultado += " ";
        } else if (expresion[i] == '(') {
            operadores->aggregate(expresion[i]);
        } else if (expresion[i] == ')') {
            while (!operadores->is_stack_void() && operadores->get_top()->get_value() != '(') {
                resultado += operadores->get_top()->get_value();
                operadores->remove_top();
            }
            operadores->remove_top(); // Este remove_top elimina el '(' de la pila
        } else if (es_operador(expresion[i])) {
            while (!operadores->is_stack_void() && jerarquia(operadores->get_top()->get_value()) >= jerarquia(expresion[i])){
                resultado += operadores->get_top()->get_value();
                operadores->remove_top();
            }
            operadores->aggregate(expresion[i]);
        }
    }
    while (!operadores->is_stack_void()) {
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }
    return resultado;
}

std::string sacar_operadores_del_parentesis(Stack<char>* operadores) {
    std::string resultado = "";
    while (!operadores->is_stack_void() && operadores->get_top()->get_value() != '(' && operadores->get_top()->get_value() != ')') {
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }
    operadores->remove_top();
    return resultado;
}

std::string sacar_operadores_jerarquia(char operador, Stack<char>* operadores) {
    std::string resultado = " ";
    while (!operadores->is_stack_void() && jerarquia(operadores->get_top()->get_value()) >= jerarquia(operador)){
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }
    operadores->aggregate(operador);
    return resultado;
}

void polaca_inversa_rec(std::string expresion, Stack<char>* operadores, int tam, std::string* resultado) {
    if (tam >= 0) {
        //Acumular la pila de llamadas hasta la primera posicion
        polaca_inversa_rec(expresion, operadores, tam - 1, resultado);

        if (isdigit(expresion[tam]) || isalpha(expresion[tam]) || expresion[tam]=='.' ){
            *resultado += expresion[tam];
        }
        else if (expresion[tam] == '(') {
            operadores->aggregate(expresion[tam]);
        }
        else if (expresion[tam] == ')') {
            *resultado += sacar_operadores_del_parentesis(operadores);
        }
        else if (es_operador(expresion[tam])) {
            *resultado += sacar_operadores_jerarquia(expresion[tam], operadores);
        }
    }
}

std::string polaca_inversa(std::string expresion) {
    Stack<char>* operadores = new Stack<char>();
    std::string resultado = "";
    polaca_inversa_rec(expresion, operadores, expresion.length(), &resultado);

    while (!operadores->is_stack_void()) {
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }

    return resultado;
}

void polaca_rec(std::string expresion, Stack<char>* operadores, int pos, std::string* resultado) {
    if (pos < expresion.length()) {
        //Acumular la pila de llamadas hasta la ultima posicion
        polaca_rec(expresion, operadores, pos + 1, resultado);
        if (isdigit(expresion[pos]) || isalpha(expresion[pos])|| expresion[pos]=='.'){
            *resultado += expresion[pos];
        }
        else if (expresion[pos] == ')') {
            operadores->aggregate(expresion[pos]);
        }
        else if (expresion[pos] == '(') {
            *resultado += sacar_operadores_del_parentesis(operadores);
        }
        else if (es_operador(expresion[pos])) {
            *resultado += sacar_operadores_jerarquia(expresion[pos], operadores);
        }
    }
}

std::string polaca(std::string expresion) {
    Stack<char>* operadores = new Stack<char>();
    std::string resultado = "";

    polaca_rec(expresion, operadores, 0, &resultado);

    while (!operadores->is_stack_void()) {
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }

    // Invertir el resultado porque se leyo de derecha a izquierda
    for (int i = 0; i < resultado.length()/2; ++i) {
        std::swap(resultado[i], resultado[resultado.length() - i - 1]);
    }

    return resultado;
}


#endif // STACKS_OPERATIONS_H_INCLUDED