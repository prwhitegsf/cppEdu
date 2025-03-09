//
// Created by prw on 3/9/25.
//
#ifndef CPPEDU_HELPERS_H
#define CPPEDU_HELPERS_H


#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>

namespace helpers {

    template<class T>
    void print_item(const T &data, std::string item = "") {
        std::cout << item << data << std::endl;
    }


    template<class T>
    void print_list(const T &data, std::string item = "") {

        if (data.empty()) {
            std::cout << "No data in container" << std::endl;
            return;
        }

        std::cout << item;

        for (auto &i: data) {
            std::cout << i << ' ';
        }

        std::cout << std::endl;
    }

    template<class T>
    void print_key_value(const T &data, std::string item = "") {

        if (data.empty()) {
            std::cout << "No data in container" << std::endl;
            return;
        }

        std::cout << item;

        for (auto &[key, value]: data) {
            std::cout << "key: " << key << " value: " << value << std::endl;
            return;
        }
    }

    template<class T>
    void print_map_list(const T &data, std::string item = "") {

        if (data.empty()) {
            std::cout << "No data in container" << std::endl;
        }

        std::cout << item;

        for (auto &[key, list]: data) {

            std::cout << "key: " << key << " values: ";

            for (auto &val: list) {
                std::cout << val << ' ';
            }

            std::cout << std::endl;

        }
    }

    std::vector<int> GenerateInts(int start, int len, bool sort = false) {

        std::vector<int> nums(len);
        std::iota(nums.begin(), nums.end(), start);

        if (!sort)
            std::shuffle(nums.begin(), nums.end(), std::mt19937{std::random_device{}()});

        return nums;
    }


}

#endif //CPPEDU_HELPERS_H
