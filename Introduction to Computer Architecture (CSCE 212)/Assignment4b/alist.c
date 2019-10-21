#include <stdlib.h>
#include <assert.h>
#include "alist.h"

alist_t* alalloc(void) {
    alist_t *list = malloc(sizeof *list);
    assert(list != NULL);
    list->size = 0;
    list->len = DEFAULT_LEN;
    list->arr = calloc(DEFAULT_LEN, sizeof(void *));
    //assert(list->arr != NULL);
    if(list->arr == NULL){
	free(list);
	return NULL;
	}

    return list;
}

void push(alist_t* lst, void *item) {
    assert(item != NULL);
    assert(lst != NULL);
    if(lst->size == lst->len){
	alist_t *newlst	= malloc(sizeof *lst);			//make a new list 
 	newlst->len = (lst->size+1)*2;				//set the newlst length = (lst->size+1)*2
	newlst->arr = calloc(newlst->len, sizeof(void *));	//allocate memory for new list
	for(int i = 0; i < lst->size; i++){
		newlst->arr[i] = lst->arr[i];
	}
	free(lst->arr);						//free memory for old array
	newlst->arr[lst->size] = item;
	lst->len = (lst->size+1)*2;				//update the array with the new len and size and add new item
    	lst->size = lst->size + 1;
	lst->arr = newlst->arr;	}

    else{
	lst->arr[lst->size] =  item;				//just add a new item if the size is less than the len
	lst->size += 1;	}

}

void* pop(alist_t *lst){
    assert(lst != NULL);
    void* returnVal = lst->arr[lst->size-1];			//saves the value that is removed to return
    free(lst->arr[lst->size-1]);				//free memory for the removed item
    lst->size--;			
	if(lst->size == (lst->len)/4){				//if the size is less than len/4, make new array with len/2
   	alist_t *newlst	= malloc(sizeof *lst);	
 	newlst->len = (lst->len)/2;
	newlst->arr = calloc(newlst->len, sizeof(void *));
	for(int i = 0; i < lst->size; i++){
		newlst->arr[i] = lst->arr[i];
		}
	free(lst->arr);						//free old array and swap with a new one
	lst->len = (lst->len)/2;
	lst->arr = newlst->arr;		
	}
    return returnVal;						//return item removed
}

void* find(alist_t *lst, bool (*sel)(void*)){
    assert(lst != NULL);
    for(int i = 0; i < lst->size; i++){
	if((*sel)(lst->arr[i]) == 1)				//if the item is found, return that item in array else NULL
		return lst->arr[i];
	}
    return NULL;

}
void map(alist_t *lst, void* (*func)(void*)){
   assert(lst != NULL);
   for(int i = 0; i < lst->size; i++){
	lst->arr[i] = (*func)(lst->arr[i]);			//call map() on each item in the array
	}

}
