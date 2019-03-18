/*
	Queue implmented using linked list 
	Author : Dawit Kefyalew 
	03/18/2019
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

// only for the 1st Node
void initNode(struct Node *head,int n){
	head->data = n;
	head->next =NULL;
}

// apending at the rear/tail of the queue
struct Node* enqueue(struct Node *tail, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	
	tail->next = newNode;
	return newNode;
}

bool dequeue(struct Node **head) {
	Node *cur = *head;
	*head = cur->next;
	delete cur;
}

void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout <<"\t[ "<< list->data << " ] ";
		list = list->next;
	}
}


int main(){
	int ch,data;
	struct Node *head;
	struct Node *tail;
	while(1){
		cout<<"Welcome\n\t1, Create\n\t2, Enqueue\n\t3, Dequeue\n\t4, Display\n\t5, Get Front\n\t6, Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				head = new Node;
				cout<<"\tHead node will be initialized\n\tPlease enter the value of head node : ";
				cin>>data;
				initNode(head,data);
				tail = head;
				cout<<"\tQueue Created Successfully.\n\n";
				display(head);
				break;
			case 2:
				if(head != NULL){
					cout<<"\tPlease Enter the value of the new node :";
					cin>>data;
					tail = enqueue(tail,data);
					cout<<endl;
					display(head);
				}else{
					cout<<"\tError: Queue is empty!";
				}				
				break;
			case 3:
				if(head != NULL){
					dequeue(&head);
					display(head);					
				}else{
					cout<<"\tError: Queue is empty";
				}
				break;
			case 4:
				if(head != NULL)
					display(head);
				else{
					cout<<"\tError: Queue is empty";
				}
				break;			
			case 5:
				if(head != NULL){
					cout<<"Front of the queue : [ "<<head->data<<" ]\n";					
				}else{
					cout<<"\tError: Queue is empty";
				}
				break;
			case 6:				
				exit(0);
				break;
			default:
				cout<<"\nInvalid Choice!\nPress any key to continue...";
				getch();
				break;
		}
		cout<<endl;
	}
}
