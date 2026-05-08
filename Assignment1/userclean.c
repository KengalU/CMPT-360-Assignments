/* -----------------------------------------
    Contributors: Kevin Usuanlele / Scott
    ID's: 3103649 / 
    Date: May 7, 2026
    Program: userclean.c
    Description:
    Reference(s):
------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Macros
# define MAXLEN 16
# define MINLEN 3
# define VALIDCHARS "abcdefghijklmnopqrstuvwxyz1234567890_"

bool is_valid_chars(char *username)
{
    for (int i = 0; username[i] != '\0'; i++)
    {
        if (!islower(username[i]) && !isdigit(username[i]) && username[i] != '_')
        {
            return false;
        }
    }
    return true;
}

bool is_valid_length(char *username)
{
    if (strlen(username) < MINLEN || strlen(username) > MAXLEN)
        {
           return false;
        }
    return true;
}

int main ()
{

    char username[MAXLEN + 1]; // +1 for \0

    fgets(username, sizeof(username), stdin);
    username[strcspn(username, '\n')] = '\0';

    printf("username is: %s", username); //test















    return 0;
}