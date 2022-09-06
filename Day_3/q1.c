// q1-- Write a menu driven program for stack implementation.


#include<stdio.h>
#include<stdlib.h>

#define SIZE 5                                                    //define size to 5
int STACK_A[SIZE];                                                //defining STACK_A of size

int top = -1;



int isEmpty()                                                     //function for showing stack is empty
{
	if(top == -1)
	{
		printf("STACK UNDERFLOW\nSTACK IS EMPTY\n");
		return 1;
	}
	else
		return 0;
}

int isFull()                                                      //function for showing stack is full
{
	if(top == SIZE-1)
	{
		printf("STACK OVERFLOW\nSTACK IS FULL\n");
	}
	else
		return 0;
}

void Push(int item)                                                //function for pushing the element into stack
{
	if(isFull() )
	{

	}
	else
	{
		STACK_A[++top]=item;
		printf("PUSH ELEMENT IS: %d\n",STACK_A[top]);
	}

}

void Pop()                                                           //function for pop the element from the stack
{
	int temp=0;
	if(isEmpty() )
	{

	}
	else
	{
		temp=STACK_A[top];
		top--;
		printf("POP ELEMENT FROM STACK IS: %d\n",temp);

	}

}

void Peek()                                                              //function for showing the top element from the stack
{
	if(isEmpty() )
	{

	}
	else
	{
		printf("TOP ELEMENT IN STACK IS: %d\n",STACK_A[top]);
	}
}


void Display()                                                           //function for displaying the stack element
{
	if(isEmpty() )
	{

	}
	else
	{
		int i;
		for(i=top;i>0;i--)
		{
			printf("%d\n",STACK_A[i]);
		}
	}
}




int main()                                                                 //main function
{
	int choice,item;
	while(1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Display all element of stack\n");
		printf("5.exit\n");
		printf("ENTER THE CHOICE: ");
		scanf("%d",&choice);
	
        	switch(choice)
        	{
		case 1:
			printf("ENTER THE ELEMENT TO BE PUSH INTO STACK:\n");
			scanf("%d",&item);
			Push(item);
			break;
		case 2:
			Pop();
			break;
		case 3:
			Peek();
			break;
		case 4:
			printf("ELEMENTS IN STACKS ARE:\n");
			Display();
			break;
		case 5:
			exit(1);
		default :
			printf("ENTERED WRONG CHOICE!");
        	}
	}

	return 0;
}
