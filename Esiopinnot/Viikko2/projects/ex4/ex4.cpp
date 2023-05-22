#include <iostream>
#include <cmath>

const double PI = 3.14159;

int main() {
    double radius;

    // Prompt the user to enter the radius of the circle
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Calculate the area and circumference
    double area = PI * pow(radius, 2);
    double circumference = 2 * PI * radius;

    // Display the results
    std::cout << "Area of the circle: " << area << std::endl;
    std::cout << "Circumference of the circle: " << circumference << std::endl;

    return 0;
}
