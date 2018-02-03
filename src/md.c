#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>  
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <regex.h>
#include "../include/line.h"



int main(int argc, char* argv[]){
    char lines[argc+2][255];

    predealLine(argc, argv, lines);

    if(strcmp(lines[0],"md")==0||strcmp(lines[0],"mkdir")==0){
        for(int i=1;i<argc;i++){
            if(access(lines[i],R_OK)){
                //printf("\n!\n");
                char cm[255]="./";
                strcat(cm, lines[i]);
                mkdir(lines[i],S_IRWXU|S_IRGRP|S_IROTH);
            }
            else{
                printf("%s: ", lines[0]);
                printf("cannot create directory: %s :", lines[i]);
                printf("File exists or Permission denied!\n");
            }
        }
    }
    else{
        printf("%s: ", lines[0]);
        printf("sytax error!\n");
    }

    return 0;
}