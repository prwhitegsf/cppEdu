#ifndef STL_IMPLEMENTATIONS_VECTOR_H
#define STL_IMPLEMENTATIONS_VECTOR_H

#include <memory>   // std::allocator
#include <cstddef>  // std::size_t, std::ptr_diff_t
#include <iterator> // std::distance
#include <stdexcept>




namespace my_vector {

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


        ~Vector() noexcept(std::is_nothrow_destructible_v<value_type>);  // Destructor

    private:
        size_type sz = 0;
        size_type cap =0;
        T* data = nullptr;
        Allocator allocator;


    };

} // my_vector

using namespace my_vector;

// Default Constructor

template<class T, class Allocator>
Vector<T, Allocator>::Vector() noexcept
        : sz(0), cap(0), data(nullptr)
{/*empty*/ }

// Constructor with allocator

template<class T, class Allocator>
Vector<T, Allocator>::Vector(const allocator_type& alloc)
        : sz(0), cap(0), data(nullptr), allocator(alloc)
{}



#endif //STL_IMPLEMENTATIONS_VECTOR_H
