#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct N{
	int data;
	struct N* next;
}node;

void printList(node* head);
int ListLength(node*);
void GetMiddeNode1(node*);
void GetMiddleNode2(node*);

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
	
	GetMiddleNode1(head);
	GetMiddleNode2(head);
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

void GetMiddleNode1(node* head){
	int req_len = ceil((ListLength(head))/2);
	while(req_len != 0){
		head = head->next;
		req_len--;
	}
	printf("\nMiddle node is: %d", head->data);
}

void GetMiddleNode2(node* head){
	node* temp = head;
	while((temp != NULL) && (temp->next != NULL)){
		head = head->next;
		temp = temp->next->next;
	}
	printf("\nMiddle node is(2nd method): %d", head->data);
}
