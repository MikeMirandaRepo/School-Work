#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include "bmatch.h"

struct Node {
	char *data;
	struct Node *next;
};

void insertAtStart(struct Node **start_ref, char *data);
void bubbleSort(struct Node *start);
void printList(struct Node *start);

int main(int argc, char *argv[]) {
	clock_t start_time, stop_time;
	double total_time;
	start_time = clock();
	const char *filename = "./ANNA_KARENINA.txt";
	if(argc > 1)
		filename = argv[1];
	
	FILE *fp =  fopen(filename, "r");
	char *word;
	if(argc > 2)
		word = argv[2];
	if(fp == NULL)
		printf("Failed to open file %s for reading\n", filename);

	char buf[300];
	char buf2[300];
	char str[300];
	bool get = true;
	
	struct Node *start = NULL;
	char tempStr[300];
	
	int fd[2];
	int fd2[2];
	pipe(fd2);
	pipe(fd);
	pid_t pid;
	pid = fork();
	do {
	if(pid<0) {
		perror("fork failed");
		exit(1);
	}
	if(pid == 0) {
		//this is the child
		close(fd[1]);
		read(fd[0], buf, sizeof(buf));
		close(fd2[0]);
		if(match(buf,word)) {
			write(fd2[1],buf,sizeof(buf));
		} else {
			write(fd2[1],"",1);
		}
	} else {
		//parent will open file, read file, pass to child, and output lines in alphabetical order
		//This is the parent
		char str[300];
		get = (fgets (str, sizeof str,fp) != NULL);
		close(fd[0]);
		write(fd[1], str, sizeof(str));
		close(fd2[1]);
		read(fd2[0], buf2, sizeof(buf2));
		if(strcmp(buf2,"")==0) {
		} else {
			if(strcmp(buf2,tempStr)==0) {
			} else {
				insertAtStart(&start,buf2);
				strcpy(tempStr,buf2);
			}
		}

	}
} while(get);
	
	fclose(fp);
	bubbleSort(start);
	printList(start);
	stop_time = clock();
	total_time = ((double) (stop_time-start_time))/CLOCKS_PER_SEC;
	printf("\nthe total seconds taken: %f\n", total_time);
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
