#include <stdio.h>
#include <string.h>
#include <ctype.h>
int predealLine(int argc, char* argv[], char (*lines)[255]){
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
    return 0;
}