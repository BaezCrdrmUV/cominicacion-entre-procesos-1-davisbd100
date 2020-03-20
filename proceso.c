#include <stdio.h> 
#include <string.h> 
#include <windows.h> 
#include <sys/wait.h>
#include <signal.h>
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
    //   Obtener el numero maximo de FD

    //   if( getrlimit(RLIMIT_NOFILE, &old_lim) == 0) 
    //     printf("Old limits -> soft limit= %ld \t"
    //        " hard limit= %ld \n", old_lim.rlim_cur,  
    //                              old_lim.rlim_max); 
    // else
    //     fprintf(stderr, "%s\n", strerror(errno)); 

    printf("\nObteniendo variables de entorno...\n");
    const char* environment = getenv("PATH");
    printf("PATH :%s\n",(environment!=NULL)? environment : "getenv returned NULL");

    // Crear un nuevo proceso
    
    // printf("Creando un nuevo proceso desde el programa actual...\n");
    // char *args[]={"./Proceso",NULL}; 
    // execvp(args[0],args); 
    // return 0;

    // Bloquear el proceso padre

    // int status;
    // printf("Bifurcando el proceso actual...\n");
    // int pidchild = fork();
    // if( 0 == pidchild)
    // {
    //     printf( "PID del hijo %ld\n", (long)getpid());
    //     exit(1);
    // }
    // else
    // {
    //     printf( "PID del padre: %ld\n", (long)getpid());
    //      printf("Blockeando el proceso padre... \n");
    //     if (wait(&status) >= 0)
    //     {
    //         printf("Proceso hijo termino con status %d \n", WEXITSTATUS(status));
    //     }
    // }
    
    // return 0; 

    // Matar al proceso hijo

        int status;
    printf("Bifurcando el proceso actual...\n");
    int pidchild = fork();
    if( 0 == pidchild)
    {
        printf( "PID del hijo %ld\n", (long)getpid());
        printf("Matando al hijo... \n");
        kill(pidchild, SIGKILL);
        printf("Hijo muerto... \n");
    }
    else
    {
        printf( "PID del padre: %ld\n", (long)getpid());
    }
  
    return 0;

 }