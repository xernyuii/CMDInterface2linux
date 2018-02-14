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
int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    
    for(int i=1;i<argc;i++){
        printf("%s ", lines[i]);
    }
    printf("\n");

    return 0;
}