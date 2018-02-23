#include <time.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	time_t rawtime; 
	struct tm* timeinfo; 
	time(&rawtime); 
	timeinfo = localtime(&rawtime); 
	printf( "The current date/time is: %s", asctime(timeinfo) ); 
	return 0;
}