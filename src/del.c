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

int remove_dir(const char *dir){
    DIR* dirp;
    struct dirent *dp;
    struct stat dir_stat;
    char dir_name[255];

    if(access(dir,F_OK)!=0){
        return 0;
    } // don't exit
    if(stat(dir, &dir_stat)<0){
        perror("dir stat errpr!\n");
        return -1;
    } //
    if(S_ISREG(dir_stat.st_mode)){
        remove(dir);
    }
    else if(S_ISDIR(dir_stat.st_mode)){
        dirp=opendir(dir);
        while((dp=readdir(dirp))!=NULL){
            if((0==strcmp(".", dp->d_name))||(0==strcmp("..",dp->d_name))) 
                continue;
            
            sprintf(dir_name, "%s/%s", dir, dp->d_name);
            remove_dir(dir_name);
        }
        closedir(dirp);
        rmdir(dir);
    }
    else{
        perror("error here!\n");
    }

    return 0;
}


int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);

    if((strcmp("del",lines[0])==0)||(strcmp("rm",lines[0])==0)){
        remove_dir(lines[1]);
    }
    else{
        perror("error after lines\n");
    }

    return 0;
}