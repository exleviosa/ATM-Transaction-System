#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>


float checkBal(float balance);


float checkBal(float balance)
{
    printf("\n\t\t\t\t**************************************************************\n\n");
    printf("\t\t\t\tYou've selected: Balance Inquiry\n\n");
    printf("\t\t\t\t**************************************************************\n\n");
    printf("\t\t\t\tYour Available Balance: PHP %.2f\n\n", balance);
    printf("\t\t\t\t_____________________________________________________________\n\n");
    printf("\t\t\t\t\t\t   Transaction Record\n\n");
    time_t now;
    time(&now);
    printf("\t\t\t\tDATE:\t\t\t\t%s", ctime(&now));
    printf("\t\t\t\tCARD NO.:\t\t\t************5263\n");
    printf("\t\t\t\tTRANSACTION:\t\t\tBALANCE INQUIRY\n");
    printf("\t\t\t\tTOTAL BALANCE:\t\t\tPHP %.2f\n", balance);
    printf("\t\t\t\tAVAILABLE BALANCE:\t\tPHP %.2f\n", balance);
    printf("\n\t\t\t\t\t\tTHIS IS YOUR TRANSACTION RECORD\n");
    printf("\t\t\t\t\tTHANK YOU FOR BANKING WITH US. HAVE A GREAT DAY\n");
    return balance;
}//balance inquiry

int main()
{
    float balance = 500000;

    checkBal(balance);

}

