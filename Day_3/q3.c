// q3-- Write a program to Sort an  array using Stacks.



#include<stdio.h>

#define SIZE 5
int STACK_A[SIZE];                                              //creating stack
int TEMP_STACK_A[SIZE];                                         //creating temp stck
int array[SIZE];                                                //creating array
int top = -1;                                                   //set top for temp
int top_temp = -1;                                              //set top for temp


int isFull(int*);                                              //  
int isEmpty(int*);                                             //
void sort(void);                                               //function prototyping
void push(int stack[SIZE],int item,int* top);                  //
void pop(int *top);                                            //

int main()                                                      //main function
{
	int i,tmp;

	printf("ENTER THE ELEMENT IN ARRAY:\n");
        for(i=0;i<SIZE;i++)
	{
	   scanf ("%d",&tmp);
	   push(STACK_A,tmp,&top);
	   array[i]=tmp;
	}

	printf("ARRAY ELEMENT:\n");
	for(i=0;i<SIZE;i++)
	{
	  printf("[%d]=%d\n",i,array[i]);
	}
	sort();
	//storing sorted array in original array
    for(i=0;i<SIZE;i++)
    {
        array[i] = TEMP_STACK_A[i];
    }

	printf("\nSorted array using stack ..\n");
        for(i=(SIZE-1);i>=0;i--)
        {
            printf("%d\n",array[i]);
        }

	return 0;
}

int isFull(int *top)                                                  //function declaration for cheacking full condition for stack
{
	if((*top) == (SIZE-1))
	{
		printf("STACK IS FULL | OVERFLOW:\n");
		return 1;
	}
	else
	        return 0;
}

int isEmpty(int *top)                                                //fucntion declaration for checking empty condition for stack
{
	if((*top) == -1)
	{
		return 1;
	}
	else
		return 0;
}

void push(int stack[SIZE],int item,int *top)                         //logic for push
{
	if(isFull(top))
	{

	}
	else
	 stack[++(*top)]=item;
}

void pop(int *top)                                                 //logic for pop
{
	if(isEmpty(top))
	{

	}
	else
		(*top)--;
}

void sort()                                                         //sorting array using stack
{
  while(!isEmpty(&top))
  {
	  int tmp = STACK_A[top];
	  pop(&top);
	  while(!isEmpty(&top_temp) && TEMP_STACK_A[top_temp] > tmp)
	  {
		  push(STACK_A,TEMP_STACK_A[top_temp],&top);
		  pop(&top_temp);
	  }
	  push(TEMP_STACK_A,tmp,&top_temp);
  }

}
