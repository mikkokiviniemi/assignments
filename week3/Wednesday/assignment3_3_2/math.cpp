/*
Exericse 1.

Test basic math functions.First write your unit tests and then create simple math functions 
like addition, subtraction, multiplication and division. 
Try and think about meaningful unit tests. 
Your program does not need a user interface now that you are using unit tests to check for functionality.
Remember error handling.

Exercise 2.

Write unit tests for a string utility program. 
Write unit tests that check if your program can correctly handle 
reversing a string, a method to convert a string to uppercase, 
a method to convert a string to lowercase and a method to check if a string is a palindrome.

Exercise 3.

Add unit tests to your banking program that you had built earlier. Try and get as high test coverage as possible.
*/

#include "math.h"

int add(int a, int b) {
    return a + b;
}
int substract(int a,int b) {
    return a - b;
}
int multiple(int a, int b) {
    return a*b;
}
int divide (int a, int b) {
    if(b==0) {
        throw std::logic_error("Cant divide with 0");
    }
    return a/b;
}

std::string reverse_string(std::string word) {
    std::string reversed;
    for (int i = word.length() - 1; i >= 0; --i) {
        reversed += word[i];
    }
    return reversed;
}

std::string upper_case_string(std::string word) {
    std::string upper;
    for (auto& c : word) {
        upper += toupper(c);
    }
    return upper;
}

std::string lower_case_string(std::string word) {
    std::string lower;
    for (auto& c : word) {
        lower += tolower(c);
    }
    return lower;
}

bool is_palindrome (std::string word) {
    for (int i = 0; i < word.size(); i++ ) {
        if(tolower(word[i]) != tolower(word[word.size()-i-1])) {
            return false;
        }
    }
    return true;
}


//Bank program

//Function to find account from vector<Bank_account> with customer_number.
Bank_account* find_account(std::vector<Bank_account>& accounts, const std::string& input){
    for (auto& account : accounts)
    {
        if (account.customer_number == input)
        {
            return &account;
        }
    }
    return nullptr;
}
//Function to add account. Also checks if customer_number is unique.
Bank_account add_account(std::vector<Bank_account>& accounts){

        std::string name;
        std::string address;
        std::string telephone;
        std::string customer_number;
        float balance = 0;

        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Address: ";
        std::getline(std::cin, address);

        std::cout << "Telephone: ";
        std::getline(std::cin, telephone);

        std::cout << "Customer number: ";
        std::getline(std::cin, customer_number);

        while(find_account(accounts,customer_number) != nullptr){
            std::cout << "Customer number already used." << std::endl;
            std::cout << "Customer number: ";
            std::getline(std::cin, customer_number);
        }

        Bank_account new_account;

        new_account={name,address,telephone,customer_number,balance};

        return new_account;



}
//Fills accounts.txt file with vector<Bank_accounts>
void fill_file (std::vector<Bank_account>& accounts) {
    std::ofstream output_file("accounts.txt");
    if(!output_file){
        std::cout << "Error opening the file." << std::endl;
    }

    for(const auto& account: accounts) {
        output_file << "[" << account.customer_number 
        << "]: Name: " << account.name 
        << ", Address: " << account.address 
        << ", Telephone: "<< account.telephone 
        << ", Balance: " << account.balance << "€" << std::endl;
    }

    output_file.close();
}