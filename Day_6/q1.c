// q1-- Write a program to delete a node from linked list at starting position.


#include<stdio.h>
#include<stdlib.h>

struct node                                                //struct for linked list
{
	int data;
	struct node *next;
};
struct node *head;                                        //head pointer

void create_list(int n);            //
void display();                      //function prototyping
void del_start();                  //

int main()                                //main
{
	int n;
	printf("ENTER THE NO OF NODES: ");
	scanf("%d",&n);
	create_list(n);
	printf("\nDATA IN NODES:\n");
	display();
	del_start();
	printf("\nAFTER DELETING START NODE:\n");
        display();
	return 0;
}

void create_list(int n)                                          //logic for creating node in linked list
{
	struct node *newnode,*temp;
	int data,i;

	head = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("UNABLE TO ALLOCATE MEMORY.\n");
		exit(0);
	}
	else
	{
		printf("ENTER THE DATA IN NEW NODE 1: ");
		scanf("%d",&data);
		head->data = data;
		head->next = NULL;
		printf("\nnode is created.\n");

		temp = head;
	}
	for(i=2;i<=n;i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("ENTER THE DATA IN NEW NODE %d: ",i);
		scanf("%d",&data);
		newnode->data = data;
		newnode->next = NULL;
		printf("\nnode is created.\n");

		temp->next = newnode;
		temp = temp->next;
	}
}

void display()                                                 //logic to print the linked list
{
	struct node *temp;
	int count=0;
	if(head == NULL)
	{
		printf("\nLIST IS EMPTY.\n");
		exit(0);
	}
	else
	{
		temp = head;
		while(temp != NULL)
		{
			printf("DATA IN NODE %d IS %d.\n",count,temp->data);
			temp=temp->next;
			count++;
		}
		printf("\nTOTAL NUMBER OF NODE IS %d.\n",count);
	}
}

void del_start()                                               //logic for deleting node from strating position
{
	struct node *temp;
	if(head == NULL)
	{
		printf("\nLIST IS EMPTY.\n");
		exit(0);
	}
	else
	{
		temp = head->next;
		free(head);
		head=temp;	
	}
}
