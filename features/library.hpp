#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <iostream>
#include <vector>
#include <string>
#include "book.hpp"
#include <fstream> // to read/write a file
#include <sstream> // to read line by line
#include <algorithm>
#include <cctype>
#include <cstring>
//#include <bits/stdc++.h>
using namespace std;

// hpp stands for header++ - used to put a just a class inside it. only contains class/template
//.cpp also works

class Library{
    public:
        void load_from_txt(const string& filename, vector<Book>& library){ // used to take data from books.txt to library vector
            // take input from book.txt, split it (w/commas)
            ifstream in(filename); // kind of opening the file or telling the program tht this is the file going to be read
            // ifstream is used to read from the file
            //offstream is to write in a file
            // in order to use the above, u have to use fstream library
            string line;
            while(getline(in,line)){
                // getline() can be used to take input from a file or user(in or cin)
                stringstream ss(line);
                
                string bid, title, author, category, status;
                getline(ss, bid, ',');
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, category, ',');
                getline(ss, status, ',');
                int id = stoi(bid); //converts bid string variable to integer and stores in an updated variable
                Book newBook = Book(id, title, author, category, status); // Create Book object
                library.push_back(newBook);
                // cout << "ID: " << bid << " | "
                // << "Title: " << title << " | "
                // << "Author: " << author << " | "
                // << "Category: " << category << " | "
                // << "Status: " << status << endl;



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

        string toLower(const string& str) {
            string lower = str;
            for (char& c : lower) {
                c = tolower(c);
            }
            return lower;
        }

        void search_book(vector<Book>& library, string search_title){
            search_title = toLower(search_title);
            bool found = false;
            for (Book &book : library){ // linear search
                //string lower_title = tolower(book.get_title());
                string title = book.get_title();
                string lower_title = toLower(title);
                //string lower_title = transform(title.begin(), title.end(), title.begin(), tolower );
                if (lower_title == search_title){
                    book.display();
                    found = true;
                    break;
                }
            }
            if (found == false){
                cout << "Book not found in library!" << endl;
            }
        }
        
        void remove_book(vector<Book>& library, string book_name){
            //can we not use the find/search funtion here?
            for (Book &book : library){
                //string lower_title = tolower(book.get_title());

                string title = book.get_title(); // the original title name
                string lower_title = toLower(title); // lowercase version of title

                toLower(book_name); // lowercase version of user input book name

                int bid = book.get_bid() - 1; // accessing book using index
                //string lower_title = transform(title.begin(), title.end(), title.begin(), tolower );

                if (lower_title == book_name){
                    library.erase(library.begin() + bid);
                    update_id(library , bid);
                    break;
                }
            }
        }

        void update_id(vector<Book>& library, int book_bid){
            if (book_bid != library.size() - 1){
                for (int i = book_bid; i < library.size(); i++){
                    Book &book = library[i];
                    book.set_bid(book.get_bid() - 1);
                    cout << book.get_bid() <<  endl;
                }
            }
        }

        vector<Book> merge(vector<Book>& library , int left, int mid, int right, string choice){
            int n1 = (mid - left) + 1; //len of left array
            int n2 = right - mid; //len of right array

            vector<Book> L(n1);
            vector<Book> R(n2);
            for(int i = 0 ; i < n1; i++){
                L[i] = library[left+i];
            }
            for(int i = 0 ; i < n2; i++){
                R[i] = library[mid + i + 1];
            }

            int i = 0 , j = 0; // indexes used to do incrimentation
            // i is for left array, j is for right array, and k is for result array

            vector<Book> result; // array where the sorted boks will enter while in sorting loop

            while(i < n1 && j < n2){ // run until both left and right arrays have elements 
                if (choice == "title"){
                    if (L[i].get_title() < R[j].get_title()){ // compare with value comes first alphabetically, iTH value of L array or jTH value of R array
                        result.push_back(L[i]); //push back the smaller value(alphabetically) into the result array
                        i++;
                    }
                    else{
                        result.push_back(R[j]);
                        j++;
                    }
                }

                else if(choice == "author"){
                    if (L[i].get_author() < R[j].get_author()){
                        result.push_back(L[i]);
                        i++;
                    }
                    else{
                        result.push_back(R[j]);
                        j++;
                    }
                }
            }
            while(i < n1){
                result.push_back(L[i]);
                i++;
            }
            while(j < n2){
                result.push_back(R[j]);
                j++;
            }
            return result;
        }

        vector<Book> merge_sort(vector<Book>& library , int left, int right, string choice){ // left & right are indexes
            if (left < right){
                int mid = (left + right)/2;
                merge_sort(library, left, mid , choice);
                merge_sort(library, mid + 1, right, choice);
                vector<Book> result = merge(library, left, mid, right , choice);
                return result;
            }

            return library;
        }

        
        void sort_library(vector<Book>& library , string choice){
        //     if(choice == "title"){
        //         sort(library.begin() , library.end() , [](Book a , Book b){ //comparater funtion
        //             return a.get_title() < b.get_title();
        //         }); //why is there a semi colon here?

        //     }
        //     else if(choice == "author"){
        //         sort(library.begin() , library.end() , [](Book a , Book b){ //comparater funtion
        //             return a.get_author() < b.get_author();
        //         });


        //     }
        //     else{
        //         cout << "Invalid choice!" << endl;
        //     }
        //     list_library(library);
        // } cmmd + / to comment

            if (choice == "title" || choice == "author"){
                vector<Book> result = merge_sort(library, 0,library.size()-1 , choice);
                list_library(result);
            }
            else{
                    cout << "Invalid choice!" << endl;
            }
        }

};

#endif