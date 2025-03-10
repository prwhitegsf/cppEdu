//
// Created by prw on 3/9/25.
//

#ifndef CPPEDU_LINKEDLIST_H
#define CPPEDU_LINKEDLIST_H


#include <memory>
#include <iostream>
#include "helpers.h"
#include <vector>

namespace LinkedList {

    struct ListNode {

    public:
        int data_;
        std::shared_ptr<ListNode> next_;

        ListNode()
                : data_(0), next_(nullptr) {}

        ListNode(int data)
                : data_(data), next_(nullptr) {}
    };

// -------------------------------------------------------
// -------------------------------------------------------

using NodePtr = std::shared_ptr<ListNode>;


    NodePtr create_node(int data){
        return std::make_shared<ListNode>(ListNode(data));
    }


    NodePtr append(NodePtr& head, int data){
        if(head == nullptr) {
            head = create_node(data);
            return head;
        }

        NodePtr iter = head;

        // Go to end of list and add node
        while(iter->next_ != nullptr)
            iter = iter->next_;

        iter->next_ = create_node(data);

        return iter->next_;
    }


    NodePtr reverse_list(NodePtr head){
        if (head == nullptr)
            return nullptr;

        NodePtr  node = head;
        NodePtr prev_node = nullptr;

        while(node != nullptr){
            NodePtr next_node = node->next_;
            node->next_ = prev_node;
            prev_node = node;
            node = next_node;

        }

        return prev_node;
    }

    // O(n) but the code logic could certainly be cleaned up
    // Specifically, there should be a way to avoid doing all these null checks 2x
    NodePtr merge_lists(NodePtr list1, NodePtr list2){

        // One or both of the lists == empty
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;

        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;

        // Set the head - this is that node we return
        // it needs to be different from the node we iterate with
        NodePtr head;

        if(list1->data_ <= list2->data_){
            head = list1;
            list1 = list1->next_;
        }
        else{
            head = list2;
            list2 = list2->next_;
        }

        // Iterate over the lists
        NodePtr node = head;

        while(node != nullptr){
            // Primary merging condition
            if (list1 != nullptr && list2 != nullptr) {
                if (list1->data_ <= list2->data_) {
                    node->next_ = list1;
                    list1 = list1->next_;
                    node = node->next_;
                } else {
                    node->next_ = list2;
                    list2 = list2->next_;
                    node = node->next_;
                }
            } // process when we run out of members
            else if (list2 == nullptr){
                node->next_ = list1;
                return head;
            }
            else if(list1 == nullptr){
                node->next_ = list2;
                return head;
            }
        }
        return head;
    }



    void PrintList(NodePtr& head){

        if(head == nullptr){
            std::cout << "List Empty" << std::endl;
            return;
        }

        NodePtr iter = head;
        int idx{};

        while(iter != nullptr) {
            std::cout << "idx: " << idx << " data: " << iter->data_ << std::endl;
            iter = iter->next_;
            idx++;
        }
    }


    NodePtr GenerateList(int start, int len, bool sort=false){

        std::vector<int> nums = helpers::GenerateInts(start,len,sort);

        NodePtr head(0);

        for(auto num : nums)
            append(head, num);

        return head;

    }



}


#endif //CPPEDU_LINKEDLIST_H
