#include <stdio.h>
#include <string.h>
#include <unistd.h>  

int main(int argc, char **argv)
{
     FILE *file;
     char buffer[256];
     char *osfilename = "/proc/sys/kernel/ostype";
     char *refilename = "/proc/sys/kernel/osrelease";
     char *kefilename = "/proc/sys/kernel/version";
     file = fopen(osfilename, "r");
     if(file == NULL)
     {
         printf("error to open: %s\n", osfilename);
     }
     fread(buffer, 1, 256, file);
     printf("当前操作系统: %s", buffer);
     file = fopen(refilename, "r");
     if(file == NULL)
     {
         printf("error to open: %s\n", refilename);
     }
     fread(buffer, 1, 256, file);
     printf("当前发行版本: %s", buffer);
     file = fopen(kefilename, "r");
     if(file == NULL)
     {
         printf("error to open: %s\n", kefilename);
     }
     fread(buffer, 1, 256, file);
     printf("当前内核版本: %s", buffer);
     fclose(file);
 }