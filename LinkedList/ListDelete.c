#include<stdio.h>
#include<stdlib.h>

typedef struct N{
	int data;
	struct N* next;
}node;

void printList(node* head);
void DeleteNode(node* head, int n_data);
void DeleteNodeAtPosition(node* head, int n_data);
void DeleteList(node* head);
	

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
	
	printf("\nSelect how you want to delete a node:\n1. Delete a node by passing the value at node.\n2. Delete a node by passing its position.\n3. Delete entire linked list.\n");
	int c;
	scanf("%d", &c);
	if(c == 1 || c == 2){
		printf("Enter the value or position to be deleted from the list: ");
		int n_data;
		scanf("%d", &n_data);
		if(c == 1)
			DeleteNode(head, n_data);
		else if(c==2)
			DeleteNodeAtPosition(head, n_data);
	}
	else if(c == 3)
		DeleteList(head);
}

void printList(node* head){
	if(head == NULL){
		printf("The linked list is empty.");
		return;
	}
	printf("\nThe linked list is as follows:\n");
	node* a = head;
	while(a != NULL){
		printf("%d -> ", a->data);
		a = a->next;
	}
	printf("NULL\n");
}

void DeleteNode(node* head, int n_data){
	node* a = head; 
	//If head is the node to be deleted...
	if(a->data == n_data){
		head = a->next;
		free(a);
	}
	else{
		node* prev;
		while((a != NULL) && (a->data != n_data)){
			prev = a;
			a = a->next;
		}
		if(a == NULL){
			printf("Node is not present in the list.\n");
			return;
		}
		prev->next = a->next;
		free(a);
	}
	printList(head);
}

void DeleteNodeAtPosition(node* head, int n_data){
	//Not used here, as empty linked list is not allowed to be created.
	/*
	if(head == NULL){
		printf("\nLinked list is empty.");
		return;
	}
	*/
	node* a = head;
	if(n_data == 0){
		head = a->next;
		free(a);
	}
	else{
		node* prev;
		while(n_data != 0){
			prev = a;
			a = a->next;
			n_data--;
		}
		prev->next = a->next;
		free(a);
	}
	printList(head);
}

void DeleteList(node* head){
	node* a;
	while(head != NULL){
		a = head;
		head = head->next;
		free(a);
	}
	printList(head);
}

