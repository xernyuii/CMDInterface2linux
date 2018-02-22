#include <stdio.h>
#include <stdlib.h>
#include "../include/line.h"

int copyFile(char *fileRead, char *fileWrite);
int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    char* srcname = lines[1];
    char* dstname = lines[2];

    FILE *src, *dst;
    src = fopen(srcname, "rb");
    dst = fopen(dstname, "wb");
    int bufferLen = 1024;
    int readCount = 0;
    char *buffer = (char*)malloc(bufferLen);
    while((readCount=fread(buffer, 1, bufferLen, src)) > 0) {
        fwrite(buffer, readCount, 1, dst);
    }

    free(buffer);
    fclose(src);
    fclose(dst);
    return 0;
}