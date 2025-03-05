#ifndef GROUP_ANAGRAM_H
#define GROUP_ANAGRAM_H

#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using anagrams = std::vector<std::string>;
using groups = std::vector<anagrams>;


inline groups group_anagrams(const anagrams& arr){

  std::unordered_map<std::string,anagrams> res;

  for (auto& str : arr) {

    // Make an array to hold the key
    std::vector<int> v_key(26,0);

    for (char c : str) {
      v_key[c - 'a'] ++;
    }

    // make the array a string so it can be a key for unordered map
    // the other way would be towrite a custom hash function
    std::string key;
    for (int count : v_key) {
      key += ','+std::to_string(count);
    }

    // Add the string to this key
    res[key].emplace_back(str);

  }

  groups output;

  for(auto& ana: res) {
    output.push_back((ana.second));
  }

  return output;

}



#endif //GROUP_ANAGRAM_H
