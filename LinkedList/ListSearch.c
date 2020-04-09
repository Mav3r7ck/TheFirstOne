#include<stdio.h>
#include<stdlib.h>

typedef struct N{
	int data;
	struct N* next;
}node;

void printList(node*);
void ListSearch(node*, int);
void ListSearchRec(node*, int);

	
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
	
	printf("\nEnter the key you wanna search: ");
	int key;
	scanf("%d", &key);
	ListSearch(head, key);
	ListSearchRec(head, key);
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

void ListSearch(node* head, int key){
	node* a = head;
	while(a != NULL){
		if(a->data == key){
			printf("\nKey exists in the linked list.");
			return;
		}
		a = a->next;
	}
	printf("\nKey doesn't exist in the linked list.");
}

void ListSearchRec(node* head, int key){
	if(head == NULL){
		printf("\nKey doesn't exist in the linked list(recursive).");
		return;
	}
	if(head->data == key){
		printf("\nKey exists in the linked list(recursive).");
		return;
	}
	ListSearchRec(head->next, key);
}
