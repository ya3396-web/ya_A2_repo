/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: ???                                                        */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,  
                              const char *pcFrom, const char *pcTo)
{
   const char *tempPrint;
   const char *tempFind;
   size_t fromSize;
   size_t totalReplacements;

   assert (pcLine != NULL);
   assert (pcFrom != NULL);
   assert (pcTo != NULL);

   /* returns 0 because fromSize is empty */
   fromSize = Str_getlength(pcFrom);
   if (fromSize == 0) {
      printf("%s", pcLine);
      return 0;
   }

   /* the rest of the code assumes that fromSize is not empty,
   even if it doesn't exist in pcLine */
   totalReplacements = 0;
   tempPrint = pcLine;
   
   while (*tempPrint != '\0') {
      /* first finding the start of the substring in pcLine*/
      tempFind = Str_search(tempPrint, pcFrom);

      /* NULL means the substring isn't in pcLine*/
      if (tempFind == NULL) {
         printf("%s", tempPrint);
         return totalReplacements; /* just returns zero */
      }

      /* not NULL means we've found the substring */
      totalReplacements++;
      while (tempPrint != tempFind) {
         /* printing character by character until we reach it */
         putchar(*tempPrint);
         tempPrint++;
      }

      /* replacing pcFrom simply means printing pcTo and skipping
      fromSize ahead in pcLine*/
      printf("%s", pcTo);
      tempPrint += fromSize;

      /* repeats the whole loop starting from the character next to
      pcFrom */
   }

   return totalReplacements;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   size_t pcFromCapacity;
   char *pcTo;
   size_t pcToCapacity;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL)
      uReplaceCount += replaceAndWrite(acLine, (const char *) pcFrom, 
                                       (const char*) pcTo);

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
