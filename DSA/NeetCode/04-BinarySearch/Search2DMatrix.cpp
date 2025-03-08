//
// Created by prw on 3/7/25.
//
/*
You are given an m x n 2-D integer array matrix and an integer target.

Each row in matrix is sorted in non-decreasing order.
The first integer of every row is greater than the last integer of the previous row.
Return true if target exists within matrix or false otherwise.

Can you write a solution that runs in O(log(m * n)) time?

 */

#include <vector>
#include <iostream>
#include <ranges>
#include <algorithm>

using TwoD = std::vector<std::vector<int>>;

inline bool Search2D(TwoD& matrix, int target){

    // the ideal here would be to slice off a view that includes the first element or each row
    // ie the first column, but not sure how to do that ...
    int top{0};
    int bottom{static_cast<int>(matrix.size()-1)};
    int target_row{};

    while (top < bottom){

        int mid_idx = (bottom - top) / 2;

        // front value happens to be the target
        if(matrix[mid_idx].front() == target)
            return true;

        // found target row
        if(matrix[mid_idx].front() <= target && matrix[mid_idx].back() >= target) {
            target_row = mid_idx;
            break;
        }

        // binary search of first column
        if (matrix[mid_idx].front() < target)
            top = mid_idx + 1;
        else
            bottom = mid_idx-1;
    }

    return std::binary_search(matrix[target_row].begin(),matrix[target_row].end(),target);



    // auto row = std::lower_bound(matrix.begin(),matrix.end()->front(),target);

}



int main(){

    TwoD matrix{{1,2,4,8},{10,11,12,13},{14, 20, 30, 40}};
    int search{76};

    std::cout << "num found: " << Search2D(matrix, search);

    return 0;
}

