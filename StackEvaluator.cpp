//
// Created by Eleanor Heaton on 9/28/23.
//

#include "StackEvaluator.h"
//stack logic processor
void StackEvaluator::calculate() {
    num1 = numbers.top();
    numbers.pop();
    num2 = numbers.top();
    numbers.pop();
        switch (operands.top()) {
            case '+':
                numbers.push(num2+num1);
                break;
            case '-':
                numbers.push(num2-num1);
                break;
            case '*':
                numbers.push(num2*num1);
                break;
            case '/':
                numbers.push(num2/num1);
                break;
            case '(':
                numbers.push(num2*num1);
                break;
        }

    result = numbers.top();
    operands.pop();
}
//handles parantheses
void StackEvaluator::parenthesisHandler() {
    operands.pop();
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
                if (negative_flag != NULL && negative_flag == true){
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
                //parser to determine if - is minus or negative
                if (currentChar != '-')
                    operands.push(currentChar);
                else
                    if (lastChar != NULL && isdigit(lastChar))
                        operands.push(currentChar);
                    else
                        negative_flag = true;

                //checks if parenthesis acts as multiplication
                if (currentChar == '('){
                    if(isdigit(lastChar))
                        operands.push('*');
                }

                //handles parantheses
                if (currentChar == ')')
                    parenthesisHandler();
                //clean up
                lastChar =equation.at(0);
                equation.erase(0,1);
                currentChar = equation.at(0);

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
