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
    else if(lines[1][strlen(lines[1])-1]!='/'){
        strcat(lines[1],"/");
    }
    //printf("hi2\n");
    if((fd=opendir(lines[1]))==NULL){
        perror("fail!");
        exit(0);
    }
    //printf("%s\n", temp);
    printf("%s 目录\n", lines[1]);
    int file_num=0;
    int dir_num=0;
    long long file_size=0;
    long long dir_size=0;
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

        printf("%.12s ", 4 + ctime(&buf.st_mtime));
        if(strcmp(fp->d_name,".")==0 || strcmp(fp->d_name,"..")==0){
            printf("        <DIR>");
            dir_num++;
            dir_size+=buf.st_size;
        }
        else{
            printf("\t%10lld", buf.st_size);
            file_num++;
            file_size+=buf.st_size;
        }
            
        printf("   %s\n", fp->d_name);

    }
    printf("%12d 个文件 %12lld 字节\n",file_num,file_size);
    printf("%12d 个目录 %12lld 字节\n",dir_num,dir_size);
    return 0;
}