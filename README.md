# Library Management System

A console-based Library Management System built using the C programming language. This project is a simple implementation of a library management system that allows managing books, members, and transactions through a menu-driven interface.

## Features

### Book Management
- **Add Books**: Enter details such as ISBN, Title, Author, Genre, and Quantity.
- **Update Books**: Update details of an existing book.
- **Delete Books**: Remove a book from the library database.
- **Display Books**: View the list of all books with their details.

### Member Management
- **Add Members**: Enter new member information including ID, Name, Address, and Phone Number.
- **Update Members**: Update details of an existing member.
- **Delete Members**: Remove a member from the library database.
- **Display Members**: View the list of all members and their details.

### Transaction Management
- **Issue Books**: Issue a book to a member by entering the member's ID and book ISBN.
- **Return Books**: Return a previously issued book using its transaction ID.
- **Display Transaction History**: View all past transactions including issued and returned books.

## Menu Navigation

The application starts with a main menu with three major options:
1. **Book Management:**
- Choose from adding, updating, deleting, or displaying book details.
2. **Member Management:**
- Choose from adding, updating, deleting, or displaying member details.
3. **Transaction Management:**
- Choose to issue a book, return a book, or display the transaction history.
4. **Exit**: Exit the application.
<br>
For each section, follow the on-screen instructions to enter information and navigate through the menu options.

## Data Structures

The following structures are used in the program:

- `struct book`: Stores book information such as ISBN, title, author, genre, and quantity.
- `struct members`: Stores member information such as ID, name, address, and phone number.
- `struct transaction`: Stores transaction details like transaction ID, member ID, book ISBN, issue date, and return date.


## Function Overview

### Book Functions
- `add_book()`: Adds book details to the system.
- `update_book()`: Updates an existing book's information.
- `deleteBook()`: Deletes a book from the system.
- `display_book()`: Displays all books in the library.

### Member Functions
- `add_memb()`: Adds member details to the system.
- `update_memb()`: Updates an existing member's information.
- `dlt_memb()`: Deletes a member from the system.
- `display_memb()`: Displays all members in the library.

### Transaction Functions
- `issue_book()`: Issues a book to a member.
- `return_book()`: Returns a previously issued book.
- `display_transaction_history()`: Displays the history of all transactions.

## Enhancements
Possible improvements and features to be added in the future:

- Implement search functionality for books and members.
- Implement fine calculation for overdue books.
- Enhance user interface with more robust input validation.
- Add file handling for persistent data storage.

