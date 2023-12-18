#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 25

int main(void) {
   FILE* fPtr = fopen("nums.txt", "w");

   srand(time(NULL));

   for (size_t i = 0; i < MAX; i++) {
       fprintf(fPtr, "%d\n", rand());
   }

   printf("1000 Random Numbers Generated.");
   exit(EXIT_SUCCESS);
}
