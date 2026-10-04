#include "str.h"
#include <stddef.h>

/* Returns how many characters are in the given string 
(excludes '\0'). Takes an array or pointer as input and 
returns a size_t value.*/
size_t Str_getlength(char str[]){
    assert(str != NULL);
    char *current;
    int j;

    current = str;
    j = 0;

    while (*current != '\0') {
        j++;
        current++;
    }

    return j;
}

/* Copies the characters in the second argument into the first.
Takes two strings as arguments and returns a pointer 
that points at the first element of the copied string.*/
char *Str_copy(char str1[], char str2[]) {
    assert (str1 != NULL);
    assert (str2 != NULL);

    char *current;
    char *copy;
    
    copy = str1;
    current = str2;
    
    while (*current != '\0') {
        *copy = *current;
        current++;
        copy++;
    }

    *copy = '\0';
    return str1;
}

/* Grafts the characters of the second argument onto the end of
first argument. Takes two strings as arguments, and returns a 
pointer to the first element of the final array.*/
char *Str_concat(char str1[], char str2[]) {
    assert (str1 != NULL);
    assert (str2 != NULL);

    size_t size1;
    size_t size2;
    size_t totalNoOfElements1;
    char *current;
    char *cat;

    size1 = Str_getlength(str1);
    totalNoOfElements1 = sizeof(str1) / sizeof(str1[0]);
    size2 = Str_getlength(str2);

    assert(size2 <= totalNoOfElements1 - size1);

    current = str1;
    while (*current != '\0') current++;


    for (cat = str2; *cat != '\0'; cat++) {
        *current = *cat;
        current++;
    }

    *current = '\0';
    return str1;
}

/* Lexicographically compares the two given strings. Takes
two strings as input. Returns 1 if str1 is more than str2, 
returns -1 if str1 is less than str2, and 0 if they're equal.
*/
int Str_compare(char str1[], char str2[]) {
    assert (str1 != NULL);
    assert (str2 != NULL);

    char *compare1;
    char *compare2;

    compare1 = str1;
    compare2 = str2;

    while ((*compare1 != '\0') && (*compare2 != '\0')) {
        if (*compare1 < *compare2) return -1;
        else if (*compare1 > *compare2) return 1;
        else {
            compare1++;
            compare2++;
            continue;
        };
    }

    return 0;
}

/* Searches the first string and checks if it contains the 
second string. Takes two strings as input and returns a pointer
that points to the first element of the substring, and NULL otherwise*/
char *Str_search(char string[], char substring[]) {
    assert (str1 != NULL);
    assert (str2 != NULL);

    char *slicedString;
    char *temp;
    char *tempCounter;
    char *sliceCounter;
    size_t substringSize;
    size_t stringSize;
    int compare;

    substringSize = Str_getlength(substring);
    stringSize = Str_getlength(string);

    if (substringSize == 0) return string;

    *temp = '\0';
    slicedString = string;
    while (*(slicedString + substringSize) != '\0') {
        tempCounter = temp;
        sliceCounter = slicedString;
        while (sliceCounter != (slicedString + substringSize)) {
            *tempCounter = *sliceCounter;
            tempCounter++;
            sliceCounter++;

            if (*sliceCounter == '\0') 
                return NULL;
        }

        compare = Str_compare(temp, substring);
        if (compare == 0) 
            return slicedString;
        else {
            slicedString++;
            continue;
        };
    }
    return NULL;
}
