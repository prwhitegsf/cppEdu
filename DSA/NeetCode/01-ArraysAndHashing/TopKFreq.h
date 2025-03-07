#ifndef CPP_TOPKFREQ_H
#define CPP_TOPKFREQ_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <map>

using IntVec = std::vector<int>;

inline void print_vec(IntVec & vec){
    if (vec.empty())
        return;

    for (int v : vec)
        std::cout << "Vec: " << v <<std::endl;

}


inline IntVec topKFreq(IntVec & nums, int k){

    // Make a hash table with each value and it's freq
    std::unordered_map<int, int> count_table;

    for (int num : nums){
        if(!count_table.contains(num))
            count_table.insert({num, 1});
        else
            count_table[num] += 1;
    }

    // Make a vector of buckets
    // the index corresponds to the frequency
    std::vector<IntVec> buckets(nums.size());

    // then fill it
    for (auto& [key, value] : count_table){
        buckets[value].push_back(key);
    }

    IntVec result;
    result.reserve(k);

    for(auto vec = buckets.rbegin();
             vec != buckets.rend(); vec++){

        if(vec->empty())
            continue;

        for (auto v : *vec)
            result.push_back(v);

        if (result.size() == k)
            break;


    }



    return result;

}

struct topK{
    std::vector<int> topk;
    int max_val{};

};


inline void topKFreq2(IntVec& nums, int k) {

    // Make a hash table with each value and it's freq
    std::unordered_map<int, int> count_table;


    for (int num: nums) {
        if (!count_table.contains(num))
            count_table.insert({num, 1});
        else
            count_table[num] += 1;
    }

    std::map<int, std::vector<int>,std::greater<>> freqs;
    for(auto& row : count_table){
        freqs[row.second].push_back(row.first);

    }

    for(auto&[key,value] : freqs){
        std::cout << "key: " << key << "\nvalues: ";
        for(auto val : value){
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }
    /*auto key_view = count_table | std::views::keys;
    auto value_view = count_table | std::views::values;
     for (auto i : value_view) {
        std::cout << "value view: " << i << std::endl;
    }
*/








}


#endif //CPP_TOPKFREQ_H
