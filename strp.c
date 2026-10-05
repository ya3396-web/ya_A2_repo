/* strp.c ----- Author: Yoftahe Abate
Implementation of the standard C library using pointers
for implementation and str.h as a blueprint */
#include "str.h"
#include <stddef.h>
#include <assert.h>

/* Returns how many characters are in the given string 
(excludes '\0'). Takes an array or pointer as input and 
returns a size_t value.*/
size_t Str_getLength(const char str[]){
    const char *current;
    size_t j;

    assert(str != NULL);

    current = str;
    j = 0;

    while (*(current++) != '\0') {
        j++;
    }

    return j;
}

/* Copies the characters in the second argument into the first.
Takes two strings as arguments and returns a pointer 
that points at the first element of the copied string.*/
char *Str_copy(char str1[], const char str2[]) {

    const char *current;
    char *copy;

    assert (str1 != NULL);
    assert (str2 != NULL);
    
    copy = str1;
    current = str2;
    
    for (; ; current++) {
        *copy = *current;
        copy++;

        if (*current == '\0') break;
    }

    return str1;
}

/* Grafts the characters of the second argument onto the end of
first argument. Takes two strings as arguments, and returns a 
pointer to the first element of the final array.*/
char *Str_concat(char str1[], const char str2[]) {
    char *current;
    const char *cat;

    assert (str1 != NULL);
    assert (str2 != NULL);

    /* getting to the end of str1 */
    current = str1;
    while (*current != '\0') current++;

    /* start by replacing the end of str1 with str2, going until the
    '\0' character at the end of str2*/
    for (cat = str2; ; cat++) {
        *current = *cat;
        current++;

        if (*cat == '\0')
            break;
    }

    return str1;
}

/* Lexicographically compares the two given strings. Takes
two strings as input. Returns 1 if str1 is more than str2, 
returns -1 if str1 is less than str2, and 0 if they're equal.
*/
int Str_compare(const char str1[], const char str2[]) {
    const char *compare1;
    const char *compare2;

    assert (str1 != NULL);
    assert (str2 != NULL);

    /* Starting at the beginning of each string and going
    character by character to check if they're the same*/
    compare1 = str1;
    compare2 = str2;

    /* We break out of the loop when we reach the end of 
    one string or both */
    while ((*compare1 != '\0') && (*compare2 != '\0')) {
        if (*compare1 < *compare2) return -1;
        else if (*compare1 > *compare2) return 1;
        else {
            compare1++;
            compare2++;
            continue;
        }
    }

    /* one string could be longer than the other so once
    the loop is done, we check to see if they both end at 
    the same time*/
    if ((*compare1 == '\0') && (*compare2 == '\0'))
        return 0;

    /* Since '\0' is smaller than all other characters,
    we only need to check if the end of the first string is
    smaller than the second*/
    if (*compare1 == '\0') return -1;
    return 1;
}

/* Searches the first string and checks if it contains the 
second string. Takes two strings as input and returns a pointer
that points to the first element of the substring, and NULL otherwise*/
const char *Str_search(const char string[], const char substring[]) {
    const char *stringPos; /* the pointer that we're returning*/
    const char *subTemp;
    const char *temp;
    size_t position;
    size_t substringSize;
    size_t stringSize;
    
    assert (string != NULL);
    assert (substring != NULL);

    substringSize = Str_getLength(substring);
    stringSize = Str_getLength(string);

    if (substringSize == 0) 
        return string;

    /*The substring has to be smaller than the main string that we're
    checking*/
    if (stringSize < substringSize)
        return NULL;

    /* Checks equality character by character */
    for (position = 0; position <= stringSize - substringSize; 
        position++) {
        stringPos = string + position;
        temp = stringPos;
        subTemp = substring;

        while (*subTemp != '\0' && *temp == *subTemp) {
            temp++;
            subTemp++;
        }

        /* Only when we reach the end of the substring will 
        we have found it in the main string*/
        if (*subTemp == '\0')
            return stringPos;
        }
    
    /* Returning NULL means we didn't find the substring in 
    the main string*/
    return NULL;
}
