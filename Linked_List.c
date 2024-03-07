#include<stdio.h>
#include<stdlib.h>
typedef struct node{
		int data;
		struct node *link;
}node;
node *create();
void display(node *);
int main()
{	
	int ch;
	node *head=NULL;
	do{
		//printf("\t --Linked List-- \n");
		printf("\n1.Create \n2.Insert \n3.Display \n4.Count \n5.Search \n6.Delete \n7.Reverse \n8.Exit\n\n");
		printf("Enter Your Choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				head = create();
				break;
			case 2:
				head = insert(head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				count(head);
				break;
			case 5:
				search(head);
				break;
			case 6:
				head = removeNode(head);
				break;
			case 7:
				head = reverse(head);
				break;
			case 8:
				
				break;
			default:
				printf("Enter Valid Choice");
				break;
		}
	}while(ch!=8);
	
	return 0;
}

node *create()
{
	node *head=NULL, *prev, *newnode;
	char ch;
	do{
		newnode = (node*)malloc(sizeof(node));
		
		if(newnode==NULL)
		{
			printf("Can't Allocate Memory");
			return 0;
		}		
		printf("Enter Data :");
		scanf("%d",&(newnode->data));
		newnode->link = NULL;
			
		if(head==NULL)
		{
			head = newnode;
			prev = head;
		}
		else
		{
			prev->link = newnode;
			prev = newnode;
		}
		printf("\nWhether To Add Next Node (Y/N) :");
		scanf("%s",&ch);	
	}while(ch=='y');
	
	return head;	
}

int insert(node *head)
{
	node *temp = head, *newnode;
	int pos,cnt=1;
	
	newnode = (node*)malloc(sizeof(node));
	printf("Enter Data :");
	scanf("%d",&(newnode->data));
	newnode->link = NULL;
	
	printf("Enter Position for Node :");
	scanf("%d",&pos);
	
	if(pos==1){
		newnode->link = head;
		head = newnode;
	}
	else{
		while(cnt<pos-1)
		{
			temp = temp->link;
			cnt++;
		}
		
		newnode->link = temp->link;
		temp->link = newnode;
	}
	return head;	
}

void display(node *head)
{
	node *curr = head;
	printf("\nYour Entered Linked List\n");
	printf("\nData\tNext-Link\n");
	while(curr!=NULL)
	{
		printf("%d\t%u\n",curr->data,curr->link);
		curr = curr->link;
	}
}

void count(node *head)
{
	node *curr = head;
	int cnt=0;
	while(curr!=NULL)
	{
		cnt++;
		curr = curr->link;
	}
	printf("\nTotal No. of Nodes are %d\n",cnt);
}

void search(node *head)
{
	node *curr = head;
	int cnt=1,find;
	printf("\nEnter Data to be Search :");
	scanf("%d",&find);
	while(curr!=NULL)
	{
		if(curr->data==find)
		{
			printf("\nData Find at Position %d\n",cnt);
			return;
		}
		cnt++;
		curr = curr->link;
	}
	
	if(curr->link==NULL)
	{
		printf("\nData is not present in the list.\n");
	}
	
	return;
}

int removeNode(node *head)
{
	node *curr, *prev;
	int pos,cnt=1;
	printf("Enter Position of Node to be Deleted :");
	scanf("%d",&pos);
	
	if(pos==1){
		curr = head;
		head = head->link;
		free(curr);
	}
	else{
		prev = head;
		while(cnt<pos-1)
		{
			cnt++;
			prev = prev->link;
		}
		curr = prev->link;
		prev->link = curr->link;
	}
	
	return head;	
}

int reverse(node *head)
{
	node *prev = NULL, *next = NULL;
	
	if(head->link==NULL)
	{
		return "NULL";
	}
	while(head!=NULL)
	{
		next = head->link;
		head->link = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return head;
}
