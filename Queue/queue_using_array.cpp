/*
	Queue implmented using array 
	Author : Dawit Kefyalew 
	03/18/2019
*/
   #include <iostream>
   #define MAX 5
   using namespace std;
   
   int Queue[MAX];
   int rear = - 1;
   int front = - 1;
   
   bool isEmpty();
   bool isFull();
   void enqueue();
   void dequeue();
   void display();
   int getFront();
   
   int main()
   {
       int choice;
       while (1)
       {
            cout<<"\n\t 1.Insert element to queue \n";
            cout<<"\t 2.Delete element from queue \n";
            cout<<"\t 3.Display all elements of queue \n";
            cout<<"\t 4.Get front element \n";
			cout<<"\t 5.Quit \n\n";
            
			cout<<"Enter your choice : ";
            cin>>choice;
            
			switch (choice)
            {
                case 1:
                	enqueue();
                	break;
                case 2:
                	dequeue();
                	break;
                case 3:
                	display();
                	break;
                case 4:
                	getFront();
                	break;
				case 5:
                	return 1;
                	break;
                default:
                	cout<<"Wrong choice \n";
            } /*End of switch*/
       } /*End of while*/
   } /*End of main()*/
   
bool isEmpty()
{
	if(front == rear)
		return true;
	else
		return false;
}
bool isFull()
{
	if(rear == MAX - 1)
		return true;
	else
		return false;
}
   
void enqueue()
{
    int newElement;      
    
	if (isFull()){
		cout<<"Error: Queue is full! \n";
		return;
	}    	
    else{
        cout<<"Enter the value of the element : ";
        cin>>newElement;
        Queue[++rear] = newElement;
    }
} 

void dequeue()
{
	if (isEmpty()){
    	cout<<"Queue is empty! \n";
        return ;
    }
    else{
        cout<<"Element deleted from queue is : "<<Queue[++front]<<"\n";
    }
} 

void display()
{
    if (isEmpty())
        cout<<"Queue is empty \n";
    else{
        cout<<"Content of Queue is : ";
        for (int i = front+1; i <= rear; i++)
	        cout<<"\t"<<Queue[i];
        cout<<"\n";
    }
}

int getFront()
{
	if(!isEmpty()){
		cout<<"Front of the queue : "<<Queue[front + 1]<<"\n";
		return(Queue[front + 1]);
	}else{
		cout<<"Queue is empty \n";
	}			
}
