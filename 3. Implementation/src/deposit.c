#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


float cashDeposit(float balance);


float cashDeposit(float balance)
{
    float deposit;
    long int accNum;
    printf("\n\t\t\t\t**************************************************************\n\n");
    printf("\t\t\t\tYou've selected: Deposit\n\n");
    printf("\t\t\t\t**************************************************************\n\n");
    printf("\t\t\t\tYour Available Balance: PHP %.2f\n\n", balance);
    printf("\n\t\t\t\tEnter Account Number: ");
    scanf("%ld", &accNum);
    printf("\n\t\t\t\tEnter amount: ");
    scanf("%f", &deposit);
    printf("\n\t\t\t\tYour money has been deposited successfully...\n\n");
    printf("\t\t\t\t______________________________________________________\n\n");
    balance += deposit;

    printf("\t\t\t\tYou've deposited: PHP %.2f\n", deposit);
    printf("\t\t\t\tYour new total balance: PHP %.2f\n\n", balance);
    printf("\t\t\t\t______________________________________________________\n\n");
    return balance;

}//Cash deposit

int main()
{
    float balance = 500000;

    cashDeposit(balance);

}