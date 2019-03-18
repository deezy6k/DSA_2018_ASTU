/*
	Sorted priority Queue
	Author : Dawit Kefyalew 
	03/18/2019
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Node {
	int data;
	int priority;
	Node* next;
};

// only for the 1st Node
void initNode(struct Node *head,int n,int p){
	head->data = n;
	head->priority = p;
	head->next =NULL;
}

void enqueue(struct Node **head, int Ndata,int Npriorty) {
	Node *cur = *head;
	
	Node *newNode = new Node;
	newNode->data = Ndata;
	newNode->priority = Npriorty;
	newNode->next = NULL;
	
	if(cur->next == NULL || cur->priority <= Npriorty){
			if(cur->priority >= Npriorty){
				cur->next = newNode;
				return;			
			}else{
				newNode->next = cur;
				*head = newNode;
				return;
			}
	}
	while(cur) {
		if(cur->next == NULL || cur->next->priority <= Npriorty) 
			break;
		cur = cur->next;
	}
	
	
	Node *NxtOfCur = cur->next;
	cur->next = newNode;
	newNode->next = NxtOfCur;
}


bool dequeue(struct Node **head) {
	Node *cur = *head;
	*head = cur->next;
	delete cur;
}

void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout <<"\t[ "<< list->data <<" P = "<<list->priority<<" ] ";
		list = list->next;
	}
}


int main(){
	int ch,data,priorty;
	struct Node *head;
	while(1){
		cout<<"Welcome\n\t1, Create\t2, Enqueue\t3, Dequeue\t4, Display\t5, Get Front\t6, Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				head = new Node;
				cout<<"\tHead node will be initialized\n\tPlease enter the value of head node : ";
				cin>>data;
				cout<<"\n\tPlease enter the priorty of head node : ";
				cin>>priorty;
				initNode(head,data,priorty);
				cout<<"\tQueue Created Successfully.\n\n";
				display(head);
				break;
			case 2:
				if(head != NULL){
					cout<<"\tPlease Enter the value of the new node :";
					cin>>data;
					cout<<"\tPlease enter the priorty of head node : ";
					cin>>priorty;
					enqueue(&head,data,priorty);
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
