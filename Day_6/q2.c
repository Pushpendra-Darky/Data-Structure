// q2-- Write a program to delete a node from linked list at last position.

#include<stdio.h>
#include<stdlib.h>

struct node                                                         //struct for linked list
{
	int data;
	struct node *next;
};
struct node *head;                                                   //head pointer

void create_n(int);          //
void display();                //function prototyping
void del_l();                //

int main()                        //main
{
	int n;
	printf("ENTER THE NUMBER OF NODES: ");
	scanf("%d",&n);
	create_n(n);
	printf("\nDATA IN NODES:");
	display();
	del_l();
	printf("\nAFTER DELETING LAST NODE:");
	display();

	return 0;
}

void create_n(int n)                                           //logic for creating node
{
	struct node *create,*temp;
	int data,i;
	head = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("Unable to allocate memory.\n");
		exit(0);
	}
	else
	{
		printf("ENTER THE DATA IN NODE 1: ");
		scanf("%d",&data);
		head->data = data;
		head->next = NULL;
		printf("NODE IS CREATED.\n");

		temp = head;
	}
	for(i=2;i<=n;i++)
	{
		create = (struct node*)malloc(sizeof(struct node));
		printf("ENTER THE DATA IN NODE %d: ",i);
		scanf("%d",&data);
		create->data = data;
		create->next = NULL;
		printf("NODE IS CREATED\n");

		temp->next = create;
		temp= temp->next;
	}

}

void display()                                                //logic to print the linked list
{
	struct node *temp;
	if(head == NULL)
	{
		printf("\nLIST IS EMPTY.\n");
	}
	else
	{
		int count=0;
		temp = head;
		while(temp != NULL)
		{
			printf("\nDATA IN NODE %d is  %d.",count,temp->data);
			temp=temp->next;
			count++;
		}
		printf("\nNUMBER OF NODES IS %d .\n",count);
	}
}

void del_l()                                                //logic for deleting node from the last position
{
	struct node *temp,*p;
	int i=0,count=0;
	if(head == NULL)
	{
		printf("\nLIST IS EMPTY.\n");
		exit(0);
	}
	else
	{
		temp = head;
		int dat;
		while(temp->next != NULL)
		{
			temp=temp->next;

		}
		dat = temp->data;
		p = head;
		int flag=0;
		while(p->next != NULL)
		{
                   if(p->next->data == dat)
		   {
			   p->next=NULL;
			   free(p->next);
			   flag=1;
		   }
		   if(flag == 0)
		     p=p->next;
		}

		printf("\nNODE DELETED FROM LAST WITH DATA %d\n",dat);

	}
}
