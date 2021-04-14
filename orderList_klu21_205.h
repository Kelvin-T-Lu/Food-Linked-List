#ifndef  ORDERLIST_H
#define ORDERLIST_H

typedef struct _foodNode{
	char *data;//Food Item Name
	struct _foodNode *next;
} foodNode;

typedef struct _orderList{
	foodNode *head;
	int count; 
} orderList;


orderList *createItem();
int insert(char *str, orderList *s);
void printItems(orderList *s); 
void *dcalloc(int,size_t);
int strcmpi(char *, char *);
void deleteOrderList(orderList *); 
char *stringcopy(char *s); 

#endif
