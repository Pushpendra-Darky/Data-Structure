// q1-- Write a program to create a Linked list with n elements.


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
        struct node *next;                                                //creating struct for liked list
};
struct node *head;                                                        //creating head pointer

void create_list(int);                                                   //
void display();                                                         //function prototyping

int main()                                                             //main
{
	int n;
	printf("ENTER THE NUMBER OF NODE IN LINKED LIST\n");
	scanf("%d",&n);
	create_list(n);
	printf("\nDATA IN LIST:\n");
	display();

	return 0;
}

void create_list(int n)                                               //function declaration for creating node
{
	struct node *newnode,*temp;
	int data,i;
	head=(struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("UNABLE TO ALLOCATE MEMORY.\n");
		exit(0);
	}
	else
	{
            printf("ENTER THE DATA IN NODE 1 = ");
	    scanf("%d",&data);
	    head->data = data;
	    head->next = NULL;
	    printf("\nNEW NODE CREATED SUCCESSFULLY.\n\n");
	    temp=head;

	    for(i=2;i<=n;i++)
	    {
		    newnode=(struct node*)malloc(sizeof(struct node));
		    if(newnode == NULL)
		    {
			    printf("UNABLE TO ALLOCATE MEMORY.\n");
			    break;
		    }
		    else
		    {
		      printf("ENTER THE DATA IN NEW NODE %d =",i);
		      scanf("%d",&data);

		      newnode->data = data;
		      newnode->next = NULL;

		      temp->next = newnode;
		      temp = temp->next;
		      printf("\nNEW NODE CREATED SUCCESSFULLY.\n\n");
		    }
	    }
	    
	}
}

void display()                                                         //function declaration for displaying the linked list
{
	struct node *temp;
	if(head==NULL)
	{
		printf("LIST IS EMPTY.\n");
		return;
	}
	else
	{
		temp=head;
		while(temp != NULL)
		{
			printf("DATA = %d\n",temp->data);
			temp=temp->next;
		}
	}


}
