/* q1--
         Imlement Hash Table Data Structures with following three basic operations  using Open Addressing (Linear Probing). Implementations must resolve the expected collisions.

         1. insert (i):  Insert ‘i’ in to the hash table
         2. find(i): Find item with key ‘i’
         3. remove(i): delete ‘i’ from the hash table

          Write the Test  code to check the working of the program.
	  */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 6
enum student_status_type {EMPTY,DELETED,OCCUPIED};
struct student
{
	int r_no;
	char name[10];
};
struct student_record
{
	struct student info;
	enum student_status_type status;
};

void insert_student(struct student s, struct student_record table[]);
int find_student(int key, struct student_record table[]);
void remove_student(int key, struct student_record table[]);
void display_table(struct student_record table[]);
int hash(int key);

int main()
{
	struct student_record table[SIZE];
	struct student s;
	int key,ch,i;

	for(i=0;i<=(SIZE-1);i++)
	{
		table[i].status= EMPTY;
	}

	while(1)
	{
		printf("\n1.INSERT THE KEY.\n");
		printf("2.FIND THE KEY.\n");
		printf("3.REMOVE THE KEY.\n");
		printf("4.DISPLAY THE TABLE.\n");
		printf("5.EXIT.\n");

		printf("\nENTER THE CHOICE: \n");
		scanf("%d",&ch);
		printf("\n");

		switch(ch)
		{
			case 1:
				printf("\nENTER ROLL NO:\n");
				scanf("%d",&s.r_no);
				printf("ENTER NAME:\n");
				scanf("%s",s.name);
				insert_student(s,table);
				break;
			case 2:
				printf("\nENTER A KEY TO BE SEARCHED: ");
				scanf("%d",&key);
				i=find_student(key,table);
				if(i == -1)
				{
					printf("\nKEY NOT FOUND.\n");
				}
				else
					printf("\nKEY FOUND ON INDEX [%d]\n",i);
				break;
			case 3:
				printf("\nENTER THE KEY TO BE SEARCHED: ");
				scanf("%d",&key);
				remove_student(key,table);
				break;
			case 4:
				display_table(table);
				break;
			case 5:
				exit(1);
			default :
				printf("ENTER VALID CHOICE.\n");
		}
		
	}

	return 0;
}

int hash(int key)
{
	return (key % SIZE);
}

void insert_student(struct student s, struct student_record table[])
{
	int i,key,h,location;
	key = s.r_no;
	h= hash(key);
	location = h;

	for(i=1;i!=(SIZE-1);i++)
	{
		if(table[location].status == EMPTY || table[location].status == DELETED)
		{
			table[location].info= s;
			table[location].status= OCCUPIED;
		        printf("\nRECORD INSERTED.\n");
			return;
		}
		if(table[location].info.r_no == key)
		{
			printf("\nDUPLICATE KEY\n");
			return;
		}
	   location= (h+i) % SIZE;
	 }
	printf("\nRECORD CAN'T BE INSERTED: TABLE OVERFLOW.\n");
}

int find_student(int key, struct student_record table[])
{
	int i,h,location;
	h = hash(key);
	location = h;

	for(i=1; i != (SIZE-1);i++)
	{
		if(table[location].status == EMPTY)
		{
			return -1;
		}
		if(table[location].info.r_no == key)
		{
			return location;
		}
		location = (h+i) % SIZE;
	}
	return -1;
}

void remove_student(int key, struct student_record table[])
{
	int location = find_student(key,table);
	if(location == -1)
	{
		printf("\nKEY NOT FOUND.\n");
	}
	else
	{
		table[location].status = DELETED;
		printf("RECORD IS DELETED.\n");
	}
}

void display_table(struct student_record table[])
{
	int i;
	for(i=0; i<SIZE; i++)
	{
		printf("[%d] : ",i);
		if(table[i].status == OCCUPIED)
		{
			printf("OCCUPIED: %d  %s\n",table[i].info.r_no,table[i].info.name);
		}
		else if(table[i].status == DELETED)
		{
			printf("DELETED\n");
		}
		else
		{
			printf("EMPTY\n");
		}
	}
}
