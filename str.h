#include <stddef.h>
#include "str.h"
#ifndef STR_H
#define STR_H

/* Returns how many characters are in the given string 
(excludes '\0'). Takes an array or pointer as input and 
returns a size_t value.*/
size_t Str_getlength(char str[]);

/* Copies the characters in the second argument into the first.
Takes two strings as arguments and returns a pointer 
that points at the first element of the copied string.*/
char *Str_copy(char str1[], char str2[]);

/* Grafts the characters of the second argument onto the end of
first argument. Takes two strings as arguments, and returns a 
pointer to the first element of the final array.*/
char *Str_concat(char str1[], char str2[]);

/* Lexicographically compares the two given strings. Takes
two strings as input. Returns 1 if str1 is more than str2, 
returns -1 if str1 is less than str2, and 0 if they're equal.
*/
int Str_compare(char str1[], char str2[]);

/* Searches the first string and checks if it contains the 
second string. Takes two strings as input and returns a pointer
that points to the first element of the substring, and NULL otherwise*/
char *Str_search(char string[], char substring[]);

#endif
