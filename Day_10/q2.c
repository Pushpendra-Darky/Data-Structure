// binary search


#include<stdio.h>

int bs(int [],int,int);
int main()

{
	int i,j,temp,n,a[30];
	int item,index;

        printf("Enter the array size:\n");
        scanf("%d",&n);

        printf("\nEnter the element in array:\n");
        for(i=0;i<n;i++)
	{
            scanf("%d",&a[i]);
	}

        for(i=0;i<n;i++)
	{
		for (j=(i+1);j<n;j++)
		{
			if(a[i] > a[j])
			{
				temp =  a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("array element sorting in ascending order:\n");
	for (i=0;i<n;i++)
	{
		printf("[%d] = %d\n",i,a[i]);
	}

	printf("Enter the element to be searched by binary search in array:\n");
	scanf("%d",&item);
	
	index = bs(a,n,item);
	if(index == -1)
	{
		printf("%d not in array.\n",item);
	}
	else
	{
		printf("%d found at array[%d].\n",item,index);
	}



	return 0;
}

int bs(int a[],int n,int item)
{
	int start=0,end=n-1,mid;

	while(start<=end)
	{
		mid = (start+end)/2;
		if(item>a[mid])
		{
			start=mid+1;     //search in right half
		}
		else if(item<a[mid])
		{
			end=mid-1;      //search in left half
		}
		else
			return mid;
	}
	return -1;
}
