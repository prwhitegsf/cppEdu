#ifndef CONTAINS_DUPES_H
#define CONTAINS_DUPES_H


#include <unordered_set>
#include <vector>



inline bool contains_duplicates(const std::vector<int>& v) {

    std::unordered_set<int> s{};

    for (int i : v) {
        if (s.contains(i))
            return true;
        else
            s.insert(i);
    }
    return false;
}

inline bool contains_duplicates_by_size(const std::vector<int>& v) {

    return std::unordered_set<int>(v.begin(),v.end()).size() < v.size();
}


#endif //CONTAINS_DUPES_H
