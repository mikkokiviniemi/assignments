#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>

//Calculates the sum of the list
int totalSum (std::vector<int>& list){
    int sum = 0;
    for (int i : list) {
        sum += i;
    }
    return sum;
}

//Calculates the average of the list
float average (std::vector<int>& list) {
    return totalSum(list) / (1.00f*list.size());
}

//Finds the minimum value in the list
int minimum (std::vector<int>& list) {
    return *std::min_element(list.begin(), list.end());
}

//Finds the maximum value in the list
int maximum (std::vector<int>& list) {
    return *std::max_element(list.begin(), list.end());
}

//Calculates the most frequent value in the list
int frequent (std::vector<int>& list) {
    std::unordered_map<int, int> countMap;

    //Fills the unordered_map list with a number and its frequency.
    for (int value : list) {
        countMap[value]++;
    }

    int mostFrequentValue = 0;
    int maxCount = 0;

    //Go through the unordered_map and find out the most frequent value from there.
    for (const auto& pair : countMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentValue = pair.first;
        }
    }
    return mostFrequentValue;
}

//The difference between the minimum and maximum of the list
int minmax(std::vector<int>& list) {
    return maximum(list) - minimum(list);
}

std::vector<int> manualInput(){
    std::vector<int> numbers;
    std::string input;

    std::cout << "Enter numbers (press enter to stop)" << std::endl;

    while (true) {
        std::cout << "Enter a number: ";
        std::getline(std::cin, input);
        if (input == "") {
            break;       
        }
        else {
            //Error handling if input not int
            try {
                numbers.push_back(std::stoi(input));
            }
            catch (const std::exception& e) {
                std::cerr << "Error! Wrong input" << std::endl;
            }
        }
    }
    return numbers;
}

//Reads file and fills vector
std::vector<int> readFileAndFillVector(const std::string& filename) {
    std::vector<int> numbers;
    std::ifstream inputFile(filename);

    //Reads file and fills vector numbers
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            //Error handling file
            try {
                int number = std::stoi(line);
                numbers.push_back(number);
            } catch (const std::exception& e) {
                std::cerr << "Error: Failed to convert line '" << line << "' to an integer.\n";
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Failed to open the file '" << filename << "' for reading.\n";
        numbers.push_back(0); //Fills with 0 to run the whole program.
    }
    return numbers;
}

//Prints things
void prints (std::vector<int>& numbers) {
    std::cout << "The sum of the integers in the list: " << totalSum(numbers) << std::endl;
    std::cout << "The average of the integers in the list: " << average(numbers) << std::endl;
    std::cout << "The minimum value in the list: " << minimum(numbers) << std::endl;
    std::cout << "The maximum value in the list: " << maximum(numbers) << std::endl;
    std::cout << "The most frequent value in the list: " << frequent(numbers) << std::endl;
    std::cout << "The difference between the minimum and maximum of the list: " << minmax(numbers) << std::endl;
}

int main() {
    std::vector<int> numbers;
    std::string input;
    
    //Input selection
    std::cout << "Manual input or text file input (M/F): ";
    std::getline(std::cin,input);
    if (input == "M") {
        numbers = manualInput();
    } else if (input == "F") {
        std::string file;
        std::cout << "File input: ";
        std::getline(std::cin,file);
        numbers = readFileAndFillVector(file);
    } else {
        std::cout << "Wrong input" << std::endl;
        return 0;
    }

    prints(numbers);

    return 0;
}