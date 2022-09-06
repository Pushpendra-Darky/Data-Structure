// q2-- Write a program to print the elements in a link list.


#include<stdio.h>
#include<stdlib.h>

struct node{                                                                  //creating struct for linked list
	int data;
	struct node *next;
};
struct node *head;                                                             //creating head pointer 

void create_list(int);                                                        //
void display();                                                              //function prototyping

int main()                                                                   //main 
{
	int n;
	
	printf("ENTER THE NUMBER OF NODES: ");
	scanf("%d",&n);
	create_list(n);
	display();
	return 0;
}

void create_list(int n)                                                     //function declaration for creating node
{
	struct node *newnode, *temp;
	int data,i;

	head = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("unable to create memory.\n");
		exit(0);
	}
	else
	{
		printf("\nEnter the data in new node 1 =");
		scanf("%d",&data);
		head->data = data;
		head->next = NULL;
		printf("NODE IS CREATED.\n\n");
		
		temp = head;
	}
	for(i=2;i<=n;i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter the data in new node %d =",i);
		scanf("%d",&data);
		newnode->data = data;
		newnode->next = NULL;
		printf("\nNODE IS CREATED.\n\n");

		temp->next = newnode;
		temp = temp->next;
		
	}

}

void display()                                                             //function declaration to print the linked list
{
	struct node *temp;
	int count=0;
	if(head == NULL)
	{
		printf("LIST IS EMPTY.\n");
		return;
	}
	else
	{
		temp=head;
		while(temp != NULL)
		{
			printf("DATA IN NODE %d is %d\n",count,temp->data);
			temp=temp->next;
			count++;
		}
		printf("TOTAL NUMBER OF ELEMENT ARE %d\n",count);
	}
}
