#ifndef VALID_ANAGRAM_H
#define VALID_ANAGRAM_H


#include <unordered_map>
#include <string_view>
#include <string>
#include <vector>


// My solution
inline bool valid_anagram(std::string_view s, std::string_view t) {

    if (s.size() != t.size())
        return false;

    std::unordered_map<char,int> map{};

    for (char letter : s) {
        if (map.contains(letter)) {
            map[letter] += 1;
        }
        else {
            map[letter] = 1;
        }
    }

    for (char letter : t) {
        if (map.contains(letter)) {
            map[letter] -= 1;
        }
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
        for (int i = 0; i < s.length(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
    }

// Hash table optimized
// Again like the python version
// with c++ we don't need to use a function to get the char values, we can just use them
// However this may not work with stringview

 inline bool nc2_isAnagram(const std::string& s, const std::string& t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }


#endif //VALID_ANAGRAM_H
