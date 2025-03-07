//
// Created by prw on 3/7/25.
//
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <map>
#include <functional>

using IntVec = std::vector<int>;


class MapNums{

public:
    MapNums(std::unordered_map<int, int>& count_table)
    : count_table_(count_table){}

    void operator()(int num){
        if (!count_table_.contains(num))
            count_table_.insert({num, 1});
        else
            count_table_[num] += 1;
    }


    std::unordered_map<int, int>& count_table_;

};




inline void topKFreq2(IntVec& nums, int k) {


    // Make a hash table with each value and it's freq
    std::unordered_map<int, int> count_table;

   /* std::function<void(std::unordered_map<int, int>)> pv = [&count_table](std::unordered_map<int, int>){
        for (auto &[key, value]: count_table) {
            std::cout << "key: " << key << "value: " << value << std::endl;

        }
    };*/
    MapNums mapNums(count_table);
    std::function<void(int)> pm =mapNums;

    //MapNums mapNums(count_table);
/*
    place_values = [&count_table](int num)->void{
        if (!count_table.contains(num))
            count_table.insert({num, 1});
        else
            count_table[num] += 1;
    };
*/
    std::for_each(nums.begin(), nums.end(), pm);

    //std::for_each(nums.begin(), nums.end(), MapNums(count_table));
    //pv(count_table);

/*    std::for_each(nums.begin(), nums.end(), [&count_table](int num)->void{
        if (!count_table.contains(num))
            count_table.insert({num, 1});
        else
            count_table[num] += 1;
    });*/

    /*for (int num: nums) {
        if (!count_table.contains(num))
            count_table.insert({num, 1});
        else
            count_table[num] += 1;
    }*/

    std::map<int, std::vector<int>, std::greater<>> freqs;
    for (auto &row: count_table) {
        freqs[row.second].push_back(row.first);

    }

    for (auto &[key, value]: freqs) {
        std::cout << "key: " << key << "\nvalues: ";
        for (auto val: value) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }

}

int main(){


    std::vector<int> vec {1,2,3,3,5,6,5};

 /*   const auto& output = topKFreq2(vec,2);
    for (const auto& res : output){
        std::cout << res <<std::endl;
    }
*/
    topKFreq2(vec,2);

    return 0;



    return 0;
}

/*
    std::map<int, std::vector<int>, std::greater<>> freqs;
    for (auto &row: count_table) {
        freqs[row.second].push_back(row.first);

    }

    for (auto &[key, value]: freqs) {
        std::cout << "key: " << key << "\nvalues: ";
        for (auto val: value) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }*/