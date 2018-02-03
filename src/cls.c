#include<stdio.h>
#include "../include/line.h"

int main(int argc, char*argv[]){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);

    if(strcmp(lines[0], "cls")==0){
        printf("\033[2J");
    }
    else{
        printf("sytax error!");
    }

    return 0;
}