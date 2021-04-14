#include <stdlib.h>
#include <stdio.h> 
#include <string.h> 
#include <ctype.h>

#include "orderList_klu21_205.h"

foodNode *locate(foodNode*, char *); 
void deleteFoodNode(foodNode *curr); 
void printFoodNode(foodNode *curr); 

orderList *createItem(){
	orderList *temp = (orderList *) dcalloc(1, sizeof(orderList)); 
	temp-> count = 0;  
	return temp;  
}

int insert(char *str, orderList *s){
	foodNode *newNode = (foodNode *) dcalloc(1,sizeof(foodNode)); 
	(newNode -> data)= str;
	int count = (s->count); 

	if(count == 0){ //Empty List
		(s->head) = newNode;
		(s->count)++;  
		return 0; 
	}
	foodNode *head = (s-> head);
	
	if(strcmpi(str, (head->data))<0){//Insertion before head.
		(newNode->next) = head; 
		(s->head) = newNode;
		(s->count)++;
		return 0;
	}
	if(count ==1){//Single element list
		if(strcmpi(str, (head->data)) == 0){ //Duplicates element
			return 1; 
		}else{//Appends
			(head->next) = newNode; 
			(s->count)++;
			return 0; 	
		}
	}else{
		foodNode *prev = locate(head, str); 
		if(prev == NULL){//Appends
			while((head->next)!=NULL){
				head = (head->next);
			}
			(head->next)=newNode; 
			(s->count)++;
			return 0;
		}else if(strcmpi(str, (prev->next)->data)==0){//Duplicates.
				return 1; 
		}else{//Middle indexes.
			(newNode->next)= (prev->next); 
			(prev->next) = newNode;
			(s->count)++;
			return 0; 
		}
	}
}

void printItems(orderList *s){
	printFoodNode(s->head); 
}

void deleteOrderList(orderList *s){
	deleteFoodNode(s->head);
	(s->head) = NULL;
	free(s);
	s=NULL;  
}
void *dcalloc(int i, size_t size){
	void *p = calloc(i, size); 
	if(!p){
		printf("Memory Allocation Error.\n"); 
		exit(1); 
	}
	return p; 

}

int strcmpi(char *s, char *t){
	while(*s && tolower(*s) == tolower(*t)){
		s++;
		t++;
	}
	return tolower(*s) - tolower(*t); 
}

char *stringcopy(char *s){
	char *temp = (char *) dcalloc(strlen(s)+1, sizeof(char)); 	
	strncpy(temp, s, strlen(s));
	return temp; 

}

foodNode *locate(foodNode *current, char *data){
	if(strcmpi((current->next)->data,data) >= 0){
		return (current); 
	} else{
		if((current->next)->next ==NULL){
			return (NULL);
		}else{
			current = locate(current->next, data); 
		}
	}
	return (current); 
}
void printFoodNode(foodNode *curr){
	printf("\t%s\n", (curr->data));
	if(curr->next != NULL){
		printFoodNode(curr->next); 
	}
}

void deleteFoodNode(foodNode *head){
	if(head->next != NULL){
		deleteFoodNode(head-> next); 
	}
	head->next = NULL;
	free(head->data);
	head->data = NULL; 
 	free(head);
	head = NULL; 
	return;  	
}
