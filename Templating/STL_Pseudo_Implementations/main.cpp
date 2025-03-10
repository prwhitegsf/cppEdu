#include <iostream>
#include "vectorlib/Vector.h"
#include "helpers.h"




int main(){

    using namespace vec;

    Vector<int> mv;

    mv.push_back(42);

    helpers::print_item(mv[0]);

    helpers::print_list(mv);

    return 0;
}