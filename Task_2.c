#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

/*

TASK 2

*/


typedef enum
{
    Withdraw = 0,
    Deposit
} TransactionType;

typedef struct
{

    TransactionType type;
    float amount;
    char date[10];

} TransactionHistory;

typedef struct
{

    int MinimumBalance;
    int interestrate;
    char creationDate[10];
    char LastTransactionDate[10];
    TransactionHistory *TransactionHistory;

} Account;

Account *Savings, *Current, *Fixed_Deposit;

void Storeinformation(int Count, Account *Type);

int main()
{

    int Count;

    printf("Note: All dates are in format DD/MM/YYYY\n\n");

    printf("Enter number of savings account: ");
    scanf(" %d", &Count);

    Storeinformation(Count, Savings);

    printf("\nEnter number of Current accounts: ");
    scanf(" %d", &Count);

    Storeinformation(Count, Current);

    printf("\nEnter number of Fixed Deposit accounts: ");
    scanf(" %d", &Count);

    Storeinformation(Count, Current);

    free(Savings);
    free(Fixed_Deposit);
    free(Current);

    return 0;
}

void Storeinformation(int Count, Account *Type)
{

    int MinimumBalance, InterestRate, tempcounter;
    char TransactionType, ch;

    Type = (Account *)malloc(sizeof(Account) * Count);

    printf("Enter minimum Amount for this type of account: ");
    scanf(" %d", &MinimumBalance);

    printf("Enter interest rate for this type of account: ");
    scanf(" %d", &InterestRate);

    for (int i = 0; i < Count; i++)
    {

        Type[i].MinimumBalance = MinimumBalance;
        Type[i].interestrate = InterestRate;

        printf("\nEnter Account Creation Date: ");
        while ((ch = getchar() == '\n' && !EOF))
            ;
        gets(Type[i].creationDate);

        printf("\nEnter Last transaction Date: ");
        while ((ch = getchar() == '\n' && !EOF))
            ;
        gets(Type[i].LastTransactionDate);

        printf("\nEnter length of transaction history to enter: ");
        scanf(" %d", &tempcounter);

        Type[i].TransactionHistory = (TransactionHistory *)malloc(sizeof(TransactionHistory) * tempcounter);

        for (int j = 0; j < tempcounter; j++)
        {

            while (true)
            {
                printf("Enter Transaction type for transaction number %d. W for withdraw, D for Deposit: ", j + 1);
                scanf(" %c", &TransactionType);
                if (TransactionType == 'W' || TransactionType == 'w')
                {
                    Type[i].TransactionHistory[j].type = Withdraw;
                    break;
                }
                else if (TransactionType == 'D' || TransactionType == 'd')
                {
                    Type[i].TransactionHistory[j].type = Deposit;
                    break;
                }
                else
                {
                    printf("Invalid Depost type. Kindly enter information again.");
                }
            }
            printf("Enter Transaction Date: ");
            while ((ch = getchar() == '\n' && !EOF))
                ;
            gets(Type[i].TransactionHistory[j].date);
            printf("Enter Transaction Amount: ");
            scanf("%d", &Type[i].TransactionHistory[j].amount);
            printf("\n");
        }
    }
}
