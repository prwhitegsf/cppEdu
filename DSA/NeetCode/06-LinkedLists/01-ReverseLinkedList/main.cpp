#include <iostream>

// lol
// Next:

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };





ListNode* reverseList(ListNode* head) {

    if(head == nullptr)
        return nullptr;

    ListNode* curr_node = head;
    ListNode* prev_node = nullptr;

    while(curr_node != nullptr){

        ListNode* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    return prev_node;

}


int main(){



    return 0;
}



