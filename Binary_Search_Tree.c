#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct bstnode{
	char name[50];
	char phone[50];
	struct bstnode *lchild, *rchild;
}node;

node *dnode, *pardnode;

node *insert(node *root,char uname[50], char uphone[50])
{
	int found = 0;
	node *p = root,*parent;
	while((p!=NULL) && (!found))
	{
		parent = p;
		if(strcmp(uname,root->name)==0)
		{
			found == 1;
		}
		else if(strcmp(uname,p->name)>0)
		{
			p = p->rchild;
		}
		else{
			p = p->lchild;
		}
	}
	
	if(!found)
	{
		p = (node *)malloc(sizeof(node));
		p->lchild = NULL;
		p->rchild = NULL;
		strcpy(p->name,uname);
		strcpy(p->phone,uphone);
	}
	
	if(root!=NULL)
	{
		if(strcmp(p->name,parent->name)>0)
		{
			parent->rchild = p;
		}
		else{
			parent->lchild = p;
		}
	}
	else{
		root = p;
	}
	
	return root;
}

//inorder
void display_inorder(node *root)
{
	if(root!=NULL)
	{
		display_inorder(root->lchild);
		printf("%s\t%s\n",root->name,root->phone);
		display_inorder(root->rchild);
	}
}

//preorder
void display_preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%s\t%s\n",root->name,root->phone);
		display_inorder(root->lchild);
		display_inorder(root->rchild);
	}
}

//postorder
void display_postorder(node *root)
{
	if(root!=NULL)
	{
		display_inorder(root->lchild);
		display_inorder(root->rchild);
		printf("%s\t%s\n",root->name,root->phone);
	}
}

node *search(node *root, char uname[])
{
	dnode = root;
	while(dnode!=NULL && strcmp(dnode->name,uname)!=0)
	{
		pardnode = dnode;
		if(strcmp(dnode->name,uname)>0)
		{
			dnode = dnode->lchild;
		}
		else{
			dnode = dnode->rchild;
		}
	}
}
node *delcaseA(node *root,node *dnode,node *pardnode)
{
	node *child;
	if(dnode->lchild==NULL && dnode->rchild==NULL)
	{
		child = NULL;
	}
	else if(dnode->lchild!=NULL)
	{
		child = dnode->lchild;
	}
	else{
		child = dnode->rchild;
	}
	
	if(pardnode!=NULL)
	{
		if(dnode==pardnode->lchild)
		{
			pardnode->lchild = child;
		}
		else{
			pardnode->rchild = child;
		}
	}
	else{
		root = child;
	}
}

node *delcaseB(node *root, node *dnode, node *pardnode)
{
	node *p = dnode->rchild;
	node *q = dnode,*succ, *parsucc;
	
	while(p->lchild!=NULL)
	{
		q = p;
		p = p->lchild;
	}
	succ = p;
	parsucc = q;
	delcaseA(root,succ,parsucc);
	if(pardnode != NULL)
	{
		if(dnode == pardnode->lchild)
		{
			pardnode->lchild = succ;
		}
		else{
			pardnode->rchild = succ;
		}
	}
	else{
		root = succ;
	}
	succ->lchild = dnode->lchild;
	succ->rchild = dnode->rchild;
}

node *bstdel(node *root,char uname[50])
{
	search(root,uname);
	if(dnode==NULL)
	{
		printf("\nNot Found");
		return;
	}
	if(dnode->rchild!=NULL && dnode->lchild!=NULL)
	{
		delcaseB(root,dnode,pardnode);
	}
	else{
		delcaseA(root,dnode,pardnode);
	}
	free(dnode);
}

int main()
{
	node *root = NULL;
	char uname[50], uphone[50];
	int ch,res;
	char next;
	do{
		printf("\n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit");
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				do{
					printf("\nEnter Name :");
					scanf("%s",&uname);
					printf("\nEnter Phone Number :");
					scanf("%s",&uphone);
					root = insert(root, uname, uphone);
					printf("\nyou want to enter next node? (y/n) :");
					scanf("%s",&next);
				}while(next!='n');
				break;
			case 2:
				printf("\nDisplaying in Inorder Sequence:\n");
				display_inorder(root);
				break;
			case 3:
				printf("\nEnter Name to be search for :");
				scanf("%s",&uname);
				search(root,uname);
				if(dnode!=NULL)
				{
					printf("\n%s\t%s\n",dnode->name,dnode->phone);
				}
				else{
					printf("\nNot Found\n");
				}
				break;
			case 4:
				printf("Enter The Name to be Deleted :");
				scanf("%s",&uname);
				bstdel(root,uname);
				break;
			case 5:
				break;
			default:
				printf("\nEnter Valid Choice!");
				break;
		}
	}while(ch!=5);
}
