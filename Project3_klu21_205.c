#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

#include "orderList_klu21_205.h"


typedef struct _robotOrder{
	unsigned char robotNum;
	orderList *data; 
	char *deliverTo; 
	char *restaurant; 
	struct _robotOrder *next; 
} robotOrder;

robotOrder *insertRobotNode(robotOrder *); 
robotOrder *createNode(); 
void printRobotOrder(robotOrder *); 
void deleteRobotOrder(robotOrder *); 

int main(){
	char inBuf[5];
	robotOrder *head=NULL;
	printf("Size of\n"); 

	//SIZE OF FILE TESTERprintf("foodNode: %zu, orderList: %zu robotOrder: %zu\n", sizeof(foodNode), sizeof(orderList), sizeof(robotOrder));  

	do{
		printf("New Delivery Order? (y/n) ");  
		fgets(inBuf, 5, stdin);
		if(strcmp(inBuf, "n\n")==0){
			continue;
		}
		sscanf(inBuf, "%[^\n]", inBuf); 
		if(strcmpi(inBuf, "y")==0){
			head = insertRobotNode(head); 
		}else{
			printf("Error. Invalid input: %s \n",inBuf); 	
		}
	}while(strcmp(inBuf, "n\n") != 0);
	//printf("check");
	if(head!=NULL){
		printf("\nList of Delivery Orders:\n"); 
		printRobotOrder(head); 
		deleteRobotOrder(head);
 	}
	return 0;
}

robotOrder *insertRobotNode(robotOrder *head){
	if(head == NULL){
		head = createNode(); 	
		return head; 	
	}else{
		robotOrder *temp = createNode(); 
		(temp->next)=head; 
		return temp; 
	}	
}

robotOrder *createNode(){
	robotOrder *temp = (robotOrder*) dcalloc(1,sizeof(robotOrder));
	char inBuf[50];// *str; 

	//Robot Number Assignement. 
	printf("\n\nTask Robot Number: "); 
	fgets(inBuf, 50, stdin); 
	sscanf(inBuf, "%d", &temp->robotNum); 

	//Delievery Address String assignement. 
	printf("Delivery Address for new delivery order: "); 
	fgets(inBuf, 50, stdin); 
 	sscanf(inBuf, "%[^\n]", inBuf);
	(temp->deliverTo)= stringcopy(inBuf); 

	//Restaurant Address Assignment. 
	printf("Restaruant from which to pick up from: "); 
	fgets(inBuf, 50, stdin); 
	sscanf(inBuf, "%[^\n]", inBuf);
	(temp->restaurant) = stringcopy(inBuf);  
	
	//Food Items addition. 
	orderList *list = createItem(); 
	do{
		printf("Food item: ");
		fgets(inBuf, 50, stdin);
		if(strcmp(inBuf,"\n") == 0){
			continue; 
		}
		sscanf(inBuf,"%[^\n]", inBuf);  
		char *copy = stringcopy(inBuf); 	
		if(insert(copy, list)==1){
			printf("Food insertion error.\n"); 
			free(copy); 
		}
	}while(strcmpi(inBuf, "\n")!=0);
	(temp->data)= list;
	printf("\n"); 

	return temp;  
}

void printRobotOrder(robotOrder *curr){
	//Print the receipt order.
	printf("\nRobot %d: Delivery Order from %s has %d food item(s).\n",curr->robotNum, (curr->restaurant), (curr->data)->count);
	printItems(curr->data); 
	printf("Deliver to: %s\n", (curr->deliverTo));
	
	printf("\n");  
	if(curr->next != NULL){
		printRobotOrder(curr->next); 
	}
}

void deleteRobotOrder(robotOrder *curr){
	if((curr->next)!=NULL){
		deleteRobotOrder((curr->next)); 
	}

	(curr ->next) = NULL;
	deleteOrderList(curr->data); 
	//curr->data = NULL; 
	free(curr->deliverTo);
	//curr->deliverTo=NULL; 
	free(curr->restaurant); 
	//curr->restaurant = NULL; 
	free(curr); 
	curr = NULL; 
	return; 		
}
