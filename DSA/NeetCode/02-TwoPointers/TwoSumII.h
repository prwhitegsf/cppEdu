#ifndef CPP_TWOSUMII_H
#define CPP_TWOSUMII_H

/* Two Integer Sum II
Given an array of integers numbers that is sorted in non-decreasing order.

 Return the indices (1-indexed) of two numbers, [index1, index2],
    - such that they add up to a given target number target and index1 < index2.

Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.

There will always be exactly one valid solution.

Your solution must use O(1) additional space.

 */



#include <vector>
#include <unordered_map>

inline std::vector<int> two_sum_2(const std::vector<int>& nums, const int target){

    int sz = nums.size();
    int lhs = 0;
    int rhs = sz - 1;

    std::vector<int> result(2);

    while (lhs < rhs){

        int sum = nums[lhs] + nums[rhs];

        if (sum == target) {
            result.push_back(lhs+1);
            result.push_back(rhs+1);
            break;
        }
        else if (sum < target)
            lhs++;
        else
            rhs--;
    }
    return result;
}




#endif //CPP_TWOSUMII_H
