#include <stdio.h> 
#include <stdlib.h> 

struct StackNode 
{ 
    int data; 
    StackNode* next; 
}; 
  
struct StackNode* newNode(int data) 
{ 
    StackNode* node = new StackNode; 
    node->data = data; 
    node->next = NULL; 
    return node; 
} 
  
int isEmpty(StackNode *head) 
{ 
    return !head; 
} 
  
void push(StackNode** head, int data) 
{ 
    StackNode* node = newNode(data); 
    node->next = *head; 
    *head = node; 
    printf("%d pushed to stack\n", data); 
} 
  
int pop(StackNode** head) 
{ 
    if (isEmpty(*head)){
    	printf ("Stack is empty\n");
		return 0;	
	}  
    StackNode* temp = *head; 
    *head = (*head)->next; 
    int popped = temp->data; 
    free(temp); 
  
    return popped; 
} 
  
int peek(StackNode* head) 
{ 
    if (isEmpty(head)) {
    	printf ("Stack is empty\n");
		return 0;	
	} 
    return head->data; 
} 

void display(StackNode *head) {
	if (isEmpty(head)) {
    	printf ("Stack is empty\n");
		return;	
	}
	StackNode *list = head;
	while(list) {
		printf ("[ %d ]\n", list->data); 
		list = list->next;
	}
}
  
int main() 
{ 
    int choice,option = 1;
	StackNode* head = NULL; 
  
  	printf ("STACK OPERATION\n");
	while (option)
	{
	            printf ("------------------------------------------\n");
	            printf ("      1    -->    PUSH                 \n");
	            printf ("      2    -->    POP                 \n");
	            printf ("      3    -->    DISPLAY                 \n");
	            printf ("      4    -->    PEEK            \n");
				printf ("      5    -->    EXIT            \n");
	            printf ("------------------------------------------\n");
	            printf ("Enter your choice\n");
				scanf ("%d", &choice);
				switch (choice)
				{
					case 1:
						int num;
						printf ("Enter the element to be pushed\n");
						scanf ("%d", &num);
						push(&head, num); 
						break;
					case 2:
						pop(&head);
						break;
					case 3:
						display(head);
						break;
					case 4:
						printf ("The Top Element = %d\n",peek(head));
						break;
					case 5:
						return 0;
				}
				printf ("\nDo you want to continue(Type 0 or 1)?\n");
				scanf ("%d", &option);
	}
}
