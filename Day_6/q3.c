// q3-- Write a program to delete a node from linked list at nth position.

#include<stdio.h>
#include<stdlib.h>

struct node                                                                        //struct for linked list
{
	int data;
	struct node *next;
};
struct node *head;                                                             //head pointer

int lenList(void);                              //
void create_l(int);                           //
void display();                              // function prototyping
void del_pos(int);                             //

int main()                              //main
{
	int n,pos;
	printf("ENTER THE NUMBER OF NODES: ");
	scanf("%d",&n);
	create_l(n);
	printf("\nDATA IN NODE:\n");
	display();
	printf("ENTER THE POSITION OF NODE TO DELETE: ");
	scanf("%d",&pos);
	del_pos(pos);
	printf("\nDATA IN NODE:\nAFTER DELETING NODE %d \n",pos);
	display();

	return 0;

}

void create_l(int n)                                     //logic for creating nodes in linked list
{
	struct node *new,*temp;
	int data,i;
	head =(struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("Unable to allocate memory.\n");
		exit(0);
	}
	else
	{
		printf("ENTER THE DATA IN NODE 1: ");
		scanf("%d",&data);
		head->data= data;
		head->next = NULL;
		printf("node is created.\n\n");

	}	temp=head;
	
	for(i=2;i<=n;i++)
	{
		new = (struct node*)malloc(sizeof(struct node));
		printf("ENTER THE DATA IN NODE %d: ",i);
		scanf("%d",&data);
		new->data = data;
		new->next = NULL;
		printf("node is created\n\n");

		temp->next = new;
		temp = temp->next;
	
	}
}

void display()                                                 //logic for print the linked list
{
	struct node *temp;
	int count=0;
	if(head == NULL)
	{
		printf("\nLIST IS EMPTY\n");
		exit(0);
	}
	else
	{
		temp = head;
		while(temp != NULL)
		{
			printf("DATA IN NODE %d IS %d\n",count,temp->data);
			temp = temp->next;
			count++;
		}
		printf("TOTAL NO OF NODES IS %d\n",count);
	}
}

void del_pos(int pos)                                      //logic for deleting node at random position
{
	struct node *temp,*b;
	
	if(head == NULL)
	{
		printf("LIST IS EMPTY.\n");
		exit(0);
	}
	else
	{
		int i=0;
		temp = head;
		/* Removing first node */
		if(pos == 1)                            //logic for deleting starting node
		{
			temp=head->next;
			free(head);
			head=temp;
			return;
		}
		/* Removing last node */
		else if(pos == lenList())
		{
                   while(temp->next->next != NULL)
		    temp=temp->next;

                   temp->next=NULL;
		   free(temp->next);
		}
		/* Removing any node between first and last */
		else if(pos>1 && pos<lenList()){
		while(temp->next != NULL)
		{
			if((++i) == (pos-1))
			{
				b = temp->next->next;
				temp->next = b;
				return;
			}
			temp=temp->next;
		}
		free(temp->next);
         	}
		/* Wrong Position selected*/
		else
		{
			printf("\nNODE IS NOT PRESENT IN LIST.\n");
			exit(0);
		}
	}
}

int lenList()                             //logic for checking lenght of linked list
{
	struct node *tmp=head;
	int count=0;
        while(tmp->next != NULL)
	{
		tmp=tmp->next;
		count++;
	}
	return count+1;
}
