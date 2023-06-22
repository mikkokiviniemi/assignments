/*
Banking application
"add": To add a new bank account and enter the necessary information for the account.
"deposit": To deposit money into an existing bank account.
"withdraw": To withdraw money from an existing bank account.
"balance": To check the balance of an existing bank account.
"info": To view detailed information about an existing bank account.
"file": To fill a file with the contents of the bank account database.
"quit": To exit the program.
*/
#include <iostream>
#include <vector>
#include <fstream>


/*
Struct that contains information about account. 
Also have functions print_account(), deposit_money(amount), withdraw_money(amount)
and get_balance().
*/
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

/*Input menu for the program.
"add": To add a new bank account and enter the necessary information for the account.
"deposit": To deposit money into an existing bank account.
"withdraw": To withdraw money from an existing bank account.
"balance": To check the balance of an existing bank account.
"info": To view detailed information about an existing bank account.
"file": To fill a file with the contents of the bank account database.
"quit": To exit the program.
 Looks bad :D
 */
int menu (std::vector<Bank_account>& database){
    std::cout << "Commands: add, deposit, withdraw, balance, info, file and quit" << std::endl;
    while (true)
    {
        std::string input;
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "add")
        {
            Bank_account new_account = add_account(database);
            database.push_back(new_account);

        }
        else if (input == "file") {
            fill_file(database);
        }
        else if (input == "deposit")
        {
            std::string customer_number,amount;

            std::cout << "Enter account customer number: ";
            std::getline(std::cin,customer_number);

            Bank_account* account = find_account(database,customer_number);

            if(account == nullptr){
                std::cout << "Account not found" << std::endl;
                continue;
            }
            
            std::cout << "Enter amount: ";
            std::getline(std::cin,amount);

            float depo_money = std::stof(amount);
            account->deposit_money(depo_money);
        }
        else if (input == "balance")
        {
            std::string customer_number,amount;

            std::cout << "Enter account customer number: ";
            std::getline(std::cin,customer_number);

            Bank_account* account = find_account(database,customer_number);
            if(account == nullptr){
                std::cout << "Account not found" << std::endl;
                continue;
            }
            account->get_balance();
        }
        else if (input == "withdraw")
        {
            std::string customer_number,amount;

            std::cout << "Enter account customer number: ";
            std::getline(std::cin,customer_number);

            Bank_account* account = find_account(database,customer_number);

            if(account == nullptr){
                std::cout << "Account not found" << std::endl;
                continue;
            }
            
            std::cout << "Enter amount: ";
            std::getline(std::cin,amount);

            float wd_money = std::stof(amount);
            account->withdraw_money(wd_money);
        }
        else if (input == "info")
        {
            std::string customer_number;
            std::cout << "Enter account customer number: ";
            std::getline(std::cin,customer_number);

            Bank_account* account = find_account(database,customer_number);
            if(account == nullptr){
                std::cout << "Account not found" << std::endl;
                continue;
            }
            account->print_account();

        }
        else if (input == "quit")
        {
            return 0;
        }
        else
        {
            std::cout << "Wrong input!" << std::endl;
        }
    }
}

int main()
{
    
    std::vector<Bank_account> database;

    //Test account
    Bank_account test;
    test = {"Test","Testroad 1","1800-Test","test",100};
    database.push_back(test);


    menu(database);

    return 0;
}
