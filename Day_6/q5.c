// q5-- Write a program to implement queue using linked list.


#include<stdio.h>
#include<stdlib.h>

void enqueue(void);                                                     //
void dequeue(void);                                                   //
void display(void);                                                   //  function prototype
void peek(void);                                                      //
int lenQueue(void);                                                     //
void free_global(void); 

typedef struct node                                        // struct for linked queue
{
	int data;
	struct node *next;
}Node;                                                     

Node *front=NULL;                                        //creating front pointer
Node *rear=NULL;                                         //creating rear pointer
int size=0; 

int main()                                             //main
{
  int ch;	
  printf("\n Enter size of queue..");
  scanf("%d",&size);
  do{
	  printf("\n1.Enueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
	  scanf("%d",&ch);
	  switch(ch)
	  {
		  case 1: enqueue();
			  break;
	          case 2: dequeue();
			  break;
		  case 3: peek();
			  break;
		  case 4: display();
		          break;
		  case 5: free_global();
			  exit(0);
		  default : printf("\n Invalid choice..");	  
	  }

  }while(ch != 5);


  return 0;	  
}

int lenQueue()                                         //logic for lenght of queue
{
	Node* temp = front;
	int count=0;
	if(front == NULL && rear == NULL)
	{
		count=-1;
	}
	else{
	   while(temp->next != NULL)
	   {
		count++;
		temp=temp->next;
	   }
	}
	return count+1;
}

void enqueue()                                        //logic for inserting element into queue
{
	Node *enq;
	int val;
	enq=(Node*)malloc(sizeof(Node));
	if(lenQueue() == size)
	{
		printf("\n Queue full..\n");
	}
	else if(front == NULL && rear == NULL)
	{
		printf("\n Enter data to be queued:");
		scanf("%d",&val);
		enq->data=val;
		enq->next=NULL;
		front=enq;
		rear=enq;
	}
	else
	{
		printf("\n Enter data to be queued:");
                scanf("%d",&val);
                enq->data=val;
                enq->next=front;
		front=enq;
	}
}

void dequeue()                                          //logic for removing element from the queue
{
	Node* temp;
	if(front==NULL && rear==NULL)
	{
		printf("\n Queue empty..\n");
	}
	else
	{
		if(front == rear)
		{
			printf("\n Dequeued element..[%d]",front->data);
			front=NULL;
			rear=NULL;
		}
		else
		{
			temp=front;
			while(temp->next != NULL)
			{
				if(temp->next->next==NULL)
				{
				   printf("\n Dequeued element..[%d]",temp->next->data);	
                                   temp->next=NULL;
				   rear=temp;
				   return;
				}
				temp=temp->next;
			}
			free(temp);
		}
	}

}

void display()                                       //logic for print the queue element
{
	Node *temp;
	if(front==NULL && rear==NULL)
	{
		printf("\n Queue is empty..\n");
	}
	else
	{
		printf("\n Queue : ");
		temp=front;
		while(temp->next != NULL)
		{
			printf("[%d]->",temp->data);
			temp=temp->next;
		}
                printf("[%d]->",temp->data);

	}

}
void peek()                                            //logic for displaying front element of queue
{
	Node *temp;
	if(front == NULL && rear ==NULL)
	{
		printf("\nQUEUE IS EMPTY\n");
	}
	else
	{
		temp=front;
		printf("\nFRONT ELEMENT:");
		printf("%d",temp->data);
	}
}

void free_global()   //free global node when we exit
{
	free(front);
	free(rear);
}
