#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define FILE_LENGTH 0x100
int firstInt, fd;
void* file_memory;

void doubleNum(void *fileMem){

 sscanf ((char *) fileMem, "%d", &firstInt);
 printf ("value before: %d\n", firstInt);
 sprintf ((char*) fileMem, "%d\n", 2 * firstInt);
}

void printNums(void *fileMem){

 sscanf((char *) fileMem, "%d\n", &firstInt);
 printf("value after double: %d\n",  firstInt);
 //sprintf ((char*) fileMem, "%d\n", firstInt);

}

int main (int argc, char* const argv[])
{

 // Find the first integer, print it out, and double it. 
 // Open the file. 
 fd = open (argv[1], O_RDWR, S_IRUSR | S_IWUSR);

// Create the memory-mapping. 
 file_memory = mmap (0, FILE_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
     close (fd);

    doubleNum(file_memory);
     printNums(file_memory);

     munmap (file_memory, FILE_LENGTH);

 return 0;
}


