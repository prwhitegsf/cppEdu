#include <iostream>
#include <vector>

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
    };


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    // Empties
    if (list1 == nullptr && list2 == nullptr)
        return nullptr;

    if (list1 == nullptr)
        return list2;

    if (list2 == nullptr)
        return list1;


    ListNode* primaryNode = list1;
    ListNode* insertNode = list2;


    while(primaryNode != nullptr){

        if (primaryNode->val <= insertNode->val)
            primaryNode = primaryNode->next;
        else{
            primaryNode->next = insertNode;
            while (insertNode != nullptr && insertNode->val <= primaryNode->val){
                insertNode = insertNode->next;
            }
        }

    }
}


ListNode* InsertIntoList(ListNode* head, int val){

    ListNode* new_node = new ListNode(val);

    if (head == nullptr){
        head = new_node;
        return head;
    }

    ListNode* node_iter = head;

    while(node_iter->next)
        node_iter = node_iter->next;


    node_iter->next = new_node;

    return new_node;

}

void PrintList(ListNode* node){

    while(node != nullptr){

        std::cout << node->val << ' ';
        node = node->next;

    }



}





int main(){

    std::vector arr1 {1,2,3,4,5,6,7};

    setvbuf(stdout, NULL, _IONBF, 0);
    std::cout << "arr size: " << arr1.size() << std::endl;

    ListNode head(0);

    for (auto i : arr1){

        InsertIntoList(&head, i);


    }


    PrintList(&head);

    return 0;
}



