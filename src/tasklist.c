#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
 
void travDir(char dir[]);
int printInfo(char d_name[]); 
int isNum(char p_name[]);

int main(int ac,char *av[])
{
    travDir("/proc/");
}
 
void travDir(char dir[])                         
{
    DIR *dirp;
    struct dirent *direntp;
    struct stat infobuf;
 
    if((dirp = opendir(dir)) == NULL) {
        fprintf(stderr, "dir error %s\n", dir);
    }
    else {  
        printf("%s\t%s\t%s\n", "PID", "PPID", "CMD");
        // 遍历/proc目录, 也就是存放所有进程信息的目录
        while((direntp = readdir(dirp)) != NULL) {
            // 判断目录名字是否为纯数字, 如果是, 说明存放的是进程信息
            if((isNum(direntp->d_name)) == 0) {
                printInfo(direntp->d_name);
            }
        }
    }
}
 
int printInfo(char d_name[]) 
{
    FILE *file;
    char dir[1024];
    // 打开stat文件
    sprintf(dir, "%s/%s", "/proc", d_name);
    chdir(dir);
    if((file = fopen("stat", "r")) < 0) {
        printf("can not open the stat file!\n");
        exit(0);  
    }
    // 读取stat文件的信息
    int pid;
    char pname[256];
    char state;
    int ppid;
    while(4 == fscanf(file, "%d %s %c %d\n", &pid, pname, &state, &ppid)) {
        break;
    }
    // 输出
    printf("%d\t%d\t%s\n", pid, ppid, pname);
    fclose(file);
    return 0;
}

int isNum(char p_name[])
{
    int i,len;
    len=strlen(p_name);
    if(len==0) return -1;
    for(i=0;i<len;i++)
        if(p_name[i]<'0' || p_name[i]>'9')
            return -1;
    return 0;
}