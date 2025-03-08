#ifndef VALID_ANAGRAM_H
#define VALID_ANAGRAM_H


#include <unordered_map>
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>


// My solution
inline bool valid_anagram(std::string_view s, std::string_view t) {

    if(s.size() != t.size())
        return false;

    std::unordered_map<char, int> smap;

    for(char c : s) {
        if (smap.contains(c))
            smap[c]++;
        else
            smap.insert({c, 1});
    }

    for (char c : t){
        if (smap.contains(c))
            smap[c]--;
        else
            return false;
    }

    return true;
}



// Neetcode solutions - these don't use stringview or contains
// 2 hash tables
// like the python, we write both to unordered maps with their respective char counts and then compare
inline bool nc1_isAnagram(const std::string& s, const std::string& t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> countS;
        std::unordered_map<char, int> countT;
        for (int i = 0; i < s.length(); i++) { // O(n)
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT; // member wise comparison, O(n)
    }

// Hash table optimized
// Again like the python version
// with c++ we don't need to use a function to get the char values, we can just use them

 inline bool nc2_isAnagram(const std::string& s, const std::string& t) {
        if (s.length() != t.length()) {
            return false;
        }

        // O(n)
        std::vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        // 26 or O(1)
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }

inline bool nc3_isAnagram(std::string_view s, std::string_view t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::vector<int> count(26, 0);
    for (int i = 0; i < s.length(); i++) { // O(n)
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    // O(1)
    for (int val : count) {
        if (val != 0) {
            return false;
        }
    }
    return true;
}


// with is permutation
inline bool isPermutation(const std::string& s, const std::string& t){
    return std::is_permutation(s.begin(),s.end(),t.begin());
}


#endif //VALID_ANAGRAM_H
