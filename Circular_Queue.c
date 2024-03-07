#include<stdio.h>
#include<conio.h>
#define max 20
int cqueue[max];
int front=-1,rear=-1;

is_full()
{
	if((rear==max-1 && front==0)||(rear+1==front))
		return 1;
	else
		return 0;
}

int is_empty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}

int qinsert(int element)
{
	if(is_full())
	{
		printf("\nCircular Queue is Full");
		return;
	}
		
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		if(rear==max-1)
		{
			rear = 0;
		}
		else{
			rear++;
		}
	}
	cqueue[rear] = element;
}

int qdelete()
{ 
	int element;
	if(is_empty())
	{
		printf("\nCircular Queue is Empty");
		return;
	}
	
	element = cqueue[front];
	
	if(front==rear)
	{
		front = -1;
		rear = -1;
	}
	else{
		if(front==max-1)
		{
			front=0;
		}
		else{
			front++;
		}
	}
	return element;
}

void display()
{
	int i=front,j=rear;
	if(is_empty())
	{
		printf("Queue is Empty");
		return;
	}
	printf("\nElements in Circular Queue:\t");
	if(i<=j)
	{
		while(i<=j)
		{
			printf("%d\t",cqueue[i]);
			i++;
		}
	}
	else
	{
		while(i<=max-1)
		{
			printf("%d\t",cqueue[i]);
			i++;
		}
		
		i=0;
		
		while(i<=j)
		{
			printf("%d\t",cqueue[i]);
			i++;
		}
	}
	printf("\n");
}

int main()
{
	int element,ch;
	do{
		printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter Element: ");
				scanf("%d",&element);
				qinsert(element);
				break;
			case 2:
				element = qdelete();
				printf("\nDeleted Element %d",element);
				break;
			case 3:
				display();
			case 4:
				break;
			default:
				printf("Enter Valid Choice!");
				break;
		}
	}while(ch!=4);
	return 0;
}
