#include "utils.h"

//Getting information about input_file. Options -l -w -c -s or empty.
int file_manager (std::string input_file, std::string option) {
    std::ifstream file(input_file);

    //Feature line count
    if (file.is_open() && option == "-l") {
        std::string line;
        int count = 0;
        while (std::getline(file, line)) {
            count++;
        }
        std::cout << "Lines: " << count << "\n";
        file.close();
        return 0;
    }
    //Feature word count
    if (file.is_open() && option == "-w") {
        std::string line;
        int count = 0;
        while (file >> line) {
            count++;
        }
        std::cout <<  "Words: " << count << "\n";
        file.close();
        return 0;
    }
    //Feature character count
    if (file.is_open() && option == "-c") {
        std::string line;
        int count = 0;
        while (file >> line) {
            count = count + line.size() + 1; //+1 adds spaces
        }
        --count;//Minus last space
        std::cout << "Characters: " << count << "\n";
        file.close();
        return 0;
    }
    //Feature file size
    if (file.is_open() && option == "-s") {
        std::filesystem::path file_path = input_file;
        std::cout << "File size: " << std::filesystem::file_size(file_path) << " bytes" << std::endl;
        return 0;
    }
    //If no features
    if (file.is_open()){
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    } 
    else {
        std::cout << "Unable to open the file.\n";
    }
}