//
// Created by prw on 2/21/25.
//

#ifndef CPP_THREESUM_H
#define CPP_THREESUM_H

#include <set>
#include <vector>
#include <algorithm>
#include <array>


inline std::vector<std::array<int,3>> ThreeSum(std::vector<int>& nums) {

    // std::sort operates on original, so it can't be const
    std::sort(nums.begin(),nums.end(),std::less<int>());

    std::set<std::array<int,3>> found{};

    // if in c++ 23 we could use views along with an enumerate function to loop like with enumerate in python
    for (int i{}; i < nums.size(); i++){

        int target = 0 - nums[i];
        int lhs = i + 1;
        int rhs = nums.size() - 1;

        while (lhs < rhs){
            int sum = nums[lhs] + nums[rhs];

            if (sum == target){
                std::array<int, 3> res {nums[i], nums[lhs],nums[rhs]};
                found.insert(res);
                lhs++;
                rhs--;
            }
            else if (sum < target)
                lhs++;
            else
                rhs--;
        }
    }

    std::vector<std::array<int, 3>> output{};

    for (const auto& arr : found){
        output.push_back((arr));
    }

    return output;
}
















#endif //CPP_THREESUM_H
