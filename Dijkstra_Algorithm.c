#include<stdio.h>
#include<conio.h>
#define max 10

int cost[max][max],start=0;

void print(int place)
{
	switch(place)
	{
		case 0:
			printf("Home");
			break;
		case 1:
			printf("Dhule<-");
			break;
		case 2:
			printf("Jalgaon<-");
			break;
		case 3:
			printf("Nashik<-");
			break;
		case 4:
			printf("College<-");
			break;
		default:
			printf("Enter Valid Choice");
			break;
	}
}

void dijkstra(int n) 
{
  	int path[max][max], distance[max], pred[max];
  	int visited[max], count, min, nextnode, i, j;
  	for (i=0;i<n;i++)
  	{
  		for (j=0;j<n;j++)
  		{
  			if (cost[i][j]==0)
        		path[i][j] = 1000;
      		else
        		path[i][j] = cost[i][j];
		}
	}
    	
	for (i = 0; i < n; i++)
	{
	    distance[i] = path[start][i];
	    pred[i] = start;
	    visited[i] = 0;
	}

  	distance[start] = 0;
  	visited[start] = 1;
  	count = 1;

  	while(count<n-1) 
	{
    	min = 1000;
		for (i=0;i<n;i++)
      		if (distance[i] < min && !visited[i])
			{
        		min = distance[i];
        		nextnode = i;
      		}

    	visited[nextnode] = 1;
    	for (i=0;i<n;i++)
      		if (!visited[i])
        		if (min + path[nextnode][i] < distance[i])
				{
          			distance[i] = min + path[nextnode][i];
          			pred[i] = nextnode;
        		}
    	count++;
  	}
  	
  	// Printing the distance
  	for (i=0;i<n;i++)
  	{
  		if (i!=start)
		{
			
      		printf("\nDistance from source to %d: %d", i, distance[i]);
      		printf("\nPath: ");
      		print(i);
			j=i;
			do{
				j=pred[j];
				print(j);
			}while(j!=start);
			printf("\n");
    	}
  	}
}

int main() 
{
  	int i,j,n;
  	printf("\nEnter how many vertex you want : ");
	scanf("%d",&n);
	printf("\nEnter Source vertex :");
	scanf("%d",&start);
			
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			//printf("\nEnter the Weight of [%d] to [%d]:",i,j);
			scanf("%d",&cost[i][j]);
		}
	}	
	
	printf("\nCost Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",cost[i][j] );
		}
		printf("\n");
	}
	printf("\n Source Vertex : %d\n",start);
	printf("\n 0:Home\n 1:Dhule\n 2:Jalgaon\n 3.Nashik\n 4.College\n");
	
	dijkstra(n);
	
	return 0;
}
