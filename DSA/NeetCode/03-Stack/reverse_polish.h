//
// Created by prw on 2/22/25.
//

#ifndef CPP_REVERSE_POLISH_H
#define CPP_REVERSE_POLISH_H

#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <stack>


inline int ReversePolish(const std::vector<std::string>& tokens){

    if (tokens.size() < 3)
        return stoi(tokens[0]);

    std::unordered_map<std::string,std::function<int(int, int)>> ops_dict {
        {"+", [](int a, int b){return a + b;}},
         {"-", [](int a, int b){return a - b;}},
          {"*", [](int a, int b){return a * b;}},
           {"/", [](int a, int b){return a / b;}}
    };

    std::stack<int> operands{};
    std::stack<std::string> operators{};

    for (size_t i{tokens.size()}; i > 0; i--){
        if(!ops_dict.contains(tokens[i-1]))
            operands.push(stoi(tokens[i-1]));
        else
            operators.push(tokens[i-1]);
    }

    int res{};

    if (!operands.empty()) {
        res = operands.top();
        operands.pop();
    }

    while (!operators.empty()){
        res = ops_dict[operators.top()](res, operands.top());
        operators.pop();
        operands.pop();
    }

    return res >= 0 ? res : res + 1;

}




#endif //CPP_REVERSE_POLISH_H
