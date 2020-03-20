#include <stdio.h> 
#include <string.h> 

main() {
    char ch;
    FILE *fp;
    printf("Abriendo archivo....\n");
    fp = fopen("test.txt", "r");
    printf("Archivo abierto, leyendo archivo....\n");
    if (fp == NULL){
      perror("Error abriendo el archivo, saliendo...\n");
      return 1;
    }
   printf("El archivo decia: \n");

   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);
    //   if( getrlimit(RLIMIT_NOFILE, &old_lim) == 0) 
    //     printf("Old limits -> soft limit= %ld \t"
    //        " hard limit= %ld \n", old_lim.rlim_cur,  
    //                              old_lim.rlim_max); 
    // else
    //     fprintf(stderr, "%s\n", strerror(errno)); 

    printf("\n Obteniendo variables de entorno...\n");
    const char* environment = getenv("PATH");
    printf("PATH :%s\n",(environment!=NULL)? environment : "getenv returned NULL");
    return 0;
 }