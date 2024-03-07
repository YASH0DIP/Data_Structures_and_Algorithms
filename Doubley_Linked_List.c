#include<stdio.h>
#include<stdlib.h>
typedef struct node{
		char cname[10];
		char cmodel[10];
	    int year;
		int cprice;
		struct node *llink, *rlink;		
}node;

node *create();
void display(node *);
int insert(node *);
int update(node *);

int main()
{	
	int ch;
	node *head=NULL;
	do{
		
		printf("\n1.Create \n2.Insert \n3.Display \n4.Update Price \n5.Find Within Range \n6.Delete \n7.Exit\n\n");
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
				head = update(head);
				break;
			case 5:
				find_within_range(head);
				break;
			case 6:
				head = removeNode(head);
				break;
			case 7:
				break;
			default:
				printf("Enter Valid Choice!");
				break;
		}
	}while(ch!=7);
	
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
		printf("\nEnter Car Company Name :");
		scanf("%s",&(newnode->cname));
		printf("Enter Car Model :");
		scanf("%s",&(newnode->cmodel));
		printf("Enter Car Price :");
		scanf("%d",&(newnode->cprice));
		printf("Enter Car Year :");
		scanf("%d",&(newnode->year));
		newnode->llink = NULL;
		newnode->rlink = NULL;
			
		if(head==NULL)
		{
			head = newnode;
			prev = head;
		}
		else
		{
			prev->rlink = newnode;
			newnode->llink = prev;
			prev = newnode;
		}
		printf("\nWhether To Add Next Node (Y/N) :");
		scanf("%s",&ch);	
	}while(ch=='y');
	
	return head;	
}


int insert(node *head)
{
	node *curr = head, *newnode;
	int pos,cnt=1;
	
	newnode = (node*)malloc(sizeof(node));
	printf("\nEnter Car Company Name :");
	scanf("%s",&(newnode->cname));
	printf("Enter Car Model :");
	scanf("%s",&(newnode->cmodel));
	printf("Enter Car Price :");
	scanf("%d",&(newnode->cprice));
	printf("Enter Car Year :");	
	scanf("%d",&(newnode->year));
	newnode->llink = NULL;
	newnode->rlink = NULL;
	
	printf("\nEnter Position for Node :");
	scanf("%d",&pos);
	
	if(pos==1)
	{
		newnode->rlink = head;
		head->llink = newnode;
		head = newnode;
	}
	else
	{
		while(cnt<pos-1)
		{
			curr = curr->rlink;
			cnt++;
		}
		
		if(curr->rlink!=NULL)
		{
			(curr->rlink)->llink = newnode;
		}
		newnode->rlink = curr->rlink;
		newnode->llink = curr;
		curr->rlink = newnode;
	}
	
	return head;	
}

void display(node *head)
{
	node *curr = head;
	//printf("\nYour Entered Linked List\n");
	printf("\n\nCompany\tModel\tPrice\tYear\n");
	while(curr!=NULL)
	{
		printf("%s\t%s\t%d\t%d\n",curr->cname,curr->cmodel,curr->cprice,curr->year);
		curr = curr->rlink;
	}
}

int removeNode(node *head)
{
	node *curr = head;
	int cnt=1;
	char model[20];
	printf("Enter Car Model to be Deleted :");
	scanf("%s",&model);
	
	
	while(curr!=NULL)
	{
		if(strcmp(curr->cmodel,model)==0)
		{
			if(cnt==1)
			{
				head = head->rlink;
				head->llink = NULL;
				free(curr);
			}
			else{
				if(curr->rlink!=NULL)
				{
					(curr->rlink)->llink = curr->llink;
				}
				(curr->llink)->rlink = curr->rlink;
				free(curr);
			}
		}
		cnt++;
		curr = curr->rlink;
	}
	return head;	
}

int update(node *head)
{
	node *curr = head;
	int price;
	char model[20];
	
	
	printf("\nEnter Car Model Where You Want To Change Car Price :");
	scanf("%s",&model);
	
	while(curr!=NULL)
	{
		if(strcmp(curr->cmodel,model)==0)
		{
			printf("\nEnter New Car Price :");
			scanf("%d",&price);
			curr->cprice = price;
			break;
		}
		curr=curr->rlink;
	}
	return head;
}


void find_within_range(node *head)
{
	node *curr = head;
	int lprice,bprice;
	
	
	printf("\nEnter Lowest Price :");
	scanf("%d",&lprice);
	printf("\nEnter Budget Price :");
	scanf("%d",&bprice);
	
	printf("\nAll Cars Within Entered Range :\n");
	printf("\nCompany\tModel\tPrice\tYear\n");
	
	while(curr!=NULL)
	{
		if(curr->cprice>=lprice && curr->cprice<=bprice)
		{
			printf("%s\t%s\t%d\t%d\n",curr->cname,curr->cmodel,curr->cprice,curr->year);
		}
		curr=curr->rlink;
	}
}

