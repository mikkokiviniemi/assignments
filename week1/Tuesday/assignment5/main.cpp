#include <iostream>
#include <vector>
#include <string>
/*
Exercise:  Book Management System

You have been tasked with developing a Book Management System for a library. The system should allow users to manage books in the library

Books in the library have the following information. Title, Author, ISBN, Year, Quantity. The information will be stored with proper data types.

There should be a function to display a book, add a book and remove a book, see if the book has been loaned or not.
*/

//Structure for books
struct Book{
    std::string title;
    std::string author;
    std::string isbn;
    int year;
    int quantity;
    bool loaned;

    //Function to display information of the book.
    void display () {
        std::cout << title << " by " << author << " " << year << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        if (loaned){
            std::cout << "Loaned" << std::endl;
        }
        else {
            std::cout << "Not loaned" << std::endl;
        }
    }
    bool if_loaned () {
        return loaned;
    }

    //Function to add a book.
    void add_book () {
        std::cout << "Add a book:" << std::endl;

        std::cout << "Title: ";
        std::getline(std::cin, title);

        std::cout << "Author: ";
        std::getline(std::cin, author);

        std::cout << "ISBN: ";
        std::getline(std::cin, isbn);

        std::string year_input;
        std::cout << "Year: ";
        std::getline(std::cin, year_input);
        year = std::stoi(year_input);

        std::string quantity_input;
        std::cout << "Quantity: ";
        std::getline(std::cin, quantity_input);
        quantity = std::stoi(quantity_input);

        loaned = false;

        std::cout << "Book added." << std::endl;
    }

};

int main()
{
    std::vector<Book> books;
    std::cout << "Commands: add, display, quit" << std::endl;
    while (true) {
        std::string input;
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "add") {
            Book new_book;
            new_book.add_book();
            books.push_back(new_book);

        }
        else if (input == "display") {
            for (auto book : books) {
                book.display();
                std::cout << std::endl;
            }
        }
        else if (input == "quit") {
            return 0;
        }
        else {
            std::cout << "Wrong input!" << std::endl;
        }
    }

    return 0;
}
