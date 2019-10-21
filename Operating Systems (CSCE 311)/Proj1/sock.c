#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bmatch.h"

struct Node
{
    char *data;
    struct Node *next;
};
void insertAtStart(struct Node **start_ref, char *data);
void bubbleSort(struct Node *start);
void printList(struct Node *start);

int getFileLength(int w, const char* fileN)
{
        int fileLEN = 0;
        FILE *file2 = fopen ( fileN, "r" );
        if ( file2 != NULL )
        {
                char line [w]; /* or other suitable maximum line size */
                int i = 0;
                while ( fgets ( line, sizeof line, file2 ) != NULL ) /* read a line */
                {
                        fileLEN++;
                }
                fclose ( file2 );
        }
        else
        {
                perror ( fileN ); /* why didn't the file open? */
        }
        return fileLEN;
}
int main(int argc, char **argv)
{
        int fileLength = 0,sendSize = 0,width = 200; // shouldExit = 1; //for shouldExit 0 is true and 1 is false
        const char *filename = "./ANNA_KARENINA.txt";
        char *word = "world";
        struct Node *start = NULL;
        char buf[width];
        char buf2[width];
        char tempStr[width];
        if (argc > 1)
        {
            filename = argv[1];
        }
        if( argc > 2)
        {
            word = argv[2];
        }
        //fileLength = getFileLength(width, filename);
        //printf("FILE LENGTH:%d\n",fileLength);

        int sv[2]; /* the pair of socket descriptors */
        char *str = ""; /* for data exchange between processes */

        if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1)
        {
                perror("socketpair");
                exit(1);
        }
        bool get = true;
        FILE *file = fopen ( filename, "r" );
        if(file == NULL)
        {
		        printf("Failed to open file %s for reading\n", filename);
            exit(0);
        }
        pid_t pid;
        pid = fork();
        while(get)
        {
            if (pid  >= 0)
            {
                if(pid == 0)
                { /* child */
                        //printf("in child\n");
                        int len = fileLength*width;
                        read(sv[1], &buf, sizeof(buf));
                        if(match(buf,word))
                        {
                        			write(sv[1], buf, sizeof(buf));
                        }
                        else
                        {
                        			write(sv[1],"",1);
                        }
                }
                else
                { /* parent */
                        //printf("in parent\n");
                        char line[width];
                        get = (fgets (line, sizeof line,file) != NULL);
                        write(sv[0], line, sizeof(line));
                        read(sv[0], buf2, sizeof(buf2));
                        //at this point buf2 is the string.
                        if(strcmp(buf2,"")==0 ) //if they are equal
                        {
                            //printf("non match line\n");
                        }
                        else
                        {
                            if(strcmp(buf2,tempStr)==0)
                            {
                                //don't add to list.
                            }
                            else
                            {
                                //printf("Adding: %s",buf2);
                                //printf("inserting: %s",buf2);
                                insertAtStart(&start,buf2);
                                strcpy(tempStr,buf2);
                            }

                        }
                } //end of parent else
            }
            else
            {
               printf("fork error\n");
            }
        }
        fclose ( file );
        bubbleSort(start); //sort the LL collected.
        printList(start);
        //printf("Made it out to space?\n");
        return 0;

}
void insertAtStart(struct Node **start_ref, char *datastr)
{
    struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node));
    char *val=malloc((strlen(datastr)+1)*1);
    strcpy(val,datastr);
    ptr1->data = val;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}
void printList(struct Node *start)
{
    struct Node *temp = start;
    printf("Printing List:\n");
    while (temp!=NULL)
    {
        printf("%s", temp->data);
        temp = temp->next;
    }
}
void bubbleSort(struct Node *start)
{
    int swapped;
    struct Node *otherPtr = NULL;
    struct Node *myPtr;
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        myPtr = start;
        while (myPtr->next != otherPtr)
        {
            if (strcmp(myPtr->data,myPtr->next->data) > 0)
            {
                char *temp = myPtr->data;
                myPtr->data = myPtr->next->data;
                myPtr->next->data = temp;
                swapped = 1;
            }
            myPtr = myPtr->next;
        }
        otherPtr = myPtr;
    }
    while (swapped);
}