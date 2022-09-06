// q2-- Write a program to Sort a stack using a temporary stack.




#include<stdio.h>

#define SIZE 5
int STACK_A[SIZE];                                   //stack create

int TEMP_STACK_A[SIZE];                              //temp stack create

int top = -1;                                       //setting top for stack
int top_temp = -1;                                 //setting top for temp stack


int isFull(int*);                                  //
int isEmpty(int*);                                 //
void sort(void);                                   //   function prototyping
void push(int stack[SIZE],int item,int* top);       //
void pop(int *top);                                //

int main()                                         //main
{
	int i,tmp;

	printf("ENTER THE ELEMENT IN STACK:\n");
        for(i=0;i<SIZE;i++)
	{
	   scanf ("%d",&tmp);
	   push(STACK_A,tmp,&top);
	}

        printf("\nENTERED ELEMENT IN STACK IS:\n");
	for(i=(SIZE-1);i>=0;i--)
	{
	    printf("%d\n",STACK_A[i]);
	}
	sort();
	printf("\n Sorted Stack ..\n");
        for(i=(SIZE-1);i>=0;i--)
        {
            printf("%d\n",TEMP_STACK_A[i]);
        }



	return 0;
}

int isFull(int *top)                                         //function declaration for checking stack is full or not
{
	if((*top) == (SIZE-1))
	{
		printf("STACK IS FULL | OVERFLOW:\n");
		return 1;
	}
	else
	        return 0;
}

int isEmpty(int *top)                                        //function declaration for checking stack is epty or not
{
	if((*top) == -1)
	{
		return 1;
	}
	else
		return 0;
}

void push(int stack[SIZE],int item,int *top)                 //function declaration for inserting element into stack
{
	if(isFull(top))
	{

	}
	else
	 stack[++(*top)]=item;
}

void pop(int *top)                                            //fucntion declaration for removing element from stack
{
	if(isEmpty(top))
	{

	}
	else
		(*top)--;
}

void sort()                                                  //logic for sort stack using temp stack
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
