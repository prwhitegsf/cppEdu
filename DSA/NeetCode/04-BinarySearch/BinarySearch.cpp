//
// Created by prw on 3/7/25.
//
/*
You are given an array of distinct integers nums, sorted in ascending order, and an integer target.

Implement a function to search for target within nums. If it exists, then return its index, otherwise, return -1.

Your solution must run in

O(logn) time.
 *
 * */

#include <iostream>
#include <vector>
#include <algorithm>

inline int BinarySearch(std::vector<int> nums, int target){
    auto val = std::lower_bound(nums.begin(),nums.end(),target);
    return val != nums.end() ? std::distance(nums.begin(),val) : -1;
}

int main (){

    std::vector<int> nums{-1, 0, 2, 4, 6, 8};
    int target{6};

    std::cout << "Val at idx: "<< BinarySearch(nums, target)<< std::endl;

    return 0;
}
