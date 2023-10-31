//
// Created by Eleanor Heaton on 9/28/23.
//

#include "StackEvaluator.h"
//stack logic processor
void StackEvaluator::calculate() {
    // popping out 2 numbers to evaluate
    num1 = numbers.top();
    numbers.pop();
    num2 = numbers.top();
    numbers.pop();
    switch (operands.top()) {
        case '+':
            numbers.push(num2 + num1);
            break;
        case '-':
            numbers.push(num2 - num1);
            break;
        case '*':
            numbers.push(num2 * num1);
            break;
        case '/':
            numbers.push(num2 / num1);
            break;
        case '(':
            numbers.push(num2 * num1);
            break;
    }
    // setting result
    result = numbers.top();
    // popping operand
    operands.pop();
}
//handles parentheses
void StackEvaluator::parenthesisHandler() {
    // pop ')'
    operands.pop();
    //do all operations within parenthesis
    while (operands.top() != '(')
    {
        calculate();
    }
    operands.pop();
}
// creates the stacks
void StackEvaluator::parser(string equation) {

        while (!equation.empty()) {
            currentChar = equation.at(0);
            if(isdigit(currentChar)) {
                string number;
                number = currentChar;
                //individual number parser
                while(equation.length() != 1 && isdigit(equation.at(1))) {
                    number += equation.at(1);
                    equation.erase(0, 1);
                }
                lastChar = currentChar;
                equation.erase(0,1);
                int num3 = stoi(number);
                // negative check
                if (negative_flag){
                    num3 = num3 * -1;
                    negative_flag = false;
                }
                //prints absolute value
                cout << " " << abs(num3);
                numbers.push(num3);
                //multiplication priority
                if (lastChar == '*' || lastChar == '/'){
                    calculate();
                }
            }
            else {
                cout << " "<< currentChar;
                // pushes all obvious chars
                if (currentChar != '-')
                    operands.push(currentChar);
                    //parser to determine if - is minus or negative
                else
                    //if the last char isn't empty, and is a number or paranthesis end bracket, then must be negative
                    if (lastChar != ' ' && (isdigit(lastChar)||lastChar == ')'))
                        operands.push(currentChar);
                    else
                        negative_flag = true;

                //checks if parenthesis acts as multiplication
                if (currentChar == '('){
                    if(isdigit(lastChar) || lastChar == ')')
                        operands.push('*');
                }

                //handles parantheses
                if (currentChar == ')')
                    parenthesisHandler();
                //clean up
                lastChar =equation.at(0);
                equation.erase(0,1);


            }

        }

    }
//finishes the stack evaluation
void StackEvaluator::cleanUp() {
    while (numbers.size() > 1) {
        calculate();
    }
    cout << "\nThe result of the stack evaluation is " << result << "\n";
}
