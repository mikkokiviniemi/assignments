#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <exception>
#include <vector>
#include <fstream>

int add(int a, int b);

int substract(int a, int b);

int multiple(int a, int b);

int divide(int a, int b);

std::string reverse_string(std::string word);

std::string upper_case_string(std::string word);

std::string lower_case_string(std::string word);

bool is_palindrome(std::string word);

//Bank program
struct Bank_account
{

    std::string name;
    std::string address;
    std::string telephone;
    std::string customer_number;
    float balance;

    void print_account () {
        std::cout << "Account " << customer_number << ":" << std::endl;
        std::cout << "Name: "<< name << std::endl;
        std::cout << "Address: "<< address << std::endl;
        std::cout << "Phone: "<< telephone << std::endl;
        std::cout << "Balance: " << balance << "€." << std::endl;
    }
    void deposit_money (float amount) {
        balance += amount;
    }
    void withdraw_money (float amount) {
        if(balance < amount){
            std::cout << "Not enough money." << std::endl;
            return;
        }
        balance -= amount;
    }
    void get_balance () {
        std::cout << "Balance: " << balance << "€." << std::endl;
    }

};

Bank_account *find_account(std::vector<Bank_account> &accounts, const std::string &input);

Bank_account add_account(std::vector<Bank_account> &accounts);

void fill_file(std::vector<Bank_account> &accounts);

#endif

