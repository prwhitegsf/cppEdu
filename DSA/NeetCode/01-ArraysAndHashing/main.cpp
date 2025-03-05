#include <iostream>

//#include "valid_anagram.h"
#include "two_sum.h"
#include "group_anagram.h"
#include "TopKFreq.h"




int main() {
    // Contains Dupes
    // std::vector<int> vec {1,2,3,3,5,6};


    // Valid Anagram
    // std::string s = "racecar";
    // std::string t = "carrace";
    // std::cout << nc1_isAnagram(s,t) << std::endl;

    // Two Sum
    // std::vector<int> nums{3,5,7,4,};
    // int target{11};
    // std::pair res = two_sum(nums, target);
    // std::cout << res.first << ", " <<res.second << std::endl;

    // Group anagram
    std::vector<std::string> ga{"act","pots","tops","cat","stop","hat"};
    auto output = group_anagrams(ga);
    for (const auto& res : output){
        for (const auto &str: res)
            std::cout << str + ',';

        std::cout << '\n';
    }

    // Top K Frequency
    /*
    const std::vector<int> vec {1,2,3,3,5,6,5};

    const auto& output = topKFreq(vec,2);
    for (const auto& res : output){
        std::cout << res <<std::endl;
    }*/

    return 0;
}