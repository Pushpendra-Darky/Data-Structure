// q1-- Write a program to implement Queue data structure using Array.


#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int QUEUE_A[SIZE];                                                         //creating queue array

int f = -1;                                                                //setting front end of queue
int r = -1;                                                                //setting rear end of queue
int isEmpty();                                                          //
int isFull();                                                          //
void enqueue(int);                                                    //
void dequeue();                                                      //
void peek();                                                         //fucntion prototyping
void display();                                                     //

int main()                                                          //main
{
	int choice,item;

	while(1)
	{
		printf("\n1.ENQUEUE\n");
		printf("2.DEQUEUE:\n");
		printf("3.DISPLAY THE FROMT ELEMENT:\n");
		printf("4.DISPLAY QUEUE ELEMENT:\n");
		printf("5.EXIT\n");

		printf("ENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
                printf("\n");
		switch(choice)
		 {
			 case 1:
				 printf("ENTER THE ELEMENT FOR ENQUEUE:\n");
				 scanf("%d",&item);
				 enqueue(item);
				 break;
			 case 2:
				 dequeue();
				 break;
			 case 3:
				 peek();
				 break;
			 case 4:
				 display();
				 break;
			 case 5:
				 exit(1);
			 default:
				 printf("ENTER VALID CHOICE\n");

		 }
	}
	



	return 0;
}

int isEmpty()                                                         //function declaration for checking queue is empty or not
{
	if((f == -1)&&(r == -1))
	{
		return 1;
	}
	else
		return 0;
}

int isFull()                                                         //function declaration for checking queue is full or not
{
	if(r == SIZE-1)
	{
		return 1;
	}
	else
		return 0;
}

void enqueue(int x)                                                  //function declaration for inserting element into queue
{
	if(r == SIZE-1)
	{
             printf("QUEUE IS OVERFLOW\n");
                return;

	}
	else
	{
	    if(f==-1)
	    f=0;	    
            r++;
	    QUEUE_A[r]=x;
	}

}

void dequeue()                                                       //function declaration for removing elment from queue
{

	if(f== -1 || r<f)
	{
             printf("QUEUE IS EMPTY\nQUEUE IS UNDERFLOW\n");
                return;
	}
	else
	{
            printf("DEQUEUE ELEMENT IS: %d\n",QUEUE_A[f]);
	    f++;
	}

}

void peek()                                                       //function declaration for checking front end element from queue
{
	if(f==-1 || r<f)
	{
		printf("Queue is EMPTY.\n");
		return;
	}
	else
	{
		printf("FRONT ELEMENT IS: ");
		printf("%d",QUEUE_A[f]);
	}
}

void display()                                                     //function for displaying the queue
{
	int i;
	if(f==-1 || r<f)
	{
		printf("QUEUE IS EMPTY.\n");
		return;
	}
	printf("QUEUE ELEMENT IS:\n");
	for(i=f;i<=r;i++)
	{
		printf("%d\t",QUEUE_A[i]);
	}
	printf("\n");
}
