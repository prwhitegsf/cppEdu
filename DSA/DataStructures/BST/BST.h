//
// Created by prw on 3/3/25.
//

#ifndef CPPEDU_BST_H
#define CPPEDU_BST_H


#include <iostream>
#include <memory>

namespace SimpleBST {

    struct TreeNode{
        int data_{};
        std::unique_ptr<TreeNode> left_{nullptr};
        std::unique_ptr<TreeNode> right_{nullptr};
    };

    auto create_node(int data){
        auto node = std::make_unique<TreeNode>();
        node->data_ = data;
        return std::move(node);
    }

    void insert_node(auto& root, int data){

        if (data < root->data_){
            if (root->left_ == nullptr){
                root->left_ = create_node(data);
                return;
            }
            else
                insert_node(root->left_, data);
        }
        else if (data > root->data_){
            if (root->right_ == nullptr){
                root->right_ = create_node(data);
                return;
            }
            else
                insert_node(root->right_,data);
        }
    }

    void print_node_value(int data){
        std::cout << "node value: " << data <<std::endl;
    }

    void traverse_and_print(auto& node){
        if (node == nullptr)
            return;

        traverse_and_print(node->left_);
        print_node_value(node->data_);
        traverse_and_print(node->right_);


    }

    bool tree_contains_value(auto& node, const int search_value){

        if (node == nullptr)
            return false;
        else if (search_value == node->data_)
            return true;
        else if (search_value < node->data_)
            return tree_contains_value(node->left_, search_value);
        else
            return tree_contains_value(node->right_, search_value);

    }


    auto& balance_tree(auto& node, auto& del_node){

        if (node->left_ != nullptr){
            node->left = balance_tree(node.left_, del_node);
            return std::move(node);
        }
        else{
            del_node->data_ = node->data_;
            return std::move(node->right);
        }
    }

    void remove_tree_node(auto& node, int del_value){

        if (node == nullptr)
            return;

        if (del_value < node->data_){
            remove_tree_node(node->left_, del_value);
            return;
        }
        else if (del_value > node->data_){
            remove_tree_node((node->right_, del_value));
        }
        else{

            if (node->left_ == nullptr || node->right_ == nullptr)
                return;

            node->right_ = balance_tree(node->right, node);


        }

    }





/*Next:
 * Remove node by value
 * Remove all nodes
 * Traverse and print
 * Search
 *
 *
 *
 * */

} // SimpleBST

#endif //CPPEDU_BST_H
