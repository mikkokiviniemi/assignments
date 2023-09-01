#include "source/utils.h"
#include <iostream>
#include <vector>

/*
Exercise 1
Use iterator-based for loop to go through a string and print individual characters. 
What happens when there's a character outside of ASCII charset?  (try with e.g. emoji, åäö, etc.)
Also print out the character as integers (to see the value of bytes beneath)
*/
void ex1(std::string input) {
    for (auto it = input.begin(); it != input.end(); ++it) {
        std::cout << "Character: " << *it << "\n";
        std::cout << "Integer value: " << static_cast<int>(*it) << "\n\n";
    }
}
/*
Exercise 2
Most of the time we are dealing with unicode (more specifically UTF-8) strings.
It is the most common way to encode text, and almost everything except Windows uses it.

Launch up our trusted reference again read through the Iterator requirements, we are going to implement our own.
Also familiarise yourself a bit with UTF8-encoding.
Wikipedia is enough for us this time around unless you want to dive deeper yourself.
*/
template <typename T>
class Iterator {
public:
    Iterator(T::pointer ptr) : pointer(ptr) {}
    Iterator(T::iterator it) : pointer(&(*it)) {}

    Iterator& operator++() {
        ++pointer;
        return *this;
    }

    T::reference operator*() const {
        return *pointer;
    }

    bool operator!=(const Iterator& other) const {
        return pointer != other.pointer;
    }

private:
    T::pointer pointer;
};


/*
Exercise 3
So, what we want is a way to traverse individual unicode codepoints of an std::string 
(so we get ä, ö, å, 🍍 etc., as one codepoint).
Create a type that wraps a pointer of type std::string::pointer.
This will be our starting point of our iterator.  
Then, at first, implement a simple increment and dereference operators and conversion constructors from std::string::iterator.

Try to iterate through elements of std::string with your own iterator, 
and verify that the functionality at this point is equivalent to the std::string::iterator.
*/
class string_pointer_wrap {
    public:
        string_pointer_wrap(std::string::pointer ptr) : pointer(ptr) {}
        string_pointer_wrap(std::string::iterator it) : pointer(&(*it)) {}

        string_pointer_wrap& operator++() {
            ++pointer;
            return *this;
        }
        char operator*() const {
            return *pointer;
        }
        bool operator!=(const string_pointer_wrap& other) const {
            return pointer != other.pointer;
        }
    private:
        std::string::pointer pointer;
};



/*
Exercise 4
We can use char32_t as our unicode codepoint type (that is what is was designed for).  
Make sure dereferencing our iterator uses that type.

Then reimplement the increment operator so incrementing it moves to the next unicode codepoint instead of next byte.
(Use wikipedia and google to your advantage here, it's fine if you can find a ready-made implementation for checking unicode length etc., 
and use that as a helper.  The wikipedia article is enough to know all there needs to be, but it might be useful to search other sources as well.)
*/
class string_pointer_wrap2 {
    public:
        string_pointer_wrap2(std::string::pointer ptr) : pointer(ptr) {}
        string_pointer_wrap2(std::string::iterator it) : pointer(&(*it)) {}

        string_pointer_wrap2& operator++() {
            if (*pointer != '\0') {
                char32_t codepoint = *pointer;
                if ((codepoint & 0xC0) == 0xC0) {
                    if ((codepoint & 0xE0) == 0xC0) {
                        ++pointer;
                    } else if ((codepoint & 0xF0) == 0xE0) {
                        pointer += 2;
                    } else if ((codepoint & 0xF8) == 0xF0) {
                        pointer+= 3;
                    }
                }
                ++pointer;
            }
            return *this;
        }
        char32_t operator*() const {
            char32_t codepoint = *pointer;
            if ((codepoint & 0xC0) == 0xC0) {
                if ((codepoint & 0xE0) == 0xC0) {
                    codepoint = ((codepoint & 0x1F) << 6) | (*(pointer + 1) & 0x3F);
                } else if ((codepoint & 0xF0) == 0xE0) {
                    codepoint = ((codepoint & 0x0F) << 12) | ((*(pointer + 1) & 0x3F) << 6) | (*(pointer + 2) & 0x3F);
                } else if ((codepoint & 0xF8) == 0xF0) {
                    codepoint = ((codepoint & 0x07) << 18) | ((*(pointer + 1) & 0x3F) << 12) | ((*(pointer + 2) & 0x3F) << 6) | (*(pointer + 3) & 0x3F);
                }
            }
            return codepoint;
        }
        bool operator!=(const string_pointer_wrap2& other) const {
            return pointer != other.pointer;
        }
    private:
        std::string::pointer pointer;
};
/*
Exercise 5
Reimplement the dereferencing operator so it reads the entire codepoint, and returns its value.
*/

/*
(Optional, but recommended) Exercise 6
Write unit tests for your iterator.
*//*
(Optional) Exercise 7
Write an adapter class that wraps std::string (storing a reference to it), and rewrite its begin(), end() and size()
 to use your own iterator instead of the default one that comes with std::string

If you got this far, brilliantly done!  Writing iterators + adaptors like this can be used to implement a lot of useful stuff.  And some nice stuff like functionality similar to python's enumerate in ranged-for loops.  It's extremely useful, but a bit more rarely used technique.
*/

int main(int argc, char const *argv[])
{
    std::string test = "äöå🍍";
    ex1(test);
    //EX2
    for (Iterator<std::string> it = test.begin(); it != test.end();++it) {
        std::cout << *it << " ";
    }
    //EX3
    for (string_pointer_wrap it = test.begin(); it != test.end();++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n" << "Ex4\n";
    //EX4 
    for (string_pointer_wrap2 it = test.begin(); it != test.end();++it) {
        std::cout << *it << " ";
    }
    return 0;
}

