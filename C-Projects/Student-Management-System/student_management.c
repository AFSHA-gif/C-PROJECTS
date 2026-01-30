#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[100];
    int count = 0, choice, i, roll, found;
    
    while (1) {
        printf("\n====== Student Management System ======\n");
        printf("1. Add Student\n2. Display All Students\n3. Search Student by Roll\n4. Update Student Marks\n5. Delete Student\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                printf("Enter Roll: ");
                scanf("%d", &s[count].roll);
                printf("Enter Name: ");
                scanf("%s", s[count].name);
                printf("Enter Marks: ");
                scanf("%f", &s[count].marks);
                count++;
                printf("Student Added Successfully!\n");
                break;
            case 2:
                printf("\n--- Student List ---\n");
                for (i = 0; i < count; i++) {
                    printf("Roll: %d, Name: %s, Marks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
                }
                break;
            case 3:
                printf("Enter Roll to Search: ");
                scanf("%d", &roll);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (s[i].roll == roll) {
                        printf("Student Found!\nRoll: %d, Name: %s, Marks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
                        found = 1;
                    }
                }
                if (!found) printf("Student Not Found!\n");
                break;
            case 4:
                printf("Enter Roll to Update Marks: ");
                scanf("%d", &roll);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (s[i].roll == roll) {
                        printf("Enter New Marks: ");
                        scanf("%f", &s[i].marks);
                        printf("Marks Updated Successfully!\n");
                        found = 1;
                    }
                }
                if (!found) printf("Student Not Found!\n");
                break;
            case 5:
                printf("Enter Roll to Delete: ");
                scanf("%d", &roll);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (s[i].roll == roll) {
                        for (int j = i; j < count - 1; j++) {
                            s[j] = s[j + 1];
                        }
                        count--;
                        printf("Student Deleted Successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Student Not Found!\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
