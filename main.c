#include <stdio.h>
#include <string.h>

struct book {
    char isbn[20];
    char title[100];
    char author[50];
    char genre[50];
    int quantity;
};

struct members {
    char id[25];
    char name[50];
    char address[100];
    char phone_no[10];
};

struct transaction {
    int tr_id;
    char id[25];
    char isbn[20];
    char issue[10];
    char return_date[10];
};

int n, choice;
int b;
int m;
int t;
struct book books[100];
struct members memb[100];
struct transaction tran[100];

void welcome();
void menu();
void add_book(struct book books[], int b);
void update_book(struct book books[], int n);
void deleteBook(struct book *books, int *b);
void display_book(struct book books[], int b);
void add_memb(struct members memb[], int m);
void update_memb(struct members memb[], int n);
void dlt_memb(struct members *memb, int *m);
void display_memb(struct members memb[], int m);
void issue_book(struct transaction tran[], int *t, int *num_books);
void return_book(struct transaction tran[], int *t);
void display_transaction_history(struct transaction tran[], int t);

int main() {
    welcome();
    menu();
    return 0;
}

void welcome() {
    printf("\n\n\n------------------------------------\n");
    printf("Welcome to Library Management System\n");
    printf("------------------------------------\n");
}

void menu() {
    int numBooks = 0;
    printf("\nLibrary Management menu: \n");
    printf("1. Book Management\n");
    printf("2. Member Management\n");
    printf("3. Transaction Management\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &n);
    switch (n) {
        case 1: {
            printf("\n\nBook Management Menu: \n1. Add Book details\n2. Update Book details\n3. Delete Book details\n4. Display Book details\n5. Back to main menu\n\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    printf("\nEnter the number of books you want to add: ");
                    scanf("%d", &b);
                    add_book(books, b);
                    break;
                }
                case 2: {
                    int no_books = sizeof(books) / sizeof(books[0]);
                    update_book(books, no_books);
                    break;
                }
                case 3: {
                    deleteBook(books, &b);
                    break;
                }
                case 4: {
                    display_book(books, b);
                    break;
                }
                case 5: {
                    menu();
                    break;
                }
                default: {
                    printf("\nInvalid input! Please enter number between 1 and 5.\n\n");
                    menu();
                }
            }
            break;
        }
        case 2: {
            printf("\n\nMember Management Menu: \n");
            printf("1. Add member details\n2. Update member details\n3. Delete member details\n4. Display member details \n5. Back to main menu\n\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    printf("\nEnter the number of members you want to add: ");
                    scanf("%d", &m);
                    add_memb(memb, m);
                    break;
                }
                case 2: {
                    int no_memb = sizeof(memb) / sizeof(memb[0]);
                    update_memb(memb, no_memb);
                    break;
                }
                case 3: {
                    dlt_memb(memb, &m);
                    break;
                }
                case 4: {
                    display_memb(memb, m);
                    break;
                }
                case 5: {
                    menu();
                    break;
                }
                default: {
                    printf("\nInvalid input! Please enter number between 1 and 5.\n\n");
                    menu();
                }
            }
            break;
        }
        case 3: {
            // Transaction Management
            int choice;
            printf("\nTransaction Management Menu:\n");
            printf("1. Issue a book\n");
            printf("2. Return a book\n");
            printf("3. Display transaction history\n");
            printf("4. Back to main menu\n\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    issue_book(tran, &t, &b);
                    break;
                case 2:
                    return_book(tran, &t);
                    break;
                case 3:
                    display_transaction_history(tran, t);
                    break;
                case 4:
                    menu();
                    break;
                default:
                    printf("Invalid choice!\n");
                    menu();
                    break;
            }
            break;
        }
        case 4: {
            printf("\n\nExiting...\n\n");
            printf("Thank you for using Library Management system...\n\n");
            break;
        }
        default: {
            printf("\nInvalid input! Please enter number between 1 and 4.\n\n");
            menu();
        }
    }
}

void add_book(struct book books[], int b) {
    for (int i = 0; i < b; i++) {
        printf("\nEnter ISBN for book %d: ", i + 1);
        scanf("%s", books[i].isbn);
        printf("Enter title for book %d: ", i + 1);
        scanf(" %[^\n]s", books[i].title);
        printf("Enter Author for book %d: ", i + 1);
        scanf(" %[^\n]s", books[i].author);
        printf("Enter Genre for book %d: ", i + 1);
        scanf(" %[^\n]s", books[i].genre);
        printf("Enter quantity for book %d: ", i + 1);
        scanf("%d", &books[i].quantity);
    }
    printf("\nBook details added successfully.\n\n");
    menu();
}

void update_book(struct book books[], int n) {
    char searchisbn[20];
    int index = -1;
    printf("\nEnter ISBN of the book which you want to update: ");
    scanf("%s", searchisbn);
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].isbn, searchisbn) == 0) {
            index = i;
            break;
        }
    }
    if (index < 0) {
        printf("Book not found!\n");
        menu();
        return;
    }
    printf("\nBook Details\n\n");
    printf("Title: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Genre: %s\n", books[index].genre);
    printf("Quantity: %d\n", books[index].quantity);
    printf("\n\nSelect the field which you want to update:\n1. Title \n2. Author \n3. Genre \n4. Quantity \n5. Back to main menu\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            printf("\nEnter new title: ");
            scanf(" %[^\n]s", books[index].title);
            break;
        }
        case 2: {
            printf("\nEnter new author name: ");
            scanf(" %[^\n]s", books[index].author);
            break;
        }
        case 3: {
            printf("\nEnter new genre: ");
            scanf(" %[^\n]s", books[index].genre);
            break;
        }
        case 4: {
            printf("\nEnter new quantity: ");
            scanf("%d", &books[index].quantity);
            break;
        }
        case 5: {
            menu();
            return;
        }
    }
    printf("\nBook details updated successfully.\n\n");
    menu();
}


void deleteBook(struct book *books, int *b) {
    char ISBN[20];
    int flag = 0;
    printf("\nEnter ISBN of the book to delete: ");
    scanf("%s", ISBN);
    for (int i = 0; i < *b; i++) {
        if (strcmp(books[i].isbn, ISBN) == 0) {
            for (int j = i; j < *b - 1; j++) {
                books[j] = books[j + 1];
            }
            (*b)--;
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("\nBook not found!\n");
    } else {
        printf("Book details deleted successfully.\n");
    }
    menu();
}

void display_book(struct book books[], int b) {
    if (b == 0) {
        printf("\nNo books in the library!!\n");
    } else {
        printf("\nDisplaying Book Details:\n\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("%-20s %-30s %-20s %-20s %-10s\n", "ISBN", "Title", "Author", "Genre", "Quantity");
        printf("-----------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < b; i++) {
            printf("%-20s %-30s %-20s %-20s %-10d\n", books[i].isbn, books[i].title, books[i].author, books[i].genre, books[i].quantity);
        }
    }
    menu();
}

void add_memb(struct members memb[], int m) {
    for (int i = 0; i < m; i++) {
        printf("Enter member ID for member %d: ", i + 1);
        scanf("%s", memb[i].id);
        printf("Enter member name for member %d: ", i + 1);
        scanf(" %[^\n]s", memb[i].name);
        printf("Enter address for member %d: ", i + 1);
        scanf(" %[^\n]s", memb[i].address);
        printf("Enter phone number for member %d: ", i + 1);
        scanf("%s", memb[i].phone_no);
        printf("\n");
    }
    printf("\nMember details added successfully.\n\n");
    menu();
}

void update_memb(struct members memb[], int n) {
    char searchid[25];
    int index = -1;
    printf("Enter the member ID which you want to update: ");
    scanf("%s", searchid);
    for (int i = 0; i < n; i++) {
        if (strcmp(memb[i].id, searchid) == 0) {
            index = i;
            break;
        }
    }
    if (index < 0) {
        printf("\nMember not found!\n");
        menu();
        return;
    }
    printf("\nMember details \n\n");
    printf("Member ID: %s\n", memb[index].id);
    printf("Name: %s\n", memb[index].name);
    printf("Address: %s\n", memb[index].address);
    printf("Phone number: %s\n", memb[index].phone_no);
    printf("\n\nSelect the field which you want to update:\n1. Member ID \n2. Name \n3. Address \n4. Phone number \n5. Back to main menu.");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            printf("\nEnter new ID: ");
            scanf("%s", memb[index].id);
            break;
        }
        case 2: {
            printf("\nEnter new name: ");
            scanf(" %[^\n]s", memb[index].name);
            break;
        }
        case 3: {
            printf("\nEnter new address: ");
            scanf(" %[^\n]s", memb[index].address);
            break;
        }
        case 4: {
            printf("\nEnter new phone number: ");
            scanf("%s", memb[index].phone_no);
            break;
        }
        case 5: {
            menu();
            break;
        }
    }
    printf("\nMember details updated successfully.\n\n");
    menu();
}

void dlt_memb(struct members *memb, int *m) {
    char dlt_id[25];
    int flag = 0;
    printf("\nEnter member ID to delete: ");
    scanf("%s", dlt_id);
    for (int i = 0; i < *m; i++) {
        if (strcmp(memb[i].id, dlt_id) == 0) {
            for (int j = i; j < *m - 1; j++) {
                memb[j] = memb[j + 1];
            }
            (*m)--;
            flag = 1;
        }
    }
    if (flag == 0)
        printf("\nMember details not found!\n");
    else
        printf("\nDeleted Member details added successfully.\n");
    menu();
}

void display_memb(struct members memb[], int m) {
    if (m == 0) {
        printf("\nNo members to display!\n");
    } else {
        printf("\nDisplaying member details:\n\n");
        printf("---------------------------------------------------------------------\n");
        printf("%-15s %-25s %-30s %-15s\n", "ID", "Name", "Address", "Phone Number");
        printf("---------------------------------------------------------------------\n");
        for (int j = 0; j < m; j++) {
            printf("%-15s %-25s %-30s %-15s\n", memb[j].id, memb[j].name, memb[j].address, memb[j].phone_no);
        }
    }
    menu();
}


void issue_book(struct transaction tran[], int *t, int *num_books) {
    if (*num_books == 0) {
        printf("No books available to issue!\n");
        return;
    }
    
    printf("Enter Member ID: ");
    scanf("%s", tran[*t].id);
    
    printf("Enter ISBN of the book to issue: ");
    scanf("%s", tran[*t].isbn);
    
    printf("Enter Issue Date (YYYY-MM-DD): ");
    scanf("%s", tran[*t].issue);
    strcpy(tran[*t].return_date, "NULL");
    tran[*t].tr_id = (*t) + 1;
    (*t)++;
    
    printf("\nBook issued successfully!\n");
    menu();
}

void return_book(struct transaction tran[], int *t) {
    if (*t == 0) {
        printf("\nNo transactions available to return!\n");
        return;
    }
    
    int tr_id;
    printf("Enter Transaction ID of the book to return: ");
    scanf("%d", &tr_id);
    int index = -1;
    for (int i = 0; i < *t; i++) {
        if (tran[i].tr_id == tr_id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Transaction not found!\n");
        return;
    }
    
    printf("Enter Return Date (YYYY-MM-DD): ");
    scanf("%s", tran[index].return_date);
    
    printf("Book returned successfully!\n");
    menu();
}

void display_transaction_history(struct transaction tran[], int t) {
    if (t == 0) {
        printf("\nNo transactions available!\n");
        return;
    }

    printf("\nTransaction History:\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("%-15s %-15s %-15s %-15s %-15s\n", "Transaction ID", "Member ID", "ISBN", "Issue Date", "Return Date");
    printf("----------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < t; i++) {
        printf("%-15d %-15s %-15s %-15s %-15s\n", tran[i].tr_id, tran[i].id, tran[i].isbn, tran[i].issue, tran[i].return_date);
    }
    menu();
}

