#include <iostream>

float index(float height, float weight){

    float bmi;

    bmi = weight/(height*height);


    return bmi;
}

int main()
{
    float height,weight,bmi;

    std::cout << "Enter your height (m): ";
    std::cin >> height;

    std::cout << "Enter your weight (kg): ";
    std::cin >> weight;

    bmi = index(height,weight);

    std::cout << "Your BMI is: " << bmi << std::endl;

    if (bmi < 18.5) {
        std::cout << "Underweight";
    } else if (bmi < 25) {
        std::cout << "Normal weight";
    } else if (bmi < 30) {
        std::cout << "Overweight";
    } else {
        std::cout << "Obese";
    }
    std::cout << std::endl;

    return 0;
}
