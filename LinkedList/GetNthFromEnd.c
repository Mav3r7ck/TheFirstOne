#include<stdio.h>
#include<stdlib.h>

typedef struct N{
	int data;
	struct N* next;
}node;

void printList(node* head);
int ListLength(node*);
void GetNthFromEnd1(node*, int);
void GetNthFromEnd2(node*, int);

void main(){
	printf("Create a linked list...");
	printf("\nEnter the number of elements to be present in the linked list: ");
	int n, i;
	scanf("%d", &n);
	if(n==0)
		return;
		
	printf("Enter the elememts of the linked list:\n");
	
	node* head = NULL;	
	node* temp = NULL;
	node* end = NULL;
	
	for(i=0; i<n; i++){
		temp = (node*)malloc(sizeof(node));
		scanf("%d",&(temp->data));
		temp->next = NULL;
		if(head == NULL)
			head = temp;			
		else{			
			end = head;
			while(end->next != NULL)
				end=end->next;
			end->next = temp;
		}
	}
	
	printList(head);
	
	printf("Enter the position of node from last: ");
	int pos;
	scanf("%d", &pos);
	GetNthFromEnd1(head, pos);
	GetNthFromEnd2(head, pos);
}

void printList(node* head){
	printf("\nThe linked list is as follows:\n");
	node* a = head;
	while(a != NULL){
		printf("%d -> ", a->data);
		a = a->next;
	}
	printf("NULL\n");
}

int ListLength(node* head){
	node* a = head;
	int c;
	while(a != NULL){
		a = a->next;
		c++;
	}
	return c;
}

void GetNthFromEnd1(node* head, int pos){
	int len = ListLength(head);
	if((pos == 0) || (pos > len)){
		printf("\nInput position is not defined for the given linked list.");
		return;
	}
	int i = len-pos+1;
	while(i>1){
		head = head->next;
		i--;
	}
	printf("\nThe %d th node from the end is: %d", pos, head->data);
}

void GetNthFromEnd2(node* head, int pos){
	if(pos == 0){
		printf("\nInput position is not defined for the given linked list(2nd method).");
		return;
	}
	node* temp = head;
	int i = pos;
	while((i != 0) && (temp != NULL)){
		temp = temp->next;
		i--;
	}
	if(temp == NULL){
		printf("\nInput position is not defined for the given linked list(2nd method).");
		return;
	}
	while(temp != NULL){
		temp = temp->next;
		head = head->next;
	}
	
	printf("\nThe %d th node from the end is(2nd method): %d", pos, head->data);
}
