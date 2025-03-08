//
// Created by prw on 3/8/25.
//

#include <vector>
#include <string>
#include <iostream>

// Stack is actually not a good data structure to use here
// because we want to return values in the proper order
// and we can only access a stack from the top in cpp (and in general)
// which puts our output in reverse order
// easily provides the functionality we need



using SVec = std::vector<std::string>;


void print(std::string& s){
    std::cout << s << std::endl;
}

// Dynamic Programming Solution

inline SVec GenerateParentheses(int n){


    std::vector<SVec> result(n+1);
    result[0]={""};


    for (int k{}; k <= n; ++k){

        for(int i{}; i < k;++i){

            for (auto& lhs : result[i]){

                for (auto& rhs : result[k-i-1]){

                    result[k].push_back("("+lhs+")"+rhs);
                }
            }
        }
    }


    return result[n];


}



int main(){

    int n = 3;
    std::cout << "here";
    auto res = GenerateParentheses(n);

       for(auto& s : res){

           std::cout << s << std::endl;
       }


    return 0;
}