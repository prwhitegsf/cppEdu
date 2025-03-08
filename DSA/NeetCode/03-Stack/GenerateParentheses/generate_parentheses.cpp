//
// Created by prw on 3/8/25.
//

#include <vector>
#include <string>
#include <stack>
#include <iostream>

// Stack is actually not a good data structure to use here
// because we want to return values in the proper order
// and we can only access a stack from the top in cpp (and in general)
// which puts our output in reverse order

using SVec = std::vector<std::stack<char>>;
using SStack = std::stack<char>;

void print(std::string& s){
    std::cout << s << std::endl;
}

void print(SStack stack){

    std::string s{"      "};


    int last = stack.size()-1;

    for (int i{last}; i>= 0; i--){

        s.insert(i, 1, stack.top());
        //s[i] = stack.top();
        std::cout << s << std::endl;
        stack.pop();
    }

   std::cout << s << std::endl;

}

inline void backtracker(int open_count, int close_count,int n,
                        SVec& result, SStack& curr_perm){

    // Break Condition
    if(open_count==close_count && open_count==n){

        result.push_back(curr_perm);
        return;
    }

    if (open_count < n){
        curr_perm.push('(');

        backtracker(open_count+1, close_count,n,result, curr_perm);
        curr_perm.pop();
    }

    if (close_count < open_count){
        curr_perm.push(')');
        backtracker(open_count, close_count+1,n,result, curr_perm);
        print(curr_perm);
        curr_perm.pop();
        return;
    }



}


inline SVec GenerateParentheses(int n){

    SStack curr_perm;
    SVec result;

    backtracker(0, 0, n, result, curr_perm);
    return result;


}



int main(){

    int n = 3;

    auto res = GenerateParentheses(n);

   /* for(auto& stack : res){
        while (!stack.empty()){
            std::cout << stack.top();
            stack.pop();
        }
        std::cout << std::endl;
    }*/


    return 0;
}