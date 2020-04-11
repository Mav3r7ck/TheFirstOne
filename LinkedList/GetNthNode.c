#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct N{
	int data;
	struct N* next;
}node;

typedef struct ret{
	int ret_status;
	char ret_message[20];
	int ret_val;
}ret;

void printList(node*);
ret* GetNthNode(node*, int);

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
	printf("\nEnter the position of the node: ");
	int pos;
	scanf("%d", &pos);
	ret* p = GetNthNode(head, pos);
	printf("%s, %d", p->ret_message, p->ret_val);
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

ret* GetNthNode(node* head, int pos){
	ret* temp = NULL;
	temp = (ret*)malloc(sizeof(ret));
	while((head != NULL) && (pos != 0)){
		if(--pos == 0){
			temp->ret_status = 1;
			strcpy(temp->ret_message, "Value exists");
			temp->ret_val = head->data;
			return temp;
		}
		head = head->next;
	}
	temp->ret_status = 0;
	strcpy(temp->ret_message, "Value doesn't exist");
	temp->ret_val = -1;
}
