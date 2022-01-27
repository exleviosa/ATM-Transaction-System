#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>


float cashWithdrawal(float balance);


float cashWithdrawal(float balance)
{
    float withdrawal;
    bool i = true;

    printf("\t\t\t\t**************************************************************\n\n");
    printf("\t\t\t\tYou've selected: Withdrawal\n\n");
    printf("\t\t\t\t**************************************************************\n\n");
    printf("\t\t\t\tYour Available Balance: PHP %.2f\n\n", balance);

    while(i)
    {
        printf("\n\t\t\t\tEnter amount: ");
        scanf("%f", &withdrawal);
        if(withdrawal < balance)
        {
            i = false;
            balance -= withdrawal;
            printf("\n\t\t\t\tYour money has been withdrawn successfully...\n\n");
            printf("\t\t\t\t____________________________________________________________\n\n");
            printf("\t\t\t\t\t\t   Transaction Record\n\n");
            time_t now;
            time(&now);
            printf("\t\t\t\tDATE:\t\t\t\t%s", ctime(&now));
            printf("\t\t\t\tCARD NO.:\t\t\t************5263\n");
            printf("\t\t\t\tTRANSACTION:\t\t\tCASH WITHDRAWAL\n");
            printf("\t\t\t\tTOTAL BALANCE:\t\t\tPHP %.2f\n", balance);
            printf("\t\t\t\tAVAILABLE BALANCE:\t\tPHP %.2f\n", balance);
            printf("\n\t\t\t\t\t\tTHIS IS YOUR TRANSACTION RECORD\n");
            printf("\t\t\t\t\tTHANK YOU FOR BANKING WITH US. HAVE A GREAT DAY!\n");
        }
        else
        {
            Beep(800,800);
            Beep(800,800);
            Beep(800,850);
            printf("\t\t\t\t____________________________________________________________\n\n");
            printf("\t\t\t\t\tYou don't have enough balance in your account...\n");
            printf("\t\t\t\t\tPlease contact to your Bank Customer Service.\n");
            printf("\t\t\t\t____________________________________________________________\n\n");
            printf("\t\t\t\tYour Available Balance: PHP %.2f\n\n", balance);
        }
        return balance;
    }


}//Cash withdrawal

int main()
{
    float balance = 500000;

    cashWithdrawal(balance);

}