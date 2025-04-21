#include <iostream>
using namespace std;

class Book{
    private:
        string title;
        string author;
        string ISBN;
        string genre;
        int year;
    public:
        Book(){
        }
        Book(string title, string author, string ISBN, string genre, int year){
            title = title;
            author = author;
            ISBN = ISBN;
            genre = genre;
            year = year;
        }
        void display(){
            cout << title << author << ISBN << year << genre << endl;
            // cout << title << " by " << author << " (" << year << ") [ISBN: " << isbn << "] - Genre: " << genre << endl;
        }

};