#include <iostream>
#include <stack>
#include "StackEvaluator.h"

using namespace std;

int main() {
    //creating variables
    stack<int> numbers;
    stack<char> operands;
    StackEvaluator stack_eval;
    //user input for equation
    string equation;
    cout << "type in your equation:";
    cin >> equation;
    //removing whitespaces
    equation.erase(std::remove_if(equation.begin(), equation.end(), ::isspace),
            equation.end());
    //stack evaluation
    stack_eval.parser(equation);
    stack_eval.cleanUp();
}
