#if !defined(UTILS)
#define UTILS

#include <iostream>
#include <type_traits>

//EX1
template <typename T>
void exercise1(T&& arg) {
    if constexpr (std::is_lvalue_reference_v<T>) {
        std::cout << "lvalue reference\n";
    } else {
        std::cout << "rvalue reference\n";
    }
}
//EX2
template <bool console_call = true>
class EX2 {
    public:
        EX2(){
            if (console_call) {
                std::cout << "Default constructor called\n";
            }
            ++default_constructor;
        }
        EX2(EX2& other){
            if (console_call) {
                std::cout << "Copy constructor called\n";
            }
            ++copy_constructor;
        }
        EX2(EX2&& other){
            if (console_call) {
                std::cout << "Move constructor called\n";
            }
            ++move_constructor;
        }
        ~EX2(){
            if (console_call) {
                std::cout << "Destructor called\n";
            }
            ++destructor;
        }

        int default_constructor_count () {
            return default_constructor;
        }
        int copy_constructor_count () {
            return copy_constructor;
        }
        int move_constructor_count () {
            return move_constructor;
        }
        int destructor_count () {
            return destructor;
        }
        void all_counts() {
            std::cout << "default_constructor " << default_constructor << "\n";
            std::cout << "copy_constructor " << copy_constructor << "\n";
            std::cout << "move_constructor " << move_constructor << "\n";
            std::cout << "destructor " << destructor << "\n";
        }

    private:
        static int default_constructor;
        static int copy_constructor;
        static int move_constructor;
        static int destructor;

};

template <bool console_call>
int EX2<console_call>::default_constructor = 0;

template <bool console_call>
int EX2<console_call>::copy_constructor = 0;

template <bool console_call>
int EX2<console_call>::move_constructor = 0;

template <bool console_call>
int EX2<console_call>::destructor = 0;


#endif // UINT
