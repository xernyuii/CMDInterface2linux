#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include "../include/line.h"

int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    char* srcname = lines[1];
    char* dstname = lines[2];
    char option[5];

    FILE *src, *dst;
    // 判断dst是否存在
    if(!access(dstname, 0)) {
        // 如果存在,询问是否覆盖
        while(1) {
            printf("覆盖 %s 吗?(Yes/No/All):", dstname);
            scanf("%s", option);
            if(strcmp("No", option) == 0) {
                printf("已复制 0 个文件\n");
                return 0;
            } 
            else if(strcmp("Yes", option) == 0) {
                break;
            }
        }
    }
    // 开始复制文件
    src = fopen(srcname, "rb");
    dst = fopen(dstname, "wb");
    int bufferLen = 1024;
    int readCount = 0;
    char *buffer = (char*)malloc(bufferLen);
    while((readCount=fread(buffer, 1, bufferLen, src)) > 0) {
        fwrite(buffer, readCount, 1, dst);
    }
    printf("已复制 1 个文件\n");
    // 释放内存关闭文件
    free(buffer);
    fclose(src);
    fclose(dst);
    return 0;
}