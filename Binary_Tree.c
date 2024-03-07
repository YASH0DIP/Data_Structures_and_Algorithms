#include<stdio.h>
#include<conio.h>
#define max 50
typedef struct tnode{
	int data;
	struct tnode *lchild, *rchild;
}node;

int m = 0;//for the tree height function

node *create()
{
	int val;
	node *newnode;
	newnode = (node *)malloc(sizeof(node));
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	printf("\nEnter Data (if you don't want to add next node then enter 0):");
	scanf("%d",&val);
	
	if(val==0)
	{
		return NULL;
	}
	
	newnode->data = val;
	
	printf("\nEnter Left Child of %d\n",val);
	newnode->lchild = create();
	
	printf("\nEnter Right Child of %d\n",val);
	newnode->rchild = create();
	
	return newnode;
}

void preorder(node *root)
{
	if(root!=NULL){
		printf("%d\n",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}

}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%d\n",root->data);
		inorder(root->rchild);
	}
}

void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d\n",root->data);
	}
}

node *mirror(node *root)
{
	node *temp;
	if(root!=NULL)
	{
		mirror(root->lchild);
		mirror(root->rchild);
		temp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = temp;
	}
	return root; 
}

int theight(node *root,int level)
{
	if(root!=NULL)
	{
		theight(root->lchild,level+1);
		theight(root->rchild,level+1);	
	}
	
	if(level>m)
		m = level;
	
	return m-1;
}

void level_wise(node *root)
{
	node *dummy = (node *)malloc(sizeof(node));
	dummy->lchild = root;
	dummy->rchild = NULL;
	node *q[max], *temp;
	int front=0,rear=0;
	q[rear] = root;
	rear++;
	q[rear] = dummy;
	rear++;
	temp = q[front];
	front++;
	if(root!=NULL)
	{
		while(front!=rear)
		{
			if(temp!=dummy)
			{
				printf("%d ",temp->data);
				if(temp->lchild!=NULL)
				{
					q[rear] = temp->lchild;
					rear++;
				}
				if(temp->rchild!=NULL)
				{
					q[rear] = temp->rchild;
					rear++;
				}
			}
			else{
				q[rear] = dummy;
				rear++;
				printf("\n");
			}
			temp = q[front];
			front++;
		}
	}
}

void leafnodes(node *root)
{
	if(root!=NULL)
	{
		leafnodes(root->lchild);
		
		leafnodes(root->rchild);
		
		if(root->lchild==NULL && root->rchild==NULL)
		{
			printf("%d\n",root->data);
		}
	}
}

int main()
{
	node *root = NULL;
	int ch,level,height,i;
	do{
		printf("\n1.Create \n2.Display(preorder) \n3.Display(inorder) \n4.Display(postorder)");
		printf("\n5.Mirror \n6.Height of Tree \n7.LeafNodes \n8.Level Wise Printing \n9.Exit");
		printf("\n\nEnter Your Choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				root = create();
				break;
			case 2:
				printf("\nYour Entered Tree :\n");
				preorder(root);
				break;
			case 3:
				printf("\nYour Entered Tree :\n");
				inorder(root);
				break;
			case 4:
				printf("\nYour Entered Tree :\n");
				postorder(root);
				break;
			case 5:
				root = mirror(root);
				printf("\nTree Node are Mirrored Succesfully\n");
				break;
			case 6:
				height = theight(root,0);
				printf("\nHeight of Your Tree : %d\n",height);
				break;
			case 7:
				printf("\nLeaf Nodes of the tree are :\n");
				leafnodes(root);
				break;
			case 8:
				printf("\nLevel Wise Printing :\n");
				level_wise(root);
				printf("\n");
				break;
			case 9:
				exit(0);
				break;
			default:
				printf("\nEnter Valid Choice!");
				break;
		}
	}while(ch!=9);
	
	return 0;
}
