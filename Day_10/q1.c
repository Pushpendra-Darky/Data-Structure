// linear SEARCH 




#include<stdio.h>

int main()
{
	int i=0,key,loc,array[10];
	int count=0;

	printf("\nENTER THE ARRAY ELEMENT:\n");
	for(i=0;i<10;i++)
	{
		printf("\n[%d] = ",i);
		scanf("%d",&array[i]);
	}

	for(i=0;i<10;i++)
	{
		printf("[%d] = %d\n",i,array[i]);
	}

	printf("\nENTER THE NUMBER TO SERACH BY LINEAR SEARCH ALGORITHM:\n");
	scanf("%d",&key);

	for(i=0;i<10;i++)
	{
		if(key == array[i])
		{
			count=1;
			loc = i;
		}
	}

	if(count=1)
	{
		printf("%d found at [%d] index\n",key,loc);
	}
	else if(count=0)
	{
		printf("%d not found in array.\n",key);
	}


}
