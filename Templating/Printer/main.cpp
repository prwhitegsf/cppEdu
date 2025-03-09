//
// Created by prw on 3/9/25.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <numeric>
#include <random>
#include <algorithm>


template<class T>
void print_item(const T& data, std::string item = ""){
    std::cout << item << data <<std::endl;
}


template<class T>
void print_list(const T& data, std::string item = ""){

    if(data.empty()){
        std::cout << "No data in container"<<std::endl;
        return;
    }

    std::cout << item;

    for(auto& i : data){
        std::cout << i <<' ';
    }

    std::cout<<std::endl;
}

template<class T>
void print_key_value(const T& data, std::string item = ""){

    if(data.empty()){
        std::cout << "No data in container"<<std::endl;
        return;
    }

    std::cout << item;

    for(auto& [key, value] : data){
        std::cout<< "key: " << key << " value: "<< value << std::endl;
        return;
    }
}

template<class T>
void print_map_list(const T& data, std::string item = ""){

    if(data.empty()){
        std::cout << "No data in container"<<std::endl;
    }

    std::cout << item;

    for(auto& [key, list] : data){

        std::cout<< "key: " << key << " values: ";

        for(auto& val : list){
            std::cout << val << ' ';
        }

        std::cout<<std::endl;

    }
}

std::vector<int>GenerateInts(int start, int len, bool sort=false){

    std::vector<int>nums(len);
    std::iota(nums.begin(),nums.end(),start);

    if(!sort)
        std::shuffle(nums.begin(), nums.end(), std::mt19937{std::random_device{}()});

    return nums;
}



using namespace std;

int main(){

    string s{"Print test string"};
    print_item(s,"heyo --- ");


    vector<int> nums{1,2,7,4,8,3};
    vector<string> words{"car","dog","cat","toy","pogo","bat"};
    print_list((nums));
    print_list((words));


    unordered_map<int,string> kv;
    for(int i{}; i < 6; ++i)
        kv.insert({nums[i],words[i]});

    print_key_value(kv);



    unordered_map<int,vector<string>> key_list;
    for(int i{}; i < 6; ++i) {
        key_list.insert({nums[i],words});
    }
    print_map_list(key_list);

    std::vector<int> vec(10);
    std::iota(vec.begin(),vec.end(),5);
    std::shuffle(vec.begin(), vec.end(), std::mt19937{std::random_device{}()});
    print_list(vec);



    return 0;
}