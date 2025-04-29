
#include <iostream>
#include "features/book.cpp"
#include "features/library.cpp" //??
using namespace std;

// funtions in "features" file - 

int main(){
    vector<Book>library;
    Library l;
    //load_from_txt("data/books.txt" , library);
    // create a menu in a while loop with options
    /*
    example - if (choice == 1) {
        addBook(library);
    }
    */
   int choice;

    // menu displaying
    cout << "Library Mangaer Menu:\n";
    cout << "1. Add a book\n"; // \n can be used instead of the endln() funtion.
    cout << "2. Search a book\n";
    cout << "3. List a library\n";
    cout << "4. Remove a book\n";
    cout << "4. Exit\n";

    // choice user input
    cout << "Enter the number of the action you want to perform: ";
    cin >> choice;

    if (choice == 1){
        l.add_book(library);
        
    }
   

}

