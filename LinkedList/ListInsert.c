#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct N{
	int data;
	struct N* next;
}node;

void printList(node* head);
	

void main(){
	printf("Create a linked list...");
	printf("\nEnter the number of elements to be present in the linked list: ");
	int n, i;
	scanf("%d", &n);
	if(n==0)
		return;
		
	printf("Enter the elememts of the linked list:");
	
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
	printf("The Linked List is as follows:\n");
	printList(head);
}

void printList(struct N* head){
	node* a = head;
	while(a != NULL){
		printf("%d -> ", a->data);
		a = a->next;
	}
	printf("NULL");
}
