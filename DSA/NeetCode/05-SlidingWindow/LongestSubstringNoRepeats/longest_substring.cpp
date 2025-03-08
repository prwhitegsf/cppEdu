#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <unordered_set>


int longest_sub(std::string str){

    if(str.size() == 0)
        return 0;

    std::unordered_map<char, int> ht;
    int curr_steps{};
    int max_steps{};

    int rhs{};

    while (rhs < str.size()){

        if (ht.contains(str.at(rhs))){
            rhs = ht[str[rhs]]+1;
            max_steps = std::max(max_steps,curr_steps);
            curr_steps=0;
            ht.clear();
        }
        else{
            ht[str[rhs]]=rhs;
            curr_steps++;
            max_steps = std::max(max_steps,curr_steps);
            rhs++;
        }

    }
    return max_steps;
}


int main(){

    std::string s = "thequickbrownfoxjumpsoverthelazydogthequickbrownfoxjumpsovert";

    std::cout << "Longest Non-repeating substring: " << longest_sub(s);


    return 0;
}