
#ifndef TEMPLATE_PRACTICE_ARRAY_H
#define TEMPLATE_PRACTICE_ARRAY_H

#include <cassert>




namespace SimpleArray {

    template<typename T>
    class Array {

    private:
        int length_{};
        T* data_{};

    public:
        explicit Array(int length){
            assert(length > 0);
            data_ = new T[length]{}; // allocate length number of objects of type T
            length_ = length;
        }

        // no copies
        Array(const Array&)=delete;
        Array& operator=(const Array&)=delete;

        // Destructor
        ~Array(){delete[] data_;}

        // erase functionality
        void erase(){
            delete[] data_;
            data_= nullptr;
            length_=0;
        }

        // Signature for operator [] defined outside of class
        T& operator[](int index);

    };

} // SimpleArray

namespace SimpleArray {

    // Members defined outside the class need their own declaration
    template<typename T>
    T& Array<T>::operator[](int index){
        assert(index >= 0 && index < length_);
        return data_[index];
    }

} // SimpleArray



#endif //TEMPLATE_PRACTICE_ARRAY_H
