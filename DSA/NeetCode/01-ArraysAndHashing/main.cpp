#include <iostream>

// #include "contains_dupes.h"
#include "valid_anagram.h"
// #include "two_sum.h"
#include "group_anagram.h"
#include <ranges>
#include <algorithm>
#include "TopKFreq.h"


using namespace std;

int main() {
    // Contains Dupes
   /* vector<int> vec {1,2,3,4,1,6};
    cout << "Vector has dupes: " << contains_duplicates(vec) << endl;*/

    // Valid Anagram
    string s = "racecar";
    string t = "carrace";
    cout << "is anagram: " << isPermutation(s,t) << endl;



    // Two Sum
   /* std::vector<int> nums{3,5,7,4,};
    int target{8};
    std::pair res = two_sum_ranges(nums, target);
    std::cout << "Two Sum Indices: "<< res.first << ", " <<res.second << std::endl;
*/
    // Group anagram
    /*std::vector<std::string> ga{"act","pots","tops","cat","stop","hat"};
    auto output = group_anagrams2(ga);
    for (const auto& res : output){
        for (const auto &str: res)
            std::cout << str + ',';

        std::cout << '\n';
    }
*/


    // Top K Frequency

    /*std::vector<int> vec {1,2,3,3,5,6,5};

    const auto& output = topKFreq(vec,2);
    for (const auto& res : output){
        std::cout << res <<std::endl;
    }

    topKFreq2(vec,2);*/

    return 0;
}