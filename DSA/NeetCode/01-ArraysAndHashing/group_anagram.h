#ifndef GROUP_ANAGRAM_H
#define GROUP_ANAGRAM_H

#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

inline std::vector<std::vector<std::string>> group_anagrams(const std::vector<std::string>& arr){

  std::unordered_map<std::string,std::vector<std::string>> res;

  for (const std::string& str : arr) {

    // Make an array to hold the key
    std::vector<int> v_key(26,0);

    for (char c : str) {
      v_key[c - 'a'] ++;
    }

    // make the array a string so it can be a key for unordered map
    // the other way would be towrite a custom hash function
    std::string key = std::to_string(v_key[0]);
    for (int i=1; i < 26; i++) {
      key += ','+std::to_string(v_key[i]);
    }

    // Add the string to this key
    res[key].push_back(str);

  }

  std::vector<std::vector<std::string>> output;

  /*for (const std::pair<const std::vector<int>,std::vector<std::string>>& s : res) {
    output.push_back(s.second);
  }*/

  for (const auto& [key, value] : res) {
    output.push_back((value));
  }

  return output;

}



#endif //GROUP_ANAGRAM_H
