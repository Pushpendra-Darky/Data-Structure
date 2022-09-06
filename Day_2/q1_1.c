// q1_1-- Implement Stack using Array.


#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
int STACK_A[SIZE];

int top= -1;

int isFull()                               //function if stack is full it return stack is full
{
	if(top == SIZE-1)
	{
		printf("STACK IS FULL\nSTACK OVERFLOW\n");
		printf("CANT PUSH THE ELEMENT YOU SHOULD POP ELEMENT FIRST\n");
		return 1;
	}
	else
          return 0;
}

int isEmpty()                                //if stack is empty it return stack is underflow
{
	if(top == -1)
	{
		printf("STACK IS EMPTY\n STACK UNDERFLOW\n");
		printf("CANT POp THE ELEMENT\n");
		return 1;
	}
	else 
	  return 0;

}

void Push(int item)                         //funtion for pushing element into stack
{
	if(isFull())
	{
		printf("\n Inside isFull");

	}
	else
	{
		STACK_A[++top]=item;
		printf("PUSH ELEMENT IS: %d\n",STACK_A[top]);
	}
}


void Pop()                                     //function for pop the element from the stack
{
	int temp=0;

	if(isEmpty())
	{

	}
	else
	{
		temp=STACK_A[top];
		top--;
	}
	printf("POP ELEMENT IS: %d\n",temp);
}

void Peek()                                 //function to show the top element from the stack
{
	int temp;
	if(isEmpty())
	{
	}
	else
	{
		printf("TOP ELEMENT OF THE STACK IS: %d\n",STACK_A[top]);
	}
}


void Display()                                //function for printing the stack element
{
	int i;
	printf("\n top value =%d\n",top);
	for(i=top;i>=0;i--)
	{
		printf("%d\n",STACK_A[i]);
	}
	printf("\n");
}


// main function

int main()
{
	int choice,item;

	while(1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display the top element in stack\n");
		printf("4.Display all elements in stack\n");
		printf("5.Quit.\n");
		printf("ENTER YOUR CHOICE\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("ENTER THE ELEMENT, TO BE ADDED INTO STACK(Push):\n");
				scanf("%d",&item);
				Push(item);
				break;

			case 2:
				Pop();
				break;

			case 3:
				Peek();//displaying top element
				break;

			case 4:
				printf("ELEMENTS IN THE STACK ARE:\n");
				Display();
				break;
				
			case 5:
				exit(1);

			default:
				printf("WRONG CHOICE,ENTER VALID CHOICE 1 to 5:\n");


		}
	}
	

	return 0;
}
