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


    //
    NodePtr append(NodePtr& head, int data){
        if(head == nullptr)
            return create_node(data);

        NodePtr iter = head;

        // Go to end of list and add node
        while(iter->next_ != nullptr)
            iter = iter->next_;

        iter->next_ = create_node(data);

        return std::move(iter->next_);
    }




    void PrintList(NodePtr& head){

        if(head == nullptr){
            std::cout << "List Empty" << std::endl;
            return;
        }

        NodePtr iter = head;
        int idx{};

        while(iter != nullptr)
            std::cout << "idx: " << idx << " data: " << iter->data_ << std::endl;

    }


    NodePtr GenerateList(int start, int len, bool sort=false){

        std::vector<int> nums = helpers::GenerateInts(start,len,sort);

        NodePtr head;
        for(auto num : nums)
            append(head, num);

        return head;

    }



}


#endif //CPPEDU_LINKEDLIST_H
