//
// Created by Eleanor Heaton on 9/28/23.
//
#include <stack>
#include <iostream>
using namespace std;
#ifndef STACKSUPONSTACKSOFEVALUATION_STACKEVALUATOR_H
#define STACKSUPONSTACKSOFEVALUATION_STACKEVALUATOR_H


class StackEvaluator {
    stack<int> numbers;
    stack<char> operands;
    int num1;
    int num2;
    char currentChar;
    char lastChar = ' ';
    bool negative_flag = false;
    int result;
    void calculate ();
    void parenthesisHandler();
public:
    void parser(string equation);
    void cleanUp();
    };


#endif //STACKSUPONSTACKSOFEVALUATION_STACKEVALUATOR_H