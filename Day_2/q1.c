// q1-- Implement Stack using Array.



#include<stdio.h>

#define MAX_SIZE 50
int AR[MAX_SIZE];

int top=-1;


void Push(int x)
{
	if(top == MAX_SIZE -1)
	{
		printf("ERROR:STACK OVERFLOW:\n");
		return;
	}
	else
	{
	AR[++top]=x;
	}
}

void Pop()
{
	if(top == -1)
	{
		printf("ERROR: FILE IS EMPTY\n");
		return;
	}
	else
	{
		top--;
	}

}


int Top()
{
	return AR[top];
}

int IsEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void Printing()
{
	int i;
	printf("STACK:\n");
	for(i=0;i<=top;i++)
	{
		printf("STACK ELEMENT : %d\n",AR[i]);
	}
	printf("\n");
}


int main()
{
	Push(2);
	Printing();

	Push(5);
	Printing();

	Push(10);
	Printing;

	Pop();
	Printing();

	Push(12);
	Printing();



	return 0;
}
