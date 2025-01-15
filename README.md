# Book Management System

This is a simple **Book Management System** program written in C++. It allows users to manage a list of books by performing operations such as adding, viewing, and deleting books.

## Features

1. **Add a Book**: Add a new book with its title, author, and type to the list.
2. **View Books**: Display all the books currently in the list with their details.
3. **Delete a Book**: Remove a specific book from the list using its book number.
4. **Persistent Storage**: Keeps track of books and their numbers using text files.

## Prerequisites

- C++ compiler (e.g., g++, clang++)
- Text files `books_info.txt` and `book_number.txt` are required for storing data. These will be created automatically if they do not exist.

## How It Works

1. **Book Numbering**:
   - Book numbers are stored in `book_number.txt`.
   - Each new book is assigned a unique number based on the last saved number.

2. **Adding a Book**:
   - User inputs book details (title, author, type).
   - Data is saved to `books_info.txt`.

3. **Viewing Books**:
   - All book details are read from `books_info.txt` and displayed in a formatted list.

4. **Deleting a Book**:
   - The program searches for the specified book number in `books_info.txt`.
   - If found, the book is removed, and the remaining data is saved in a temporary file (`temp.txt`), which is renamed to `books_info.txt`.

## How to Run

1. Clone or download the repository.
2. Compile the program using a C++ compiler:
   ```bash
   g++ -o book_management book_management.cpp
