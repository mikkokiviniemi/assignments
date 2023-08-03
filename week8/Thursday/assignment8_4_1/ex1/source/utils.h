#if !defined(UTILS)
#define UTILS

#include <iostream>

#include <iostream>
#include <array>

template <typename T, std::size_t array_size>
class heap_array {
    public:
        using value_type = T;
        using size_type = std::size_t;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;

        //Constructors

        //Default
        heap_array() {
            data = new T[array_size];
        }
        //Copy
        heap_array(const heap_array& other) {
            data = new T[array_size];
            std::copy(other.begin(), other.end(), this->begin());
        }
        //Move
        heap_array(heap_array&& other) noexcept {
            data = new T[array_size];
            std::move(other.begin(), other.end(), this->begin());
            other.data = nullptr;
        }
        //Destructor
        ~heap_array(){
            delete[] data;
        }

        //Assignment operators

        //Copy
        heap_array& operator=(const heap_array& other) {
            if (this != &other) {
                delete[] data;
                data = new T[other.size()];
                std::copy(other.begin(), other.end(), this->begin());
            }
            return *this;
        }
        //Move
        heap_array& operator=(heap_array&& other) noexcept {
            if (this != &other) {
                delete[] data;
                data = nullptr;
                std::swap(this->data,other.data);
            }
            return *this;
        }

        //Accessor
        reference operator[](size_type index) {
            return data[index];
        }
        //Accessor
        const_reference operator[](size_type index) const {
            return data[index];
        }

        //Iterators
        iterator begin() {
            return data;
        }
        const_iterator begin() const {
            return data;
        }
        iterator end() {
            return data + array_size;
        }
        const_iterator end() const {
            return data + array_size;
        }

        //Swap
        void swap(heap_array& other) {
            for (std::size_t i = 0; i < array_size; ++i) {
                std::swap(data[i], other.data[i]);
            }
        }

        //Comparisons

        bool operator==(const heap_array& other) const {
            return std::equal(this->begin(), this->end(), other.begin());
        }
        bool operator!=(const heap_array& other) const {
            return !(std::equal(this->begin(), this->end(), other.begin()));
        }
        void clear() {
            std::fill(this->begin(), this->end(), T{});
        }
        bool empty() const {
            return this->data == nullptr;
        }

        //Size
        size_type size() const {
            return array_size;
        }
        //Max size
        size_type max_size() const {
            return array_size;
        }

    private:
        T* data;

};

#endif // UINT
