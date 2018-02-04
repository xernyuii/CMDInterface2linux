#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>  
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <regex.h>
#include "../include/line.h"
#include <grp.h>  
#include <pwd.h>
#include <fcntl.h>  
#include <stdlib.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char**argv){
    
    char lines[argc+1][255];
    predealLine(argc, argv, lines);

    DIR* fd;
    struct dirent* fp;
    struct stat buf;
    char temp[255];

    if(strcmp(lines[1], "")==0){
        strcpy(lines[1], "./");
        //printf("hi\n");
    }
    //printf("hi2\n");
    if((fd=opendir(lines[1]))==NULL){
        perror("fail!");
        exit(0);
    }
    while((fp=readdir(fd))!=NULL){
        strcpy(temp, lines[1]);
        //if(strcmp(temp,NULL)==0){
        //    strcpy(temp,"./");
        //}
        
        strcat(temp, fp->d_name);
        if(stat(temp, &buf)==-1){
            perror("stat");
            exit(0);
        }

        printf("\t%.12s ", 4 + ctime(&buf.st_mtime));
        if(strcmp(fp->d_name,".")==0 || strcmp(fp->d_name,"..")==0){
            printf("\t<DIR> ");
        }
        else
            printf("\t%lld", buf.st_size);
        printf("   %s\n", fp->d_name);

    }

    return 0;
}