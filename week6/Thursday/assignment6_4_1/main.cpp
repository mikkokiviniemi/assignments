/*
Exercise 1

Create a namespace and a type in the global namespace.  Create a function in the
namespace and a static member function for the type.  Try using them from the global
namespace.

Exercise 2

Create a 3D vector type (e.g. a type with x, y and z values) in your own namespace.
Then overload the << operator so you can use that type directly with std::cout
Think about in what namespace the overload should be located (try it out, it might be a bit surprising).

Exercise 3

Overload +, -, += and -= operators for your vector type to handle vector addition
and substraction, pay attention to const-ness of your variables/parameters.
*/

#include <iostream>
#include <vector>

//EX 1
namespace global
{
namespace ex1
{
    void print() {
        std::cout << "Ex1 namespace \n";
    }
}
class ex1_type{
    public:
        static void print_value() {
            std::cout << "Ex1 type \n";
        }
    private:
        std::string value = "Ex1 type";
};
}
//EX 2
class vector_3D {
    public:
        int x;
        int y;
        int z;

        //EX 3 
        vector_3D operator+(const vector_3D& other) const{
            vector_3D sum = {x + other.x, y + other.y, z + other.z};
            return sum;
        }
        vector_3D operator-(const vector_3D& other) const{
            vector_3D substraction = {x - other.x, y - other.y, z - other.z};
            return substraction;
        }
        vector_3D operator+=(const vector_3D& other) {
            x = x + other.x;
            y = y + other.y;
            z = z + other.z;
            return *this;
        }
        vector_3D operator-=(const vector_3D& other) {
            x = x - other.x;
            y = y - other.y;
            z = z - other.z;
            return *this;
        }
    private:

};
std::ostream& operator<<(std::ostream& os, const vector_3D vec){
    os << "[" << vec.x << "," << vec.y << "," << vec.z << "]";
    return os;
}

int main()
{
    //EX1
    global::ex1::print();
    global::ex1_type::print_value();

    //EX2 + EX3
    {
    vector_3D test_vector = {1,2,3};
    vector_3D test_vector2 = {5,2,4};

    std::cout << test_vector << "\n";
    std::cout << test_vector2 << "\n";

    test_vector2 = test_vector2 + test_vector;
    std::cout << test_vector2 << "\n";
    }
    std::cout << "-------------------\n";
    {
    vector_3D test_vector = {1,2,3};
    vector_3D test_vector2 = {5,2,4};

    std::cout << test_vector << "\n";
    std::cout << test_vector2 << "\n";

    test_vector2 -= test_vector;
    std::cout << test_vector2 << "\n";
    }

    return 0;
}
