
#include<stdio.h>
int main()
{
	int i,j,ch,r,c,count=0,k=0,t=0,col_num=0;
	int sparse[50][50],alter_sparse[50][3],simp_trans[50][3],fast_trans[50][3];
	int row_terms[50],start_pos[50];
	printf("Enter array dimension :");
	scanf("%d %d",&r,&c);
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("enter element at [%d][%d] :",i,j);
			scanf("%d",&sparse[i][j]);
		}
	}
	
	printf("\nYour Sparse Matrix is :\n");
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",sparse[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(sparse[i][j]!=0)
			{
				count++;
			}
		}
	}
	
	//printf("%d",count);
	printf("\n");
	alter_sparse[k][0] = r;
	alter_sparse[k][1] = c;
	alter_sparse[k][2] = count;
	k++;
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(sparse[i][j]!=0)
			{
				alter_sparse[k][0] = i;
				alter_sparse[k][1] = j;
				alter_sparse[k][2] = sparse[i][j];
				k++;
			}
		}
	}
	printf("\nAlternate Representation of the Sparse Matrix :\n");
	for(i=0;i<=count;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",alter_sparse[i][j]);
		}
		printf("\n");
	}
	
	printf("\n		MENU	\n");
	printf("	1.Simple Transpose\n");
	printf("	2.Fast Transpose\n");
	
	printf("\nEnter Your Choice :");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			//t simp_trans[10][3];
			simp_trans[t][0]=c;
			simp_trans[t][1]=r;
			simp_trans[t][2]=count;
			t++;
			for(i=0;i<=alter_sparse[0][1];i++)
			{
				for(j=1;j<=alter_sparse[0][2];j++)
				{
					if(alter_sparse[j][1]==i)
					{
						simp_trans[t][0]=alter_sparse[j][1];
						simp_trans[t][1]=alter_sparse[j][0];
						simp_trans[t][2]=alter_sparse[j][2];
						t++;
					}
					
				}
			}
			
			printf("\nMatrix Using Simple Transpose :\n");
			for(i=0;i<=count;i++)
			{
				for(j=0;j<3;j++)
				{
					printf("%d ",simp_trans[i][j]);
				}
				printf("\n");
			}
			
			break;
		case 2:
			//declare int col_num = 0
			t=0;
			fast_trans[0][0] = c;
			fast_trans[0][1] = r;
			fast_trans[0][2] = count;
			
			for(i=0;i<alter_sparse[0][1];i++)
			{
				row_terms[i]=0;
			}
			
			for(i=0;i<=alter_sparse[0][2];i++)
			{
				col_num = alter_sparse[i][1];
				row_terms[col_num]++;
			}
			
			start_pos[0]=1;
			
			for(i=1;i<alter_sparse[0][1];i++)
			{
				start_pos[i] = start_pos[i-1] + row_terms[i-1];
			}
			
			for(i=1;i<=alter_sparse[0][2];i++)
			{
				col_num = alter_sparse[i][1];
				t = start_pos[col_num];
				start_pos[col_num]++;
				fast_trans[t][0]=alter_sparse[i][1];
				fast_trans[t][1]=alter_sparse[i][0];
				fast_trans[t][2]=alter_sparse[i][2];
			}
			
			printf("\nMatrix Using Fast Transpose\n");
			for(i=0;i<=count;i++)
			{
				for(j=0;j<3;j++)
				{
					printf("%d ",fast_trans[i][j]);
				}
				printf("\n");
			}
			break;
		default:
			printf("Enter Valid Choice");
	}
		
	return 0;	
}
