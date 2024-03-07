#include<stdio.h>
#include<conio.h>

int adj_mat[20][20], visited[20];
int start,n,m,k;
int queue[20];
int front=0,rear=0;

void print(int element)
{
	switch(element)
	{
		case 0:
			printf("Jatra Hotel -> %d\n",element);
			break;
		case 1:
			printf("Bali Mandir -> %d\n",element);
			break;
		case 2:
			printf("KK Wagh College -> %d\n",element);
			break;
		case 3:
			printf("Amrutdham -> %d\n",element);
			break;
		default:
			printf("\n");
			break;
	}
}

int bfs(int s)
{
	print(s);
	//printf("%d",s);
	visited[s] = 1;
	queue[rear] = s;
	rear++;
	while(front!=rear)
	{
		int curr = queue[front];
		front++;
		for(k=0;k<n;k++)
		{
			if(visited[k]==0 && adj_mat[curr][k]==1)
			{
				print(k);
				//printf("%d",k);
				visited[k]=1;
				queue[rear] = k;
				rear++;
			}
		}
	}
}

int dfs(int s)
{	
	visited[s] = 1;
	print(s);
	//printf("%d",s);
	for(k=0;k<n;k++)
	{
		for(m=0;m<n;m++)
		{
			if(visited[m]==0 && adj_mat[s][m]==1)
			{
				dfs(m);
			}	
		}
	}
}

int main()
{
	int i,j,meth;
	printf("\nEnter the total number of nodes :");
	scanf("%d",&n);
	
	printf("\nEnter Starting Vertex :");
	scanf("%d",&start);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\nEnter Element at [%d][%d] :",i,j);
			scanf("%d",&adj_mat[i][j]);
		}
	}
	printf("\nElements in the Matrix are :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",adj_mat[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<=n;i++)
	{
		visited[i] = 0;
	}
	
	printf("\n1.Breadth First Search \n2.Depth First Search\n");
	printf("\nWhich of the above search method you want to perform :");
	scanf("%d",&meth);
	switch(meth)
	{
		case 1:
			printf("\n");
			bfs(start);
			break;
		case 2:
			printf("\n");
			dfs(start);
			break;
		default:
			printf("Enter Valid Chioce");
			break;
	}
	
	return 0;	
}
