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

        // next node lives at curr_node->next
        ListNode* next_node = curr_node->next;

        // now that's something we can refer to
        // turn curr_node->next around to point to prev
        curr_node->next = prev_node;

        // now this step moves prev and curr to their respective next nodes
        prev_node = curr_node;
        curr_node = next_node;
    }

    return prev_node;

}








int main(){



    return 0;
}



