#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){

   char abc[50][50];

   for (int i = 1; i < argc; i++){
      strcpy(abc[i - 1], argv[i]);
   }

   for (int i = 0; i < argc - 1; ++i){
      for (int j = i + 1; j < argc - 1; ++j){

         char temp[100];
         if (strcmp(abc[i], abc[j]) > 0){
            strcpy(temp, abc[i]);
            strcpy(abc[i], abc[j]);
            strcpy(abc[j], temp);
         }
      }
   }

   for (int i = 0; i < argc - 1; ++i){
      printf("%s\n", abc[i]);
   }
}
