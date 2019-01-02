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


void insertFront(struct Node **head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

// apending at the end
void insertRear(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void insertMiddel(struct Node *preNode, int val){
	Node *newNode = new Node;
	newNode->data = val;
	Node *nxtNode = preNode->next;
	
	preNode->next = newNode;
	newNode->next = nxtNode;
}

bool deleteNode(struct Node **head, Node *ptrDel) {
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	
	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}



struct Node *searchNode(struct Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
	}
	cout << "\tThere is no Node with valur =" << n << " in the linkedlist.\n";
	return NULL;
}

void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout <<"\t[ "<< list->data << " ] ";
		list = list->next;
	}
}


int main(){
	int ch,data,key;
	struct Node *head;
	while(1){
		cout<<"Welcome\n\t1, Create\n\t2, Insert at Front\n\t3, Insert at Rear\n\t4, Insert at Middle\n\t5, Delete\n\t6, Display\n\t7, Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				head = new Node;
				cout<<"\tHead node will be initialized\n\tPlease enter the value of head node : ";
				cin>>data;
				initNode(head,data);
				cout<<"\tLinked List Created Successfully.\n\n";
				display(head);
				break;
			case 2:
				if(head != NULL){
					cout<<"\tPlease Enter the value of the new node :";
					cin>>data;
					insertFront(&head,data);
					cout<<endl;
					display(head);
				}else{
					cout<<"\tError: Please create the linkedlist first";
					cout<<"\n\tPress any key to continue...";
					getch();
				}				
				break;
			case 3:
				if(head != NULL){
					cout<<"\tPlease Enter the value of the new node :";
					cin>>data;
					insertRear(head,data);
					cout<<endl;
					display(head);
				}else{
					cout<<"\tError: Please create the linkedlist first";
					cout<<"\n\tPress any key to continue...";
					getch();
				}				
				break;
			case 4:
				if(head != NULL){
					cout<<"\tPlease Enter the value of the new node :";
					cin>>data;
					cout<<"\tPlease Enter the value of the predecessor node :";
					cin>>key;
					Node *preNode = searchNode(head,key);
					if(preNode != NULL)
					{
						insertMiddel(preNode,data);
						cout<<endl;
						display(head);
					}else{
						//cout<<"\n\tError: There is no such node with value = "<<key;
						cout<<"\n\tPress any key to continue...";
						getch();
					}	
				}else{
					cout<<"\tError: Please create the linkedlist first";
					cout<<"\n\tPress any key to continue...";
					getch();
				}
				break;			
			case 5:
				if(head != NULL){
					cout<<"\tPlease Enter the value of the node to deleted :";
					cin>>data;
					Node *delNode = searchNode(head,data);
					if(delNode != NULL)
					{
						if(deleteNode(&head,delNode)) 
							cout << "\tNode "<< data << " deleted!";						
						cout<<endl;
						display(head);
					}else{
						//cout<<"\n\tError: There is no such node with value = "<<key;
						cout<<"\n\tPress any key to continue...";
						getch();
					}
				}else{
					cout<<"\tError: Please create the linkedlist first";
					cout<<"\n\tPress any key to continue...";
					getch();
				}
				break;
			case 6:
				display(head);
				break;
			case 7:
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
