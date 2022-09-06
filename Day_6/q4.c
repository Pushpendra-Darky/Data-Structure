// q4-- Write a program to implement stack using linked list.


#include<stdio.h>
#include<stdlib.h>

#define SIZE 6   //declare size of stack linked list
struct node{                                                                 //struct for stack
	int data;
	struct node *next;
};
struct node *top=NULL;


int num_of_nodes();                                                          //
void display();                                                               //
void peek();                                                                  //function prototyping
void pop();                                                                   //
void push(int);                                                               //
void free_global();


int main()                                                                      //main
{
	int choice,item;

	while(1)
	{
		printf("\n1.PUSH NODE INTO STACK\n");
		printf("2.POP NODE INTO STACK\n");
		printf("3.FRONT NODE OS STACK\n");
		printf("4.DISPLAY NODE ELEMENT\n");
		printf("5.EXIT\n");
		printf("\nENTER THE CHOICE: \n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nENTER THE DATA ELEMENT INTO LINKED STACK:\n");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5: 
				free_global();
				exit(1);
					
			default:
				printf("ENTER VALID CHOICE.\n");

		}
	}


	return 0;
}
void push(int item)                                                           //logic for inserting element to the stack
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("\nSTACK LINKED LIST IS FULL.\n");
		return;
	}
	else if(num_of_nodes() != SIZE)
	{
		temp->data = item;
		temp->next = top;
		top = temp;
	}
	else if(num_of_nodes() == SIZE)
	{
		printf("STACK LINKED LIST OVERFLOW\n");
		return;
	}
}

void pop()                                                                      // logic for removing element from stack
{
	struct node *del;
	if(top == NULL)
	{
		printf("\nSTACK LINKED LIST IS EMPTY.\n");
		return;
	}
	else
	{
		del=top->next;
		top=del;
	}
	
}

void peek()                                                                     //logic for display top element of stack
{
	if(top == NULL)
	{
		printf("\nSTACK LINKED LIST IS EMPTY.\n");
		return;
	}
	else
	{
		printf("\nDATA IN TOP OF STACK LINKED NODE IS: %d\n",top->data);
	}
}

void display()                                                                  //logic for print the element
{
	struct node *dis;
	if(top == NULL)
	{
		printf("\nSTACK LINKED LIST IS EMPTY.\n");
		return;
	}
	else
	{
		dis=top;
		printf("\nSTACK LINKED LIST DATA ARE:\n");
		while(dis != NULL)
		{
			printf("%d\n",dis->data);
			dis=dis->next;
		}
		printf("\n");
	}
}

int num_of_nodes()                                                             //logic for lenth of stack
{
	struct node *num;
	int count=0;
	if(top==NULL)
	{
		printf("\nSTACK LINKED LIST IS EMPTY.\n");
		return 0;
	}
	else
	{
		num = top;
		while(num->next != NULL)
		{
			num=num->next;
			count++;
		}
		return count+1;
		printf("\nNUMBER OF NODE IN STACK LINKED LIST IS %d\n",count+1);
	}
}

void free_global()
{
	free(top);
}
