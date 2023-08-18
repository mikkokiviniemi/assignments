#include "source/utils.h"
#include <iostream>
#include <vector>
#include <array>

/*
Exercise 1

Sometimes it's possible to bypass some of limitations (e.g. if only dynamic memory allocation is forbidden) by instead using statically allocated memory.

Look at Allocator requirements.

Statically allocate a block of memory (e.g. by creating std::array, or uint8_t[SIZE] block).
Create an allocator that uses the placement new to construct objects to the memory from the static block, and manually call the destructor when deconstructing.
Try to use your allocator with std::vector.

If you can't finish this task, just post how far you got.  It's not as easy as it might first seem.


Exercise 2 (Optional)

Create unit tests for your allocator
*/

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

template <typename T, std::size_t SIZE>
class assignment {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    assignment() = default;

    
    pointer allocate(size_type n) {
        if (n > SIZE) {
            throw std::bad_alloc(); 
        }
        return reinterpret_cast<pointer>(memory_pool);
    }

    void deallocate(pointer p, size_type n) {

    }

    template <typename... Args>
    void construct(pointer p, Args&&... args) {
        new (p) T(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }

private:
    static uint8_t memory_pool[SIZE];
};

template <typename T, std::size_t SIZE>
uint8_t assignment<T, SIZE>::memory_pool[SIZE];

int main() {
    using MyAllocator = assignment<int, 10>;

    // Using std::vector with custom allocator
    std::vector<int, MyAllocator> vec;
    vec.push_back(1);
    vec.push_back(2);

    return 0;
}
