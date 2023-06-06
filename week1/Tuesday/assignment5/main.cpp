#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
Exercise:  Book Management System

You have been tasked with developing a Book Management System for a library. The system should allow users to manage books in the library

Books in the library have the following information. Title, Author, ISBN, Year, Quantity. The information will be stored with proper data types.

There should be a function to display a book, add a book and remove a book, see if the book has been loaned or not.
*/

// Structure for books
struct Book
{
    std::string title;
    std::string author;
    std::string isbn;
    int year;
    int quantity;
    bool loaned;

    void display() {
        std::cout << std::endl;
            std::cout << title << " by " << author << " " << year << std::endl;
            std::cout << "ISBN: " << isbn << std::endl;
            std::cout << "Quantity: " << quantity << std::endl;
            if (loaned)
            {
                std::cout << "Loaned" << std::endl;
            }
            else
            {
                std::cout << "Not loaned" << std::endl;
            }
    }

    // Function to add a book.
    void add_book()
    {
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

//Finds book and prints info.
void find_book(std::vector<Book>& books, const std::string& input)
{
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->title == input) {
            std::cout << std::endl;
            std::cout << it->title << " by " << it->author << " " << it->year << std::endl;
            std::cout << "ISBN: " << it->isbn << std::endl;
            std::cout << "Quantity: " << it->quantity << std::endl;
            if (it->loaned)
            {
                std::cout << "Loaned" << std::endl;
            }
            else
            {
                std::cout << "Not loaned" << std::endl;
            }
        }
    }
    std::cout << "Book not found" << std::endl;
};

//Loans book (book.loaned will be true)
void loan_book(std::vector<Book>& books, const std::string& input)
{
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->title == input && !it->loaned) {
            it->loaned = true;
            std::cout << "Book Loaned" <<std::endl;
            return;
        }
        else if (it->title == input && it->loaned) {
            std::cout << "Book already loaned" <<std::endl;
            return;
        }
    }
    std::cout << "Book not found" << std::endl;
}

// Removes book.
void remove_book(std::vector<Book>& books, const std::string& input) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->title == input) {
            books.erase(it);
            std::cout << "Book removed" << std::endl;
            return;
        }
    }
    std::cout << "Book not found" << std::endl;
}

int main()
{
    std::vector<Book> books;
    std::cout << "Commands: add, remove, display, find, loan and quit" << std::endl;
    while (true)
    {
        std::string input;
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "add")
        {
            Book new_book;
            new_book.add_book();
            books.push_back(new_book);
        }
        if (input == "remove")
        {
            std::string book;
            std::cout << "Enter book: ";
            std::getline(std::cin,book);
            remove_book(books,book);
        }
        else if (input == "display")
        {

            for(auto book: books){
                book.display();
            }
            std::cout << std::endl;

        }
        else if (input == "find")
        {
            std::string book;
            std::cout << "Enter book: ";
            std::getline(std::cin,book);
            find_book(books,book);
        }
        else if (input == "loan")
        {   
            std::string book;
            std::cout << "Enter book: ";
            std::getline(std::cin,book);
            loan_book(books,book);
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

    return 0;
}
