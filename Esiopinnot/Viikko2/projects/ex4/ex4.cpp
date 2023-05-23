#include <iostream>
#include <cmath>

const float PI = 3.14159;

int main() {
    float radius;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    float area = PI * pow(radius, 2);
    float circumference = 2 * PI * radius;

    std::cout << "Area of the circle: " << area << std::endl;
    std::cout << "Circumference of the circle: " << circumference << std::endl;

    return 0;
}
