//
// Created by prw on 3/2/25.
//

#ifndef TEMPLATE_PRACTICE_STATICARRAY_H
#define TEMPLATE_PRACTICE_STATICARRAY_H

namespace StaticSizeArray {

    template<typename T, int size>
    class StaticArray {

    private:
        T array_[size]{};

    public:
        T* getArray();

        T& operator[](int index){
            return array_[index];
        }

    };

} // StaticSizeArray

using namespace StaticSizeArray;

template<typename T, int size>
T* StaticArray<T,size>::getArray(){
    return array_;
}


#endif //TEMPLATE_PRACTICE_STATICARRAY_H
