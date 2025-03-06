#ifndef CONTAINS_DUPES_H
#define CONTAINS_DUPES_H


#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>




inline bool contains_duplicates(const std::vector<int>& v) {

    std::unordered_set<int> s{};
    // Lazy evaluation
    for (int i : v) {
        if (s.contains(i)) // Avg O(1), O(n) worst case
            return true;
        else
            s.insert(i); // Avg O(1)
    }
    return false;
}

inline bool contains_duplicates_by_size(const std::vector<int>& v) {

    return std::unordered_set<int>(v.begin(),v.end()).size() < v.size();
}

// using ranges
// Not sure if there's a useful applicaiton of that here

#endif //CONTAINS_DUPES_H
