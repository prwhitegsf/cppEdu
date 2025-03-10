//
// Created by prw on 3/2/25.
//
#include <iostream>
#include "ContainerLib/Array.h"

int main()
{
    using namespace SimpleArray;


        const int length{12};
        Array<int> intArray{length};
        Array<double> doubleArray{length};

        for (int count{0}; count < length; ++count) {
            intArray[count] = count;
            doubleArray[count] = count + 0.5;
        }

        for (int count{length - 1}; count >= 0; --count)
            std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';

    return 0;
}