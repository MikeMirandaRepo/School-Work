#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "bmatch.h"
#include <sys/mman.h>


struct Node {
	char *data;
	struct Node *next;
};

void insertAtStart(struct Node **start_ref, char *data);
void bubbleSort(struct Node *start);
void printList(struct Node *start);
void error_exit(const char *msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
	const char *filename = "./ANNA_KARENINA.txt";
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
	char buf[300];
	char buf2[300];
	
	struct Node *start = NULL;
	char tempStr[300];
	
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

	fgets(str, sizeof str, fp);
	puts(*str);
	
	close(fd);
	/*
	pid_t pid;
	pid = fork();
	do {
	if(pid<0) {
		perror("fork failed");
		exit(1);
	}
	if(pid == 0) {
		//child
		//read from str in parent and store it into buf
		if(match(buf,word)) {
			//write buf to somewhere parent can access
		} else {
			//write "" to same place as above
		}
	} else {
		//parent
		char str[300];
		get = (fgets (str, sizeof str,fp) != NULL);
		//store str into something that child can access
		//read from smem stuff from child into buf2
		if(strcmp(buf2,"")==0) {
		} else {
			if(strcmp(buf2,tempStr)==0) {
			} else {
				insertAtStart(&start,buf2);
				strcpy(tempStr,buf2);
				}
			}
		}

	} 
	*///while(get);
	r = munmap(ptr, region_size);
	if (r != 0)
		error_exit("munmap");
	r = shm_unlink(memname);
	if (r != 0)
		error_exit("shm_unlink");
	
	fclose(fp);
	bubbleSort(start);
	printList(start);
	return 0;
}
void insertAtStart(struct Node **start_ref, char *datastr) {
	struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node));
	char *val=malloc((strlen(datastr)+1)*1);
	strcpy(val,datastr);
	ptr1->data = val;
	ptr1->next = *start_ref;
	*start_ref = ptr1;
}
void printList(struct Node *start) {
	struct Node *temp = start;
	printf("Printing List:\n");
	while(temp!=NULL) {
		printf("%s", temp->data);
		temp = temp->next;
	}
}
void bubbleSort(struct Node *start) {
	int swapped;
	struct Node *otherPtr = NULL;
	struct Node *myPtr;
	if (start == NULL)
		return;
	do {
		swapped = 0;
		myPtr = start;
		while (myPtr->next != otherPtr) {
			if(strcmp(myPtr->data,myPtr->next->data) > 0) {
				char *temp = myPtr->data;
				myPtr->data = myPtr->next->data;
				myPtr->next->data = temp;
				swapped = 1;
			}
			myPtr = myPtr->next;
		}
		otherPtr = myPtr;
	}
	while(swapped);
}
