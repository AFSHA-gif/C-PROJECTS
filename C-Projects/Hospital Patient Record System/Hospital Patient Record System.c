#include <stdio.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

int main() {
    struct Patient p[100];
    int count = 0, choice, id, found, i;

    while (1) {
        printf("\n====== Hospital Patient Record System ======\n");
        printf("1. Add Patient\n2. View All Patients\n3. Update Patient Info\n4. Delete Patient\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &p[count].id);
                printf("Enter Name: ");
                scanf("%s", p[count].name);
                printf("Enter Age: ");
                scanf("%d", &p[count].age);
                printf("Enter Disease: ");
                scanf("%s", p[count].disease);
                count++;
                printf("Patient Added Successfully!\n");
                break;
            case 2:
                printf("\n--- Patient List ---\n");
                for (i = 0; i < count; i++) {
                    printf("ID: %d, Name: %s, Age: %d, Disease: %s\n",
                           p[i].id, p[i].name, p[i].age, p[i].disease);
                }
                break;
            case 3:
                printf("Enter Patient ID to Update: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (p[i].id == id) {
                        printf("Enter New Name: ");
                        scanf("%s", p[i].name);
                        printf("Enter New Age: ");
                        scanf("%d", &p[i].age);
                        printf("Enter New Disease: ");
                        scanf("%s", p[i].disease);
                        printf("Patient Updated Successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Patient Not Found!\n");
                break;
            case 4:
                printf("Enter Patient ID to Delete: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (p[i].id == id) {
                        for (int j = i; j < count - 1; j++) p[j] = p[j + 1];
                        count--;
                        printf("Patient Deleted Successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Patient Not Found!\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
