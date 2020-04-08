#include<stdio.h>
#include<stdlib.h>

typedef struct N{
	int data;
	struct N* next;
}node;

void printList(node* head);
void ListLength(node* head);
int ListLengthRec(node* head);

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
	ListLength(head);
	printf("\nLength of linked list is(recursive): %d", ListLengthRec(head));
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

void ListLength(node* head){
	node* a = head;
	int c;
	while(a != NULL){
		a = a->next;
		c++;
	}
	printf("\nLength of linked list is(iterative): %d", c);
}

int ListLengthRec(node* head){
	if(head == NULL)
		return 0;
	head = head->next;
	return 1 + ListLengthRec(head);
}
