#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unisted.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "bmatch.h"

void error_exit(const char *msg)
	perror(msg);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
	const char *filename = "./temp.txt";
	if(argc > 1)
		filename = argv[1];
	
	FILE *fp =  fopen(filename, "r");
	char *word;
	if(argc > 2)
		word = argv[2];
	if(fp == NULL)
		printf("Failed to open file %s for reading\n", filename);

	char str[300];
	bool get = true;
	
	//shared memory stuff begins here
	int r;
	const char *memname = "memname";
	const size_t region_size = sysconf(_SC_PAGE_SIZE);
	
	int fd = shm_open(memname, O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (fd == -1)
		error_exit("shm_open");
	
	r = ftruncate(fd, region_size);
	if (r != 0)
		error_exit("ftruncate");

	void *ptr = mmap(0, region_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED)
		error_exit("mmap");
	close(fd);
	
	pid_t pid;
	pid = fork();
	//Array *array;
	//initArray(array);
	do {
	if(pid<0) {
		perror("fork failed");
		exit(1);
	}
	if(pid == 0) {
		//this is the child
		if(match(buf,word)) {
			//push(array, buf);
		} else {
			
		}
	} else {
		//parent will open file, read file, pass to child, and output lines in alphabetical order
		//This is the parent
		char str[300];
		get = (fgets (str, sizeof str,fp) != NULL);
		}
	} while(get);
i	r = munmap(ptr, region_size);
	if (r != 0)
		error_exit("munmap");
	r = shm_unlink(memname);
	if (r != 0)
		error_exit("shm_unlink");

	return 0;
}

