#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    int pin = 1234, enteredPin, newPin;
    int fastChoice;
    float balance = 500.00, amount;
    char history[1000] = "Transaction History:\n";
    char temp[200];

    printf("===== WELCOME TO BSIT BANK =====\n");

    // PIN verification
    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Incorrect PIN. Access denied.\n");
        return 1;
    }

    do {
        printf("\n===== BSIT BANK ATM =====\n");
        printf("[1] Balance Inquiry\n");
        printf("[2] Deposit\n");
        printf("[3] Withdraw\n");
        printf("[4] Transfer\n");
        printf("[5] Fast Cash\n");
        printf("[6] Change PIN\n");
        printf("[7] Transaction History\n");
        printf("[8] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYour current balance is: P%.2f\n", balance);
                sprintf(temp, "Balance Inquiry: P%.2f\n", balance);
                strcat(history, temp);
                break;

            case 2:
                printf("\nEnter amount to deposit: ");
                scanf("%f", &amount);

                if (amount > 0) {
                    balance += amount;
                    printf("P%.2f deposited successfully!\n", amount);
                    sprintf(temp, "Deposited: P%.2f\n", amount);
                    strcat(history, temp);
                } else {
                    printf("Invalid deposit amount!\n");
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: ");
                scanf("%f", &amount);

                if (amount > 0) {
                    if ((balance - amount) >= 100.00) {
                        balance -= amount;
                        printf("You withdrew P%.2f successfully!\n", amount);
                        sprintf(temp, "Withdrawn: P%.2f\n", amount);
                        strcat(history, temp);
                    } else {
                        printf("Withdrawal denied! You must maintain at least P100.00 in your account.\n");
                    }
                } else {
                    printf("Invalid withdrawal amount!\n");
                }
                break;

            case 4:
                printf("\nEnter amount to transfer: ");
                scanf("%f", &amount);

                if (amount > 0) {
                    if ((balance - amount) >= 100.00) {
                        balance -= amount;
                        printf("P%.2f transferred successfully!\n", amount);
                        sprintf(temp, "Transferred: P%.2f\n", amount);
                        strcat(history, temp);
                    } else {
                        printf("Transfer denied! You must maintain at least P100.00 in your account.\n");
                    }
                } else {
                    printf("Invalid transfer amount!\n");
                }
                break;

            case 5:
                printf("\nFast Cash Options:\n");
                printf("[1] P100\n");
                printf("[2] P200\n");
                printf("[3] P500\n");
                printf("Choose option: ");
                scanf("%d", &fastChoice);

                if (fastChoice == 1)
                    amount = 100;
                else if (fastChoice == 2)
                    amount = 200;
                else if (fastChoice == 3)
                    amount = 500;
                else {
                    printf("Invalid Fast Cash option!\n");
                    break;
                }

                if ((balance - amount) >= 100.00) {
                    balance -= amount;
                    printf("Fast Cash successful! You withdrew P%.2f\n", amount);
                    sprintf(temp, "Fast Cash Withdraw: P%.2f\n", amount);
                    strcat(history, temp);
                } else {
                    printf("Fast Cash denied! You must maintain at least P100.00 in your account.\n");
                }
                break;

            case 6:
                printf("\nEnter current PIN: ");
                scanf("%d", &enteredPin);

                if (enteredPin == pin) {
                    printf("Enter new PIN: ");
                    scanf("%d", &newPin);
                    pin = newPin;
                    printf("PIN changed successfully!\n");
                    strcat(history, "PIN changed successfully.\n");
                } else {
                    printf("Incorrect current PIN!\n");
                }
                break;

            case 7:
                printf("\n%s", history);
                break;

            case 8:
                printf("\nThank you for using BSIT BANK!\n");
                break;

            default:
                printf("\nInvalid choice! Please select from 1 to 8 only.\n");
        }

    } while (choice != 8);

    return 0;
}