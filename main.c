#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>


//Macro preprocessor
// 13 is the ASCII value of ENTER key...
#define ENTER 13
#define TAB 9
#define BCKSPC 8

//list of function declarations
void getPin();
bool pinValidation();
int mainMenu();
float checkBal(float balance);
float cashDeposit(float balance);
float cashWithdrawal(float balance);
void exitMenu();
void errorMessage();

int main()
{
    //local variable
    float balance = 150000.00;
    int selection, choose;
    bool temp = true;

    system("color 1E");
    time_t now;
    time(&now);
    printf("\t\t\t\t\t\t%s\n", ctime(&now));
    printf("\t\t\t___________________________________________________________________\n\n");
    printf("\t\t\t\t\t\tATM TRANSACTION SYSTEM\n");
    printf("\t\t\t___________________________________________________________________\n\n");
    pinValidation();

    while(temp)
    {
        mainMenu();

        printf("\t\t\t___________________________________________________________________\n\n");
        printf("\t\t\tYour Selection: ");
        scanf("%d", &selection);

        switch(selection)
        {
            case 1:
                system("CLS");
                checkBal(balance);
                break;
            case 2:
                system("CLS");
                balance = cashDeposit(balance);
                break;
            case 3:
                system("CLS");
                balance = cashWithdrawal(balance);
                break;
            case 4:
                system("CLS");
                exitMenu();
                exit(0);
            default:
                system("CLS");
                errorMessage();
                break;
        }
        printf("\t\t\t___________________________________________________________________\n\n");
        printf("\t\t\tWould you like to perform another transaction?\n");
        printf("\t\t\t[1] Yes\n");
        printf("\t\t\t[2] No\n");
        printf("\t\t\t___________________________________________________________________\n\n");
        printf("\t\t\tYour Selection: ");
        scanf("%d", &choose);
        system("CLS");

        if(choose == 2)
        {
            temp = false;
            exitMenu();
        }
    }

    return 0;
}

//Getting and masking pin from the user
void getPin(char* inputPin, int maxPinLength)
{
    char ch;
    int pinLength = 0;
    inputPin[pinLength] = '\0';

    //Input PIN
    printf("\t\t\tEnter Your PIN: ");
    do
    {
        ch = getch();
        switch(ch)
        {
            //Keys to ignored when pressed
            case ENTER:
            case TAB:
                break;
            //Allows user to use backspace and delete previous digits
            case BCKSPC:
                if (pinLength > 0)
                {
                    pinLength--;
                    printf("\b \b");
                }
                break;
            //masks the PIN characters
            default:
            inputPin[pinLength] = ch;
            pinLength++;
            printf("*");
            break;
        }
    }while(ch != ENTER && pinLength < 8);
    printf("\n");
}

//defining a function to validate PIN from the user
bool pinValidation()
{
    char validPin[] = "526303";
    char pin[8];
    int attemptCount = 0;

    while(attemptCount < 3 && strcmp(pin, validPin) != 0)
    {
        attemptCount++;
        getPin(pin, 8);
        if(strcmp(pin, validPin) != 0)
        {
            Beep(700, 800);
            printf("\t\t\t\t\t\t  INVALID PIN\n");
            printf("\t\t\t\t\t  YOU HAVE %d ATTEMPT LEFT\n\n", 3 - attemptCount);
        }
    }
    if(strcmp(pin, validPin) == 0)
    {
        Beep(800,500);
        Beep(800,600);
        printf("\t\t\t\t\t\tACCESS GRANTED\n\n");
    }
    else
    {   Beep(700,800);
        Beep(700,800);
        Beep(700,850);
        printf("\t\t\t\t\t\tATTEMPT HAS REACHED\n");
        printf("\t\t\t\t\tPLEASE CONTACT THE BANK CUSTOMER SERVICE\n");
        exit(0);
    }
}


int mainMenu()
{
    printf("\n\t\t\t*********************\tSELECT TRANSACTION\t********************\n\n");
    printf("\t\t\t[1] Balance Inquiry\n");
    printf("\t\t\t[2] Deposit\n");
    printf("\t\t\t[3] Withdrawal\n");
    printf("\t\t\t[4] Exit\n\n");
    return 6;
}//Main menu


float checkBal(float balance)
{
    printf("\n");
    printf("\n\t\t\t******************************************************************\n\n");
    printf("\t\t\tYou have selected: Balance Inquiry\n\n");
    printf("\t\t\t******************************************************************\n\n");
    printf("\t\t\tYour Available Balance: PHP %.2f\n\n", balance);
    printf("\t\t\t___________________________________________________________________\n\n");

    printf("\t\t\t\t\t\t   TRANSACTION RECORD\n\n\n");
    time_t now;
    time(&now);
    printf("\t\t\t\tDATE:\t\t\t\t%s", ctime(&now));
    printf("\t\t\t\tCARD NO.:\t\t\t************5263\n");
    printf("\t\t\t\tTRANSACTION:\t\t\tBALANCE INQUIRY\n");
    printf("\t\t\t\tTOTAL BALANCE:\t\t\tPHP %.2f\n", balance);
    printf("\t\t\t\tAVAILABLE BALANCE:\t\tPHP %.2f\n\n", balance);
    printf("\n\t\t\t\t\t\tTHIS IS YOUR TRANSACTION RECORD\n");
    printf("\t\t\t\t\tTHANK YOU FOR BANKING WITH US. HAVE A GREAT DAY!\n\n");
    return balance;
}//balance inquiry

float cashDeposit(float balance)
{
    float deposit;
    long int accNum;
    printf("\n");
    printf("\n\t\t\t******************************************************************\n\n");
    printf("\t\t\tYou have selected: Deposit\n\n");
    printf("\n\t\t\t******************************************************************\n\n");
    printf("\t\t\tYour Available Balance: PHP %.2f\n\n", balance);
    printf("\n\t\t\tEnter Account Number: ");
    scanf("%ld", &accNum);
    printf("\n\t\t\tEnter amount: ");
    scanf("%f", &deposit);
    printf("\n\t\t\t\tYour money has been deposited successfully...\n\n");
    printf("\t\t\t___________________________________________________________________\n\n");
    balance += deposit;

    printf("\t\t\tYou have deposited: PHP %.2f\n", deposit);
    printf("\t\t\tYour new total balance: PHP %.2f\n\n", balance);
    return balance;

}//Cash deposit

float cashWithdrawal(float balance)
{
    float withdrawal;
    bool i = true;

    printf("\n");
    printf("\n\t\t\t******************************************************************\n\n");
    printf("\t\t\tYou have selected: Withdrawal\n\n");
    printf("\n\t\t\t******************************************************************\n\n");
    printf("\t\t\tYour Available Balance: PHP %.2f\n\n", balance);

    while(i)
    {
        printf("\n\t\t\tEnter amount: ");
        scanf("%f", &withdrawal);
        if(withdrawal < balance)
        {
            i = false;
            balance -= withdrawal;
            printf("\n\t\t\t\tYour money has been withdrawn successfully...\n\n");
            printf("\t\t\t___________________________________________________________________\n\n");
            printf("\t\t\t\t\t\t   Transaction Record\n\n\n");
            time_t now;
            time(&now);
            printf("\t\t\t\tDATE:\t\t\t\t%s", ctime(&now));
            printf("\t\t\t\tCARD NO.:\t\t\t************5263\n");
            printf("\t\t\t\tTRANSACTION:\t\t\tCASH WITHDRAWAL\n");
            printf("\t\t\t\tTOTAL BALANCE:\t\t\tPHP %.2f\n", balance);
            printf("\t\t\t\tAVAILABLE BALANCE:\t\tPHP %.2f\n\n", balance);
            printf("\n\t\t\t\t\t\tTHIS IS YOUR TRANSACTION RECORD\n");
            printf("\t\t\t\t\tTHANK YOU FOR BANKING WITH US. HAVE A GREAT DAY!\n\n");
        }
        else
        {
            Beep(800,800);
            Beep(800,800);
            Beep(800,850);
            printf("\t\t\t___________________________________________________________________\n\n");
            printf("\t\t\t\tYou don't have enough balance in your account...\n");
            printf("\t\t\tPlease contact to your Bank Customer Service.\n");
            printf("\t\t\t___________________________________________________________________\n\n");
            printf("\t\t\tYour Available Balance: PHP %.2f\n\n", balance);
        }
        return balance;
    }


}//Cash withdrawal

void exitMenu()
{
    printf("\n\t\t\t******************************************************************\n\n");
    printf("\t\t\t\tTHANK YOU FOR BANKING WITH US. HAVE A GREAT DAY!\n");
    printf("\n\t\t\t******************************************************************\n\n");
}

void errorMessage()
{
    Beep(800,800);
    Beep(800,800);
    Beep(800,850);
    printf("\n\t\t\t\t\tYou have selected invalid number\n");
}
