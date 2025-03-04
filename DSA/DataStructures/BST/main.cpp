//
// Created by prw on 3/4/25.
//
#include "BST.h"
#include <vector>
#include <iostream>


int main(){


    using namespace SimpleBST;


    auto root = create_node(25);

    std::vector<int> vec {43,23,78,22,53,1,65,3,89,67,34,76,2,27};

    for(auto v : vec){
        insert_node(root, v);
    }


    // traverse_and_print(root);
    tree_contains_value(root, 43);

    std::cout << "value found: " << tree_contains_value(root, 43) << std::endl;


    return 0;
}