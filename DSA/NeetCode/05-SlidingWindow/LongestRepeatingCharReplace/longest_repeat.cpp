#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>


using HT = std::unordered_map<char,std::vector<int>>;

// This version loops through the string, pushing each char to a hash table
// The table is laid out char : indices where char shows up
// Then we loop through the vectors for each char checking the distances between indices
// we then subtract that distance from k
// In other words, we got k "wild card" chars we can use to fill gaps between non-consecutive chars
// So we iterate over the vectors tracking how many k's we use if we were to fill in the non-repeats
// ToDo: Edit while loop to keep going after k >= 0 is hit, but clear the current count
// ugh and I'd need to go back to the last start + 1 like in longest substring
int longest_repeat(std::string& str, int k){

    if(k == str.size())
        return k;

    int max_repeat{};
    HT ht;

    int i{};
    for(auto& s : str){
        ht[s].push_back(i);
        i++;
    }

    for(auto& [key, values] : ht){


        if(values.size() == 1)
            max_repeat=std::max(max_repeat, (1+k));

        int kslots{k};
        int curr_repeats{k+1};
        int rhs{1};

        while(kslots >= 0 && rhs < values.size()){

            int diff = values[rhs]-values[rhs-1];

            if(diff > 1)
                kslots -= (diff-1);


            curr_repeats++;
            rhs++;

        }

        max_repeat=std::max(max_repeat,curr_repeats);


    }




    // Print
  /*  for(auto& [key, values] : ht)
    {
        std::cout<< "key: " << key << " values: ";
        if(!values.empty()) {
            for (auto v: values) {
                std::cout << v << ", ";
            }
            std::cout << std::endl;
        }
    }*/

    return max_repeat;

}


int main(){

    std::string s = "aabce";
    int k = 2;

    std::cout << "Longest repeat: "<< longest_repeat(s, k);

    return 0;
}