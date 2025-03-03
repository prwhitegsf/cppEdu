#ifndef CPP_TOPKFREQ_H
#define CPP_TOPKFREQ_H

#include <vector>
#include <unordered_map>
#include <iostream>


inline std::vector<int> topKFreq(const std::vector<int>& nums, int k){

    // Make a hash table with each value and it's freq
    std::unordered_map<int, int> count_table;

    for (int num : nums){
        if(!count_table.contains(num))
            count_table[num] = 1;
        else
            count_table[num] += 1;
    }

    // Make a vector of buckets
    // the index corresponds to the frequency
    std::vector<std::vector<int>> buckets(nums.size());

    // then fill it
    for (const auto& [key, value] : count_table){
        buckets[value].push_back(key);
    }

    std::vector<int> result;

    for (auto i = buckets.rbegin(); i!= buckets.rend();i++){
        auto& vec = *i;
        if (!vec.empty()){
            for (const int v : vec){
                result.push_back((v));

                if (result.size() == k)
                    return result;
            }
        }
    }



}



#endif //CPP_TOPKFREQ_H
