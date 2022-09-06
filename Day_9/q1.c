/*            Assignment Day8 and Day9-
                                   q1-- Write a program to implement a binary search tree and the following operations on it using arrays:
                                           a. Create()
                                           b. Inorder()
                                           c. Preorder()
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 8
int A[SIZE];

struct BST_node
{
	int data;
	struct BST_node *l_child, *r_child;
};
struct BST_node *root = NULL;

struct BST_node* create(int);
void inorder(struct BST_node *inorder_t);
void preorder(struct BST_node *preorder_t);
void postorder(struct BST_node *postorder_t);

int main()
{	
	int i;
	printf("ENTER THE ELEMENT:\n");
	for(i=0;i<SIZE;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&A[i]);
	}
	
	printf("\nDATA IN ARRAY:\n");
	for(i=0;i<SIZE;i++)
	{
		printf("[%d] = %d\n",i,A[i]);
	}
          
	i=0;
	root = create(i);

	printf("INORDER:\n");
	inorder(root);
	printf("\n");

	printf("PREORDER\n");
	preorder(root);
	printf("\n");
        
	printf("POSTORDER\n");
	postorder(root);
	printf("\n");

	return 0;
}

struct BST_node* create(int i)
{
	struct BST_node *newnode;

	if(i>=SIZE)
	{
		return NULL;
	}

		newnode = (struct BST_node*)malloc(sizeof(struct BST_node));
		newnode->l_child = create((2*i)+1);
		newnode->data = A[i];

		newnode->r_child = create((2*i)+2);
		return newnode;
}

void inorder(struct BST_node *inorder_t)
{
	if(inorder_t)
	{
		inorder(inorder_t->l_child);
		printf("%d  ",inorder_t->data);
		inorder(inorder_t->r_child);
	}
	return;
}

void preorder(struct BST_node *preorder_t)
{
	if(preorder_t)
	{
		printf("%d  ",preorder_t->data);
		preorder(preorder_t->l_child);
		preorder(preorder_t->r_child);
	}
	return;
}

void postorder(struct BST_node *postorder_t)
{
	if(postorder_t)
	{
		postorder(postorder_t->l_child);
		postorder(postorder_t->r_child);
		printf("%d  ",postorder_t->data);
	}
}
