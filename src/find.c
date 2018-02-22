#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include "../include/line.h"

int main(int argc, char** argv)
{
	char lines[argc+1][255];
    predealLine(argc, argv, lines);
    char* findstr = lines[1];
   	char* filename = lines[2];
   	char fileline[1024]; 
   	int linecnt = 1;
   	FILE *src = fopen(filename, "r");
   	while(!feof(src)) {
   		fgets(fileline, 1024, src);
   		if(strstr(fileline, findstr) != NULL) {
   			printf("[%d]%s", linecnt, fileline);
   		}
   		linecnt++;
   	}
   	printf("\n");
	return 0;
}