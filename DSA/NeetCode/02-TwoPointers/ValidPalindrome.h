#ifndef CPP_VALIDPALINDROME_H
#define CPP_VALIDPALINDROME_H


#include <string>

inline bool valid_palindrome(const std::string& s){

    // set initial pointer positions
    int lhs = 0;
    int rhs = s.size() - 1;

    while (lhs < rhs){

        // skip non-alphanum chars
        while (!isalpha(s[lhs])){
            lhs++;
        }

        while (!isalpha(s[rhs])){
            rhs--;
        }

        if (std::tolower(s[lhs]) != std::tolower(s[rhs])){
            return false;
        }
        else{
            lhs++;
            rhs--;
        }


    }

    return true;



}

















#endif //CPP_VALIDPALINDROME_H
