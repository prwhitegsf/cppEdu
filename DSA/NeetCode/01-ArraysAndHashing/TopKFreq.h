#ifndef CPP_TOPKFREQ_H
#define CPP_TOPKFREQ_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

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
        vec != buckets.rend();
        vec++)
    {

        if(vec->empty())
            continue;

        for (auto v : *vec)
            result.push_back(v);

        if (result.size() == k)
            break;


    }



    return result;

}



#endif //CPP_TOPKFREQ_H
