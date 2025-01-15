#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib> 

using namespace std;

int  get_book_number();
void store_book_num(int num);
void add(int num);
void see();
void delete_book(int book_num);


int main(){

    int book_number, choice;
    //system("CLS"); // clear screen for windows
    cout << "\033[2J\033[1;1H"; //clear the screen for cross-platform solution

    cout << "To add a book in book list         Enter 1\n";       
    cout << "To see book list                   Enter 2\n";       
    cout << "To delete a book from book list    Enter 3\n";       
    cout << "To Exit                            Enter 0\n\n";       
    
    while(1){  
        cout << "Enter Your Choice : ";
        cin >> choice ;
        
        switch (choice){
            case 0:
                exit(0);
                break;

            case 1:
                book_number = get_book_number();
                book_number += 1;
                add(book_number);
                store_book_num(book_number);
                break;
            
            case 2:
                see();
                break;
            
            case 3:
                int book_to_delete;
                cout << "Which Book You want to delete form the book List? : ";
                cin >> book_to_delete;
        
                cin.clear(); //if user gives unexpected input then then this two line will clear 
                fflush(stdin); // and slove that problem

                delete_book(book_to_delete);
                store_book_num(get_book_number() - 1);
                break;
        }
    }
    return 0;
}


int get_book_number(){
    ifstream file("book_number.txt");
    int book_num = 0;
    if(file.is_open()){
        file >> book_num; //get last book number from the file
        file.close();
    }
    return book_num;
}


void store_book_num(int num){
    ofstream file("book_number.txt"); 
    if(file.is_open()){
        file << num;    //save the updated book number;
        file.close();
    }
}


void add(int num){
    string book_name, author, type;
    cout << " New Book Title   : ";
    cin.ignore();
    getline(cin , book_name);
    
    cout << " New Book Author  : ";
    getline(cin , author);

    cout << " New Book Type    : ";
    getline(cin , type);

    ofstream file("books_info.txt", ios::app);
    
    if(file.is_open()){
        file << num << ',' << book_name << ',' << author << ',' << type << endl;
        file.close();
        // Confirmation message
        cout << " New Book is added\n\n";
    }else{
        cout << "\n Unable to add New book\n\n";
    }
}


void see(){
    ifstream file ("books_info.txt");
    if(file.is_open()){
        string info;
        cout << "*******************************BOOK LIST******************************\n";
        while(getline(file, info)){
            stringstream data(info);
            string num, title, author, type;

            getline(data, num, ',');
            getline(data, title, ',');
            getline(data, author, ',');
            getline(data, type, ',');
            
            cout << " Book " << num << '\n';
            cout << "    Book Title      : " << title << '\n';
            cout << "    Author          : " << author << '\n';
            cout << "    Book Type       : " << type << '\n' ;
        }
        cout << "**********************************************************************\n\n";
        file.close();
    }else{
        cout << "No Book information found" << endl;
    }
}


void delete_book(int book_num){
    ifstream file("books_info.txt");
    ofstream tm_file("temp.txt");
    bool found = false;

    if(file.is_open() && tm_file.is_open()){
        string get_info;
        
        while(getline(file, get_info)){
            stringstream data(get_info);
            string num, title, author, type;

            getline(data, num, ',');
            getline(data, title, ',');
            getline(data, author, ',');
            getline(data, type, ',');

            if(stoi(num) == book_num){
                found = true;
                cout << title << "  "
                     << author << "   "
                     << type << '\n'
                     << "This is Removed from the Book List\n\n";
            }else{
                tm_file << get_info << '\n';
            }
        }
        file.close();
        tm_file.close();

        remove("books_info.txt");
        rename("temp.txt", "books_info.txt");

        if(!found){
            cout << "Book " << book_num << " not found in the list.\n";

        }
    }else{
        cout << "Error: Unable to access the file.\n";
    }
}