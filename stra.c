#include "str.h"
#include <stddef.h>

/* Returns how many characters are in the given string 
(excludes '\0'). Takes an array or pointer as input and 
returns a size_t value.*/
size_t Str_getlength(char str[]){
    assert(str != NULL);
    size_t i;
    int j;

    i = 0;
    j = 0;

    while (str[j++] != '\0') {
        i++;
    }

    return i;
}

/* Copies the characters in the second argument into the first.
Takes two strings as arguments and returns a pointer 
that points at the first element of the copied string.*/
char *Str_copy(char str1[], char str2[]) {
    assert (str1 != NULL);
    assert (str2 != NULL);

    size_t i;
    size_t size;
    size_t noOfElements;

    size = Str_getlength(str2);
    noOfElements = size / sizeof(str2[0]);

    for (i = 0; i < noOfElements; i++) {
        str1[i] = str2[i];
    }

    return str1;
}

/* Grafts the characters of the second argument onto the end of
first argument. Takes two strings as arguments, and returns a 
pointer to the first element of the final array.*/
char *Str_concat(char str1[], char str2[]) {
    assert (str1 != NULL);
    assert (str2 != NULL);

    size_t i;
    size_t size1;
    size_t size2;
    size_t noOfElements1;
    size_t noOfElements2;

    size1 = Str_getlength(str1);
    totalNoOfElements1 = sizeof(str1) / sizeof(str1[0]);
    size2 = Str_getlength(str2);

    assert(size2 <= totalNoOfElements1 - size1);

    for (i = 0; str2[i] != '\0'; i++) {
        str1[i + size1] = str2[i];
    }

    str1[size1 + size2] = '\0';
    return str1;
}

/* Lexicographically compares the two given strings. Takes
two strings as input. Returns 1 if str1 is more than str2, 
returns -1 if str1 is less than str2, and 0 if they're equal.
*/
int Str_compare(char str1[], char str2[]) {
    assert (str1 != NULL);
    assert (str2 != NULL);

    size_t i;
    for (i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++) {
        if (str1[i] < str2[i]) return -1;
        else if (str1[i] > str2[i]) return 1;
        else continue;
    }

    return 0;
}

/* Searches the first string and checks if it contains the 
second string. Takes two strings as input and returns a pointer
that points to the first element of the substring, and NULL otherwise*/
char *Str_search(char string[], char substring[]) {
    assert (str1 != NULL);
    assert (str2 != NULL);

    size_t i;
    size_t j;
    int compare;
    size_t size1;
    size_t size2;

    char temp[Str_getlength(substring)];

    size1 = Str_getlength(string);
    size2 = Str_getlength(substring);

    if (size2 == 0) return string;

    for (i = 0; 
        (substring[i] != '\0') && (string[i + size2] != '\0');
         i++) {
        for (j = 0; j < size2; j++) {
            temp[j] = string[i + j];
        }

        compare = Str_compare(temp, substring);
        if (compare == 0) 
            return &string[i];
    }

    return NULL;
}

