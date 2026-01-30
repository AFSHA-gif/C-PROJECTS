#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int available;
};

int main() {
    struct Book b[100];
    int count = 0, choice, id, found, i;

    while (1) {
        printf("\n====== Library Management System ======\n");
        printf("1. Add Book\n2. Display All Books\n3. Search Book by ID\n4. Issue Book\n5. Return Book\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &b[count].id);
                printf("Enter Book Title: ");
                scanf(" %[^\n]s", b[count].title);
                printf("Enter Author Name: ");
                scanf(" %[^\n]s", b[count].author);
                b[count].available = 1;
                count++;
                printf("Book Added Successfully!\n");
                break;
            case 2:
                printf("\n--- Library Book List ---\n");
                for (i = 0; i < count; i++) {
                    printf("ID: %d, Title: %s, Author: %s, Status: %s\n",
                           b[i].id, b[i].title, b[i].author,
                           b[i].available ? "Available" : "Issued");
                }
                break;
            case 3:
                printf("Enter Book ID to Search: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (b[i].id == id) {
                        printf("Book Found!\nID: %d, Title: %s, Author: %s, Status: %s\n",
                               b[i].id, b[i].title, b[i].author,
                               b[i].available ? "Available" : "Issued");
                        found = 1;
                    }
                }
                if (!found) printf("Book Not Found!\n");
                break;
            case 4:
                printf("Enter Book ID to Issue: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (b[i].id == id) {
                        if (b[i].available) {
                            b[i].available = 0;
                            printf("Book Issued Successfully!\n");
                        } else {
                            printf("Book Already Issued!\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Book Not Found!\n");
                break;
            case 5:
                printf("Enter Book ID to Return: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (b[i].id == id) {
                        if (!b[i].available) {
                            b[i].available = 1;
                            printf("Book Returned Successfully!\n");
                        } else {
                            printf("Book was not issued!\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Book Not Found!\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
