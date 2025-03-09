#ifndef STL_IMPLEMENTATIONS_VECTOR_H
#define STL_IMPLEMENTATIONS_VECTOR_H

#include <memory>   // std::allocator
#include <cstddef>  // std::size_t, std::ptr_diff_t
#include <iterator> // std::distance
#include <stdexcept>




namespace vec {

    template <class T, class Allocator = std::allocator<T>>
    class Vector {

    public:

        /*CPP Standard named requirements for containers*
         * https://en.cppreference.com/w/cpp/named_req/Container */

        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;
        using difference_type = std::ptrdiff_t;
        using size_type = std::size_t;
        using allocator_type = Allocator;

        /*Constructors
         * default
         * fill
         * range
         * copy
         * move
         * initializer list
         * */

        // default constructors
        Vector() noexcept;
        explicit Vector(const allocator_type& alloc);

        // Fill Constructors
        explicit Vector(const size_type numOfElements, const allocator_type& alloc=allocator_type());
        Vector(size_type numOfElements, const value_type& fillValue, const allocator_type& alloc=allocator_type());

        ~Vector() noexcept(std::is_nothrow_destructible_v<value_type>);  // Destructor

        // Size and capacity checks -----------------------------------------------------

        bool empty()         const noexcept { return (sz == 0);   }
        size_type size()     const noexcept { return sz;          }
        size_type capacity() const noexcept { return cap;         }
        size_type max_size() const noexcept { return std::allocator_traits<Allocator>::max_size(allocator); }


        // Iterators
        iterator begin() noexcept {return data;}
        iterator end()  noexcept {return data + sz;}

        // Push Back
        void push_back(const_reference value);      // Push back by copying


        // Allocator
        allocator_type get_allocator() const noexcept { return  allocator; }

    private:
        size_type sz = 0;
        size_type cap =0;
        T* data = nullptr;
        Allocator allocator;

        // Helpers -----------------------------

        // Mem allocation
        T* grow(size_type newCap, bool copy=false, size_type gapIndex=0, size_type gapSize=0);



        // Clean up
        void destroyRange(iterator from, iterator to);
        void destroyPointer(iterator ptr);


    };

} // vec

using namespace vec;

// Helper
// Finds the next power of 2 which is greater than N.
std::size_t nextPowerOf2(std::size_t N)
{
    if(0 == N)
        return 1u;

    std::size_t maxValuedBit = 1u;

    while(0 != N) {
        N = N >> 1;
        maxValuedBit = maxValuedBit << 1;
    }

    return maxValuedBit;
}


// Default Constructor
// When vector is called without any arguments
template<class T, class Allocator>
Vector<T, Allocator>::Vector() noexcept
        : sz(0), cap(0), data(nullptr)
{/*empty*/ }


// Constructor with allocator
template<class T, class Allocator>
Vector<T, Allocator>::Vector(const allocator_type& alloc)
        : sz(0), cap(0), data(nullptr), allocator(alloc)
{}


// Fill Constructor
template<class T, class Allocator>
Vector<T, Allocator>::Vector(const size_type numOfElements, const allocator_type& alloc)
: sz(0), cap(nextPowerOf2(numOfElements)), data(nullptr), allocator(alloc)
{

    try{
        // Allocate space for incoming elements
        // Construction will take place at each element insertion
        data = std::allocator_traits<Allocator>::allocate(allocator, cap);

        // construct elements at predetermined locations
        for(; sz < numOfElements; ++sz)
            std::allocator_traits<Allocator>::construct(allocator,data+sz);

    }
    catch(...){
        destroyRange((begin(), end()));
        destroyPointer(data);
    }
}






// Post construction Writes ------------------------------------------------------

// push_back
template<class T, class Allocator>
void Vector<T, Allocator>::push_back(const_reference value) {

    if(size()==capacity()) // container is about to overflow
    {

        value_type* newData = grow(nextPowerOf2(cap),true);

        destroyRange(begin(), end());
        destroyPointer(data);

        data = newData;
        cap = nextPowerOf2(cap);

    }

    std::allocator_traits<Allocator>::construct(allocator, data+sz, value);
    sz++;

}

// Allocation/Resizing

// grow
template<class T, class Allocator>
T* Vector<T, Allocator>::grow(size_type newCap, bool copy, size_type gapIndex, size_type gapSize)
{

    if(newCap < cap + gapSize)
        throw std::invalid_argument("Cannot grow to a smaller capacity");

    if (gapIndex > size())
        throw std::invalid_argument("Cannot create gap outside of container");


    // Make new space
    value_type* newData = std::allocator_traits<Allocator>::allocate(allocator, newCap);

    size_type copied = 0;

    if(copy)
    {
        // size_type copied = 0; // moved this to outside of conditional b/c we access it in the else

        if(gapSize > 0){

            try{
                // Copy construct items on left side of gap
                for(; copied < gapIndex; ++copied)
                    std::allocator_traits<Allocator>::construct(allocator,newData+copied,*(data+copied));

                // Copy construct on right side of gap
                for (;copied < sz; ++copied)
                    std::allocator_traits<Allocator>::construct(allocator, newData+copied+gapSize,*(data + copied));


            }
            catch(...){

                // Destruct items on right side
                for (; copied > gapIndex; --copied)
                    std::allocator_traits<Allocator>::destroy(allocator, newData + copied + gapSize - 1);

                // Destruct items on left
                for (; copied > 0; --copied)
                    std::allocator_traits<Allocator>::destroy(allocator, newData+copied-1);

                destroyPointer((newData));
                throw; //propogate exception

            }
        }
        else{

            try{
                // Copy construct elements at new space
                for(; copied < sz;++copied)
                    std::allocator_traits<Allocator>::construct(allocator, newData+copied,*(data+copied));
            }
            catch(...){

                // Destroy copied objects
                for (; copied > 0; --copied)
                    std::allocator_traits<Allocator>::destroy(allocator, newData+copied-1);

                destroyPointer(newData);
                throw;
            }
        }

    }

    return newData;

}



// Clean Up -----------------------------------------------------------------------

// Destructor
template<class T, class Allocator>
Vector<T,Allocator>::~Vector() noexcept(std::is_nothrow_destructible_v<T>)
{
    destroyRange(begin(), end());
    destroyPointer(data);

    sz = 0;
    cap = 0;
    data = nullptr;

}


template<class T, class Allocator>
void Vector<T, Allocator>::destroyRange(iterator from, iterator to)
{
    /* The operator delete[] wouldn't work appropriately as we
     * used the placement new operator and constructed each element
     * at the time of the insertion. */
    for( ; from != to; ++from)
        std::allocator_traits<Allocator>::destroy(allocator, from);
}


template<class T, class Allocator>
void Vector<T, Allocator>::destroyPointer(iterator ptr)
{
    /* The allocated space will not be used anymore.
     * We shall release the resource for further usage. */
    std::allocator_traits<Allocator>::deallocate(allocator, ptr, sz);
}




#endif //STL_IMPLEMENTATIONS_VECTOR_H
