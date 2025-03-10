//
// Created by prw on 3/10/25.
//
#include <iostream>

#include "LinkedList.h"









int main(){


    using namespace LinkedList;

// Reverse List

    /*NodePtr listHead = GenerateList(1,10,true);
    PrintList(listHead);

    NodePtr reversed = reverse_list(listHead);
    PrintList(reversed);
    */

// Merge Two Sorted Lists

    NodePtr list1 = GenerateList(1,10,true);
    NodePtr list2 = GenerateList(5,10,true);

    NodePtr merged = merge_lists(list1, list2);
    PrintList(merged);




    return 0;
}







