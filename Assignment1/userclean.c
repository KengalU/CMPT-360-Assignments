/* -----------------------------------------
    Contributors: Kevin Usuanlele / Scott
    ID's: 3103649 / 
    Date: May 9, 2026
    Program: userclean.c
    Description:
    Reference(s):
------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Macros
# define MAXLEN 16
# define MINLEN 3
# define VALIDCHARS "abcdefghijklmnopqrstuvwxyz1234567890_"
# define FILLERCHARS "user"
# define BUFFER 1024

// Validation Helper Functions
bool is_valid_first(char *username)
{
    return islower(username[0]);
}

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

bool is_reserved(char *username) // Checks if the username is "root" or "admin"
{
    if (strcmp(username, "root") == 0 || strcmp(username, "admin") == 0)
    {
        return true;
    }
    return false;
}

bool clean(char *username)
{
    if (!is_valid_chars(username)) // bring username to lowercase, replace whitespace with underscore
    {
        int i = 0, j = 0; // i for reading, j for writing
        while (username[i] != '\0')
        {
            username[i] = tolower(username[i]);
            if (username[i] == ' ')
            {
            username[i] = '_';
            }

            if (strchr(VALIDCHARS, username[i]) != NULL) // if username[i] is a valid char
            {
                username[j] = username[i]; // write
                j++; // increment j for every valid char
            }
            i++;
        }
        username[j] = '\0'; // append '\0' to end new username
    }

    if (!is_valid_length(username))
    {
        int i = 0;
        while (strlen(username) < MINLEN)
        {
            int end = strlen(username);
            username[end] = FILLERCHARS[i];
            username[end + 1] = '\0';
            i++;
        }

        if (strlen(username) > MAXLEN)
        {
            username[MAXLEN] = '\0';
        }
    }

    // Run Validation tests again
    if (is_reserved(username)) return false;
    if (!is_valid_first(username)) return false;
    if (!is_valid_length(username)) return false;
    
    return true;
}

int main ()
{
    char username[BUFFER], *old_username, *new_username;

    // Get username
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    // Alloc mem and save a copy
    old_username = strdup(username); // alloc mem and save original username
    new_username = malloc(BUFFER); // alloc mem and save for clean
    strcpy(new_username, username);

    // Check if username is reserved
    if (is_reserved(username))
    {
        printf("%s : invalid and unfixable\n", username);
        free(old_username);
        free(new_username);
        return 0;
    }

    // Clean username
    bool cleaned = clean(new_username);
    if (cleaned)
    {
        printf("%s : %s\n", old_username, new_username);
    }
    else
    {
        printf("%s : invalid and unfixable\n", old_username);
    }

    // Free mem
    free(old_username);
    free(new_username);
    return 0;
}