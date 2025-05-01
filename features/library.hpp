#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <iostream>
#include <vector>
#include "book.hpp"
#include <fstream> // to read/write a file
#include <sstream> // to read line by line
using namespace std;

// hpp stands for header++ - used to put a just a class inside it. only contains class/template
//.cpp also works

class Library{
    public:
        void load_from_txt(const string& filename, vector<Book>& library){
            // take input from book.txt, split it (w/commas)
            ifstream in(filename); // kind of opening the file or telling the program tht this is the file going to be read
            string line;
            while(getline(in,line)){
                // getline() can be used to take input from a file or user(in or cin)


            }
        }
        void add_book(vector<Book>& library){ // & is used to keep changes that are done in a funtions even after the funtion is passed
            int bid;
            string title, author, category, status;
            //bid,title,author,category,status
            cout << "Enter BID:";// ???
            cin >> bid;
            cin.ignore(); // Clear input buffer

            cout << "Enter Title: \n";
            getline(cin,title); // or cin >> title; which both takes input

            /*
            The getline() function extracts characters from the input stream
            and appends it to the string object until the delimiting character is encountered.
            */
            //first take every input, make book class object with those inputs and then push_back it into the library vector
            // push on github and update when changes are made
            cout << "Enter Author: \n";
            getline(cin, author);

            cout << "Enter category: \n";
            getline(cin, category);

            cout << "Enter status: ";
            getline(cin, status);

            Book newBook = Book(bid, title, author, category, status); // Create Book object
            library.push_back(newBook);
            
        }
        void list_library(vector<Book>& library){
            // displays all the books in the library line by line
            // library vector has to first be stored with data in books.txt 
            for (Book book : library){
                book.display();
            }
        }
        void remove_book(vector<Book>& library){
            //can we not use the find/search funtion here?
        }

};

#endif