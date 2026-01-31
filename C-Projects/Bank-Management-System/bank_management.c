#include <stdio.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

int main() {
    struct Account a[100];
    int count = 0, choice, accNo, i, found;
    float amount;

    while (1) {
        printf("\n====== Bank Management System ======\n");
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Display All Accounts\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Account Number: ");
                scanf("%d", &a[count].accNo);
                printf("Enter Account Holder Name: ");
                scanf("%s", a[count].name);
                a[count].balance = 0;
                count++;
                printf("Account Created Successfully!\n");
                break;
            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (a[i].accNo == accNo) {
                        printf("Enter Amount to Deposit: ");
                        scanf("%f", &amount);
                        a[i].balance += amount;
                        printf("Amount Deposited. New Balance: %.2f\n", a[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Account Not Found!\n");
                break;
            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (a[i].accNo == accNo) {
                        printf("Enter Amount to Withdraw: ");
                        scanf("%f", &amount);
                        if (amount <= a[i].balance) {
                            a[i].balance -= amount;
                            printf("Withdrawal Successful. New Balance: %.2f\n", a[i].balance);
                        } else {
                            printf("Insufficient Balance!\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Account Not Found!\n");
                break;
            case 4:
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (a[i].accNo == accNo) {
                        printf("Account Holder: %s, Balance: %.2f\n", a[i].name, a[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Account Not Found!\n");
                break;
            case 5:
                printf("\n--- All Accounts ---\n");
                for (i = 0; i < count; i++) {
                    printf("AccNo: %d, Name: %s, Balance: %.2f\n", a[i].accNo, a[i].name, a[i].balance);
                }
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
