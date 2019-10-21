#include <stdlib.h>
#include <assert.h>
#include "llist.h"

llist_t* llalloc(int val) {
    llist_t *head = malloc(sizeof *head);
    assert(head != NULL);
    head->val = val;
    head->next = NULL;
    
    return head;
}

llist_t* copy(llist_t* lst) {	
     llist_t *newlst = llalloc(lst->val);		//head of the list
     llist_t *current = newlst;				//iterator of the list
     int block = 0;				
     llist_t *blockVal = (llist_t *) tort_hare(lst)->proof;		//records the starting point of the loop
     lst = lst->next;
		while(block < 2){
		if(lst == blockVal)			//increments the counter when finding the loop start
			block += 1;

		llist_t *new = llalloc(lst->val); 	//makes a new node with the arr[index] element as val
		if(newlst->next == NULL){		//if the start of the list, make the head->next the next node and iterate on the copy list
			newlst->next = new;
			current = new;
			lst = lst->next;
		}else if(block < 2){			//makes sure that the list stops adding upon the second ecounter of the loop start
			current->next = new;
			current = new;
			lst = lst->next; 
		}
	
	}
/*	for(int i = 0; i < 10; i++){			//printer for error checking
	printf("%d \n", newlst->val);
	newlst = newlst->next;
	}*/		
	return newlst;
}

llist_t* convert(unsigned int* arr, unsigned int size){
    llist_t *head = llalloc(arr[0]);			//head of the list
    llist_t *current = head;				//iterator for the list
    //llist_t *test = head;
    	for(int i = 1; i < size; i++){
	llist_t *new = llalloc(arr[i]);
		if(head->next == NULL){			//if the head is the only element, make the new the second
		head->next = new;
		current = new;
		}
		else{					//link new to the prev new
		current->next = new;		
		current = new;				//make the iterator the tail
		}
	}
	//for(int i = 0; i < size; i++){		//printer for error checking
	//printf("%d ", test->val);
	//test = test->next;
	//}    
	return head;					//return the head of the list
}

proof_t* tort_hare(llist_t *lst){
    llist_t *tort = lst;
    llist_t *hare = lst;
    llist_t *tort2 = lst;
    int index = 0;					//index to record the index of the start of the loop
    proof_t *returnVal = malloc(sizeof *returnVal);
	while(1){
		if(hare->next == NULL){			//if hare reaches the end of the loop, return -1 index and NULL proof
		returnVal->return_val = (int) -1;
		returnVal->proof = NULL;
		return returnVal;
		}
		else{
		hare = hare->next;			//move hare foward 1
		}
		
		if(hare->next == NULL){			//if the hare finds the end of the loop, return -1 and NULL proof
		returnVal->return_val = (int) -1;	
		returnVal->proof = NULL;
		return returnVal;
		}
		else{
		tort = tort->next;			//move hare and tort foward 1
		hare = hare->next;
		}
		if(tort == hare){			//if tort and hare are ever at the same place, record the pos for proof
		returnVal->proof = tort;
		while(tort != tort2){			//to find the start of the loop, tort2 starts at head and tort starts from the same pos as hare/tort meeting
			tort = tort->next;
			tort2 = tort2->next;
			index++;
		}
		returnVal->return_val = tort2->val; 	//**********This is the value of the index of the start of the loop *************
		//returnVal->return_val = index; 	//***********this is the index of the start of the loop ************* did not know which to return
		return returnVal;
		}
	}    
    return returnVal;
//change return val to the index the tort and hare meet, and in reverse the actual start of the cycle 
}
proof_t* rev_cycle(llist_t *lst, int num){		//does not work
    proof_t *returnProof = malloc(sizeof *returnProof);	
	int index = 0;
	llist_t *current = lst;	
	llist_t *prev = NULL;
	llist_t *next = NULL;
	for(int i = 0; i < num; i++){
		returnProof->proof[i] = current->val;
		current = current->next;
	}
	current = lst;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		index++;
	}
	returnProof->return_val = index;
	return returnProof;
}

