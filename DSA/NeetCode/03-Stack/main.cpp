#include <iostream>

#include "valid_parentheses.h"
#include "min_stack.h"
#include "reverse_polish.h"





int main() {

    // Valid Parentheses
    /*std::string input = "({{{{}}}})";
    std::cout << ValidParentheses(input) << std::endl;
*/

    // Min Stack
    /*MinStack ms;

    ms.push(7);
    ms.push(3);
    ms.push(5);

    std::cout << ms.top() << std::endl;
    std::cout << ms.GetMin() << std::endl;*/

    // Reverse Polish
    std::vector<std::string> tokens{"4","13","5","/","+"};
    std::cout << ReversePolish(tokens) << std::endl;



    return 0;
}