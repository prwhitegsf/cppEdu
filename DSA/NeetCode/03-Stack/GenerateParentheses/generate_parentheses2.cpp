
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



inline void backtracker(int open_count, int close_count,int n,
                        SVec& result, std::string& curr_perm){

    // Break Condition
    if(open_count==close_count && open_count==n){

        result.push_back(curr_perm);
        return;
    }

    if (open_count < n){
        curr_perm.push_back('(');

        backtracker(open_count+1, close_count,n,result, curr_perm);
        curr_perm.pop_back();
    }

    if (close_count < open_count){
        curr_perm.push_back(')');
        backtracker(open_count, close_count+1,n,result, curr_perm);


        curr_perm.pop_back();
        return;
    }



}


inline SVec GenerateParentheses(int n){

    std::string curr_perm;
    SVec result;

    backtracker(0, 0, n, result, curr_perm);
    return result;


}



int main(){

    int n = 3;

    auto res = GenerateParentheses(n);

    for(auto& s : res){

         std::cout << s << std::endl;
     }


    return 0;
}