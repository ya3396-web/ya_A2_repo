/* stra.c ---- Author: Yoftahe Abate
Implementation of the standard C library using arrays
for implementation and str.h as a blueprint */
#include "str.h"
#include <assert.h>
#include <stddef.h>

/* Returns how many characters are in the given string 
(excludes '\0'). Takes an array or pointer as input and 
returns a size_t value.*/
size_t Str_getLength(int str[]){
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    assert(str != NULL);

    while (str[j++] != '\0') {
        i++;
    }

    return i;
}

/* Copies the characters in the second argument into the first.
Takes two strings as arguments and returns a pointer 
that points at the first element of the copied string.*/
int *Str_copy(int str1[], int str2[]) {
    size_t i;
    size_t size2;

    assert(str1 != NULL);
    assert(str2 != NULL);
    
    for (i = 0; ; i++) {
        str1[i] = str2[i];
        if (str2[i] == '\0')
            break;
    }

    return str1;
}

/* Grafts the characters of the second argument onto the end of
first argument. Takes two strings as arguments, and returns a 
pointer to the first element of the final array.*/
int *Str_concat(int str1[], int str2[]) {
    size_t i;
    size_t size2;
    size_t size1;

    assert (str1 != NULL);
    assert (str2 != NULL);

    size1 = Str_getlength(str1);
    size2 = Str_getlength(str2);

    for (i = 0; str2[i] != '\0'; i++) {
        str1[i + size1] = str2[i];
    }

    /* making sure that the final string ends with '\0' */
    str1[size1 + size2] = '\0';
    return str1;
}

/* Lexicographically compares the two given strings. Takes
two strings as input. Returns 1 if str1 is more than str2, 
returns -1 if str1 is less than str2, and 0 if they're equal.
*/
int Str_compare(int str1[], int str2[]) {
    size_t i;

    assert (str1 != NULL);
    assert (str2 != NULL);

    /* going character by character and checking equality */
    for (i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++) {
        if (str1[i] < str2[i]) return -1;
        else if (str1[i] > str2[i]) return 1;
        else continue;
    }

    /* one string could be longer than the other so here
    we're checking if they're the same length */
    if ((str1[i] == '\0') && (str2[i] == '\0'))
        return 0;
    
    /* otherwise, one of them has ended, and we return 1 or -1 
    for the shorter one */
    return str1[i] < str2[i] ? -1 : 1;
}

/* Searches the first string and checks if it contains the 
second string. Takes two strings as input and returns a pointer
that points to the first element of the substring, and NULL otherwise*/
int *Str_search(int string[], int substring[]) {
    size_t i;
    size_t j;
    size_t size1;
    size_t size2;

    assert(string != NULL);
    assert(substring != NULL);

    size1 = Str_getlength(string);
    size2 = Str_getlength(substring);

    /* returning the string if str2 is just the '\0' character*/
    if (size2 == 0)
        return string;

    /* it doesn't make sense if the substring is bigger than
    the main string */
    if (size2 > size1)
        return NULL;

    /* going character by character until we either get an inequality
    or the substring pointer reaches the end*/
    for (i = 0; i <= size1 - size2; i++) {
        for (j = 0; j < size2; j++) {
            if (string[i + j] != substring[j])
                break;
        }

        /* the substring pointer reaching the end means that we have
        found the substring in the main string so we return the pointer
        at that position */
        if (j == size2)
            return &string[i];
    }

    /* Returning NULL means we didn't find the substring in 
    the main string*/
    return NULL;
}

int main(void) {

}

