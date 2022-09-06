// q4-- Write a program to insert a new node after nth node.

#include<stdio.h>
#include<stdlib.h>

struct node{                                                         //creating struct for linked list
	int data;
	struct node *next;
};
struct node *head;                                                  //creating head pointer

void create_n(int);                                                //
void display();                                                   //
void insert_random();                                         //function prototyping

int main()                                                      //main
{
	int n;
	printf("ENTER THE NUMBER OF NODES: ");
	scanf("%d",&n);

	create_n(n);
	display();

	insert_random();
	display();

	return 0;
}

void create_n(int n)                                                 //logic for creating node in linked list
{
	struct node *newnode,*temp;
	int data,j;
	head = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("unable to allocate memory.\n");
		exit(0);
	}
	else
	{
		printf("enter the data in node 1: ");
		scanf("%d",&data);
		head->data =data;
		head->next =NULL;
		printf("node is created.\n");

		temp = head;
	}
	for(j=2;j<=n;j++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("\nenter the data in new node %d:",j);
		scanf("%d",&data);

		newnode->data = data;
		newnode->next = NULL;
		printf("node is created.\n");

		temp->next = newnode;
		temp = temp->next;
	}
}

void display()                                                      //logic for printing linked list
{
	struct node *temp;
	int count = 0;
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	else
	{
		temp = head;
		while(temp != NULL)
		{
			printf("data in node %d is %d\n",count,temp->data);
			temp = temp->next;
			count++;
		}
		printf("total no of element are %d\n",count);
	}
}

void insert_random()                                       //logic for inserting node at random position
{
    int i,loc,item;
    struct node *r, *temp;
    r = (struct node *) malloc (sizeof(struct node));
    if(r == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value to be inserted\n");
        scanf("%d",&item);
        r->data = item;
        printf("\nEnter the node location to insert:\n");
        scanf("\n%d",&loc);

        temp=head;
	if(loc==0)
	{
		temp->data=item;
		temp->next=head->next;
		head=temp;
		
	}
        if(loc>0)
	{
        temp=head;
        for(i=1;i<loc;i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }

        }
        r->next = temp->next;
        temp->next = r;
        printf("\nNode inserted\n");
    }
    }
}
