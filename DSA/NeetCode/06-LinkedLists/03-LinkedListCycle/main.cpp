#include <iostream>
#include <unordered_map>

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };


inline bool ListCycles(ListNode* head){


    std::unordered_map<ListNode*, int> ht;

    ListNode* curr_node = head;
    int idx{};

    while(curr_node->next){
        idx++;
        if(ht.contains(curr_node->next))
            return true;
        else{
            ht[curr_node->next] = idx;
        }
    }

    return false;


}


int main(){

    ListNode* head = new ListNode(7);

    std::cout << "Node address" << &head << std::endl;

    return 0;
}



