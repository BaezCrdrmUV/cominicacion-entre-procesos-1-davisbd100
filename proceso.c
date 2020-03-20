#include <stdio.h> 
#include <stdlib.h>

main() {
    char ch;
    FILE *fp;
    printf("Abriendo archivo....\n");
    fp = fopen("test.txt", "r");
    printf("Archivo abierto, leyendo archivo....\n");
    if (fp == NULL){
      perror("Error wabriendo el archivo, saliendo...\n");
      return 1;
    }
   printf("El archivo decia: \n");

   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);
    return 0;
 }