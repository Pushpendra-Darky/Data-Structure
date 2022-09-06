// q2-- Write a program to implement circular queue using array.


#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int QUEUE_A[SIZE];                                                      //creating queue

int f = -1;                                                             //setting front end 
int r = -1;                                                             //setting rear end
int isEmpty();                                   //
int isFull();                                   //
void enqueue(int);                             //
void dequeue();                               //
void peek();                                  //
void display();                               //function prototyping

int main()                                    //main
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

int isEmpty()                                        //funtion declaration for checking queue is empty or not
{
	if((f == -1)&&(r == -1))
	{
		return 1;
	}
	else
		return 0;
}

int isFull()                                      //function declaration for checking queue is full or not
{
	if(r == SIZE-1)
	{
		return 1;
	}
	else
		return 0;
}

void enqueue(int x)                                 //fucntion declaration for inserting the element into circular queue
{
	if((f==0 && r == SIZE-1) ||(f == r+1))
	{
             printf("QUEUE IS OVERFLOW\n");
                return;

	}
	if(f == -1)
	    f=0;
	if(r==SIZE-1)
	    r=0;
	else
	     r++;

    QUEUE_A[r] = x;
}

void dequeue()                                    //function declaration for removing element from the circular queue
{

	if(f== -1)
	{
             printf("QUEUE IS UNDERFLOW\n");
                return;
	}
	printf("DEQUEUE ELEMENT IS: %d\n",QUEUE_A[f]);
	if(f == r)
	{
          f=-1;
          r=-1;
	}
	else if(f==SIZE-1)
	      f=0;
	else
	    f++;
}

void peek()                                       //function declaration for diplaying front element of the queue
{
	if(f==-1)
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

void display()                                   //function declaration for displaying the element of queue
{
	int i;
	int fpos=f;
	int rpos=r;
	if(f==-1)
	{
		printf("QUEUE IS EMPTY.\n");
		return;
	}
	printf("QUEUE ELEMENT IS:\n");
	if(fpos<=rpos)
	{
	  while(fpos<=rpos)
	  {
		printf("%d\t",QUEUE_A[fpos]);
		fpos++;
	  }
	}
	else
	{
	    while(fpos <= SIZE-1)
	    {
	        printf("%d\t",QUEUE_A[fpos]);
	        fpos++;
	    }
	    fpos=0;
	  while(fpos<=rpos)
	  {
		printf("%d\t",QUEUE_A[fpos]);
		fpos++;
	  }
	}
	printf("\n");
}
