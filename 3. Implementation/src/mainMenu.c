#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int mainMenu()
{
    printf("\t\t\t*********************\tSELECT TRANSACTION\t********************\n\n");
    printf("[1] Balance Inquiry\n");
    printf("[2] Deposit\n");
    printf("[3] Withdrawal\n");
    printf("[4] Exit\n\n");
    return 6;
}//Main menu

int main()
{
    mainMenu();
}