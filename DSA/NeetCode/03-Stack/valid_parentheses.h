//
// Created by prw on 2/21/25.
//

#ifndef CPP_VALID_PARENTHESES_H
#define CPP_VALID_PARENTHESES_H

#include <stack>
#include <unordered_map>
#include <string>


inline bool ValidParentheses(const std::string& s){

    std::stack<char> stack{};
    std::unordered_map<char, char> close_to_open = {
            {')', '('},
            {'}','{'},
            {']','['}
    };



    for (const char c : s){

        if (close_to_open.contains(c)){
            if (!stack.empty() && stack.top() == close_to_open[c]){
                stack.pop();
            }
            else
                return false;
        }
        else
            stack.push(c);
    }

    return stack.empty();

}











#endif //CPP_VALID_PARENTHESES_H
