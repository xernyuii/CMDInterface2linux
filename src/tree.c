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

void printf_dir(const char *name, int dept){

}

int tree_dir(const char *dir, int dept){
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
        //printf_dir(dp->d_name,dept);
        // for(int i=0;i<dept;i++){
        //     printf("|  ");
        // }
        // printf("|- %s\n", dir);
    }
    else if(S_ISDIR(dir_stat.st_mode)){
        dirp=opendir(dir);
        while((dp=readdir(dirp))!=NULL){
            if((0==strcmp(".", dp->d_name))||(0==strcmp("..",dp->d_name))) 
                continue;
            
            sprintf(dir_name, "%s/%s", dir, dp->d_name);
            //remove_dir(dir_name);
            for(int i=0;i<dept;i++){
                printf("|  ");
            }
            printf("|- %s\n", dp->d_name);

            tree_dir(dir_name,dept+1);
        }
        closedir(dirp);
    }
    else{
        perror("error here!\n");
    }

    return 0;
}

int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    
    if(argc==1){
        lines[1][0]='.';
    }
    if(strcmp("tree",lines[0])==0){
        printf("%s\n",lines[1]);
        tree_dir(lines[1],0);
    }
    else{
        perror("error after lines\n");
    }

    return 0;
}