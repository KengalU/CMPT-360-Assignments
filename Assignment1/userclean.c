/* -----------------------------------------
    Contributors: Kevin Usuanlele / Scott Weaver
    ID's: 3103649 / 3144661
    Submission Date: May 10, 2026
    Program: userclean.c
    Description: Transforms a given username to suitable name that follows the given criteria
    Reference(s): strcpsn() - https://www.w3schools.com/c/ref_string_strcspn.php
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
/*
    Purpose: Checks if the first letter is lowercase/digits/underscore
    Params: username: username string to check
    Return: True if valid, False otherwise
*/
{
    return islower(username[0]);
}

bool is_valid_chars(char *username)
/*
    Purpose: Checks if all letters are lowercase/digits/underscore
    Params: username: username string to check
    Return: True if all chars are valid, False otherwise
*/
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
/*
    Purpose: Checks if username length is between MINLEN and MAXLEN
    Params: username: username string to check
    Return: True if length is valid, False otherwise
*/
{
    if (strlen(username) < MINLEN || strlen(username) > MAXLEN)
        {
           return false;
        }
    return true;
}

bool is_reserved(char *username)
/*
    Purpose: Checks if username is reserved sys name
    Params: username: username string to check
    Return: True if reserved, False otherwise
*/
{
    if (strcmp(username, "root") == 0 || strcmp(username, "admin") == 0)
    {
        return true;
    }
    return false;
}

bool clean(char *username)
/*
    Purpose: Attempts to clean username to fix requirements
             lowercase -> spaces -> invalid chars -> pad/trun -> validate
    Params: username: username string to check
    Return: True if username fix passes validations, False if unfixable
*/
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

            if (strchr(VALIDCHARS, username[i]) != NULL) // strchr points to NULL if invalid char
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
        // append fillerchars until length req is met
        {
            int end = strlen(username);
            username[end] = FILLERCHARS[i];
            username[end + 1] = '\0';
            i++;
        }

        // cut off string at max length with \0
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

    // Read username
    if (fgets(username, sizeof(username), stdin) == NULL)
    {
        return 1;
    }
    username[strcspn(username, "\n")] = '\0'; // replace returned pointer ('\n') with \0

    // Alloc mem and save a copy
    old_username = malloc(strlen(username) + 1); // save original username for ouput, +1 for \0
    strcpy(old_username, username);
    new_username = malloc(BUFFER);
    strcpy(new_username, username);

    // Check if username is reserved
    if (is_reserved(username))
    {
        printf("%s : invalid and unfixable\n", username);
        free(old_username);
        free(new_username);
        return 0;
    }

    // Attempt to clean username
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
