#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>  
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]){
    char lines[argc+2][255];

    for(int i=0;i<argc;i++){
        //printf("%s ", argv[i]);
        int real_len=0;
        for(int j=0;j<strlen(argv[i]);j++){
            if(isalpha(argv[i][j])||isdigit(argv[i][j]))
                lines[i][real_len++]=tolower(argv[i][j]);
        }
        lines[i][real_len]='\0';
        //printf("%s ", lines[i]);
    }

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