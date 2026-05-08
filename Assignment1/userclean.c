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


// Validation Helper Functions
bool is_valid_chars(char *username)
{
    for (int i = 0; username[i] != '\0'; i++)
    {
        // char must be lowercase letter, digit, or underscore
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

bool is_not_reserved(char *username)
{
    if (strcmp(username, "root") == 0 || strcmp(username, "admin") == 0)
    {
        return false;
    }
    return true;
}

bool is_valid(char *username)
{
    if (!is_valid_chars(username)) return false;
    if (!is_valid_length(username)) return false;
    if (!is_not_reserved(username)) return false;
    return true;
}

int main ()
{

    char username[MAXLEN + 1]; // +1 for \0

    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("username is: %s\n", username); //test

    if (is_valid(username))
    {
        printf("%s is clean!", username);
        return 0;
    }
    else
    {
        printf("%s is not clean", username);
        // clean username
        return 0;
    }
    return 0;
}