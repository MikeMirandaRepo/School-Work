#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "hfunc.h"
using namespace std;
#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while(0)
	
int
main(int argc, char **argv) {
	clock_t time, timeP;
	time = clock();
	timeP = clock();
	char* filename = "temp.txt";
	if (argc > 1)
		filename = argv[1];
	int SIZE = 26;
	int values[SIZE];
	for (int i = 0; i < SIZE; i++)
		values[i] = 0;
	char *addr;
	int fd;
	int size;
	struct stat sb;

	fd = open(filename, O_RDONLY);
	if (fd == 1)
		handle_error("open");
	
	if (fstat(fd, &sb) == -1)
		handle_error("fstat");
	
	int status = fstat(fd, &sb);
	size = sb.st_size;

	addr = static_cast<char*>(mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0));
	if(addr == MAP_FAILED)
		handle_error("mmap");

	for (int i = 0; i < size; i++) {
		int temp = analyzeCharacter(addr[i]);
		if (temp != -1)
			values[temp] += 1;
	}
	time = clock() - time;
	printResults(values);
	timeP = clock() - timeP;
	
	cout << "The time w/o printing was: " << (float)time/CLOCKS_PER_SEC <<  
	" and w printing was: " << (float)timeP/CLOCKS_PER_SEC << 
	" and the difference was: " << (float)(timeP-time)/CLOCKS_PER_SEC << endl; 
exit(EXIT_SUCCESS);
}
	
