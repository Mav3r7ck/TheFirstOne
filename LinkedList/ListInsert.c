#include<stdio.h>
#include<stdlib.h>

typedef struct N{
	int data;
	struct N* next;
}node;

void printList(node* head);
void InsertAtFront(node* head);
void InsertAfterNode(int n_data, node* head);
void InsertAtEnd(node* head);
	

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
	
	//Inserting a node can be done in 3 ways as follows:
	printf("\nSelect where you want to insert a node:\n1. At the front of linked list.\n2. After a given node.\n3. At the end of the linked list.\n\n");
	int c;
	scanf("%d", &c);
	if(c==1)
		InsertAtFront(head);
	else if(c==2){
		int n_data;
		printf("After which node you want to insert a new node?:");
		scanf("%d", &n_data);
		InsertAfterNode(n_data, head);
	}
	else if(c==3)
		InsertAtEnd(head);
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

void InsertAtFront(node* head){
	node* temp = (node*)malloc(sizeof(node));
	printf("Enter the value to be inserted:");
	scanf("%d", &(temp->data));
	temp->next = head;
	head = temp;
	printList(head);
}

void InsertAfterNode(int n_data, node* head){
	node* a = head;
	while((a != NULL) && (a->data != n_data)){
		a = a->next;
	}
	if(a == NULL){
		printf("\nThis node doesn't exist in the list.");
		return;
	}
	node* temp = (node*)malloc(sizeof(node));
	printf("\nEnter the value to be inserted:");
	scanf("%d", &(temp->data));
	temp->next = a->next;
	a->next = temp;
	printList(head);
}

void InsertAtEnd(node* head){
	node* a = head;
	while(a->next != NULL)
		a = a->next;
	node* temp = (node*)malloc(sizeof(node));
	printf("\nEnter the value to be inserted:");
	scanf("%d", &(temp->data));
	a->next = temp;
	temp->next = NULL;
	printList(head);
}
