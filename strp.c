#include "str.h"
#include <stddef.h>
#include <assert.h>

/* Returns how many characters are in the given string 
(excludes '\0'). Takes an array or pointer as input and 
returns a size_t value.*/
size_t Str_getlength(const char str[]){
    const char *current;
    int j;

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
char *Str_copy(char str1[], size_t capacityStr1, const char str2[]) {

    const char *current;
    char *copy;
    size_t sizeStr2;

    assert (str1 != NULL);
    assert (str2 != NULL);

    sizeStr2 = Str_getlength(str2);
    assert (sizeStr2 < capacityStr1);
    
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
char *Str_concat(char str1[], size_t capacityStr1, const char str2[]) {
    size_t size1;
    size_t size2;
    char *current;
    const char *cat;

    assert (str1 != NULL);
    assert (str2 != NULL);

    size1 = Str_getlength(str1);
    size2 = Str_getlength(str2);
    assert(capacityStr1 > size1);
    assert(size2 < capacityStr1 - size1);

    current = str1;
    while (*current != '\0') current++;


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

    compare1 = str1;
    compare2 = str2;

    while ((*compare1 != '\0') && (*compare2 != '\0')) {
        if (*compare1 < *compare2) return -1;
        else if (*compare1 > *compare2) return 1;
        else {
            compare1++;
            compare2++;
            continue;
        }
    }

    if ((*compare1 == '\0') && (*compare2 == '\0'))
        return 0;

    if (*compare1 == '\0') return -1;
    return 1;
}

/* Searches the first string and checks if it contains the 
second string. Takes two strings as input and returns a pointer
that points to the first element of the substring, and NULL otherwise*/
char *Str_search(char string[], const char substring[]) {
    char *stringPos;
    const char *subTemp;
    char *temp;
    size_t position;
    size_t substringSize;
    size_t stringSize;
    
    assert (string != NULL);
    assert (substring != NULL);

    substringSize = Str_getlength(substring);
    stringSize = Str_getlength(string);

    if (substringSize == 0) 
        return string;

    if (stringSize < substringSize)
        return NULL;

    for (position = 0; position <= stringSize - substringSize; position++) {
        stringPos = string + position;
        temp = stringPos;
        subTemp = substring;

        while (*subTemp != '\0' && *temp == *subTemp) {
            temp++;
            subTemp++;
        }

        if (*subTemp == '\0')
            return stringPos;
        }
    
    return NULL;
}
