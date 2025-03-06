#ifndef GROUP_ANAGRAM_H
#define GROUP_ANAGRAM_H

#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <array>
#include <algorithm>
#include <ranges>
#include <iostream>

using anagrams = std::vector<std::string>;
using groups = std::vector<anagrams>;


inline groups group_anagrams(const anagrams& arr){

  std::unordered_map<std::string,anagrams> res;

  for (auto& str : arr) {

    // Make an array to hold the key
    const int key_len{26};
    std::array<int,key_len> v_key{0};


    for (char c : str) {
      v_key[c - 'a'] ++;
    }

    // make the array a string so it can be a key for unordered map
    // surely a better technique for this?
    // We can at least reserve the appropriate capacity
    std::string key;
    key.reserve(key_len);

    for (int count : v_key) {
        // cool that this works, implicit int to char conversion good enough for us here
      key.push_back(count);
    }

    // Add the string to this key
    // construct in place to avoid extra mem alloc/dealloc cycle
    res[key].emplace_back(str);

  }

  groups output;

  for(auto& ana: res) {
    output.push_back((ana.second));
  }

  return output;

}




void print(auto anas){
    if (anas.empty())
        return;

    for(auto ana : anas ){ // Computation happens here.
        std::cout << ana << " ";
    }
    std::cout << std::endl;
}


// Ranges version
std::string make_ana_hash(const std::string& str){

    // Make an array to hold the key
    const int key_len{26};
    std::array<int,key_len> v_key{0};

    for (char c : str) {
        v_key[c - 'a'] ++;
    }

    // make the array a string so it can be a key for unordered map
    // surely a better technique for this?
    std::string key;
    key.reserve(key_len);

    for (int count : v_key) {
        // cool that this works, implicit int to char conversion good enough for us here
        key.push_back(count);
    }

    return key;

}

auto group_anagrams2(anagrams& arr){

    std::unordered_map<std::string,anagrams> res;

   for (auto str : arr){
       res[make_ana_hash(str)].emplace_back(str);
   }

    groups output;

    for(auto& ana: res) {
        output.push_back((ana.second));
    }

    //auto anas = std::views::values(res);
    for (auto anas : res | std::views::values){
        for (auto ana : anas){
            std::cout << ana << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout <<"---------------------------------" << std::endl;
    std::cout << std::endl;




    return output;
}









#endif //GROUP_ANAGRAM_H
