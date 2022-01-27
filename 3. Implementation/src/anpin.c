#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define ENTER 13
#define TAB 9
#define BCKSPC 8

void getPin(char* inputPin, int maxPinLength)
{
    char ch;
    int pinLength = 0;
    inputPin[pinLength] = '\0';

    //Input PIN
    printf("\t\t\t\tEnter Your PIN: ");
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
            printf("\t\t\t\t\t\t\t  INVALID PIN\n");
            printf("\t\t\t\t\t\t  YOU HAVE %d ATTEMPT LEFT\n\n", 3 - attemptCount);
        }
    }
    if(strcmp(pin, validPin) == 0)
    {
        Beep(800,500);
        Beep(800,600);
        printf("\t\t\t\t\t\t\tACCESS GRANTED\n");
    }
    else
    {   Beep(700,800);
        Beep(700,800);
        Beep(700,850);
        printf("\t\t\t\t\t\t\tATTEMPT HAS REACHED\n");
        printf("\t\t\t\t\t\tPLEASE CONTACT THE BANK CUSTOMER SERVICE\n");
    }
}

int main()
{
    pinValidation();
    return 0;
}
