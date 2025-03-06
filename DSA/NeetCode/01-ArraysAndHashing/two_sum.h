#ifndef TWO_SUM_H
#define TWO_SUM_H

#include <unordered_map>
#include <ranges>
#include <utility>
#include <vector>

// my solution
inline std::pair<int,int> two_sum(const std::vector<int>& nums, const int target) {

    std::unordered_map<int, size_t> ht{};

    for (size_t i{0}; i < nums.size();i++) {
        int other_num = target - nums[i];

        if (ht.contains(other_num))
            return std::make_pair(ht[other_num],i);
        else
            ht.insert({nums[i], i});

    }
    return std::make_pair(0,0);
}

// With ranges
inline std::pair<int,int> two_sum_ranges(const std::vector<int>& nums, const int target) {

    std::unordered_map<int, size_t> ht{};

    for (auto const [index, num] : std::views::enumerate(nums)){
        int other_num = target - num;

        if (ht.contains(other_num))
            return std::make_pair(ht[other_num],index);
        else
            ht.insert({num, index});

    }

    return {};
}

// neetcode solution
inline std::vector<int> nc_two_sum(const std::vector<int>& nums, const int target) {

        int n = nums.size();
        std::unordered_map<int, int> prevMap;

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (prevMap.find(diff) != prevMap.end()) {
                return {prevMap[diff], i};
            }
            prevMap.insert({nums[i], i});
        }
        return {};
}




#endif //TWO_SUM_H
