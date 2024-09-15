#include<stdio.h>
#include<conio.h>
#define max 10
int num2[max];

void mergesort(int low,int high,int num[])
{
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		mergesort(low,mid,num);
		mergesort(mid+1,high,num);
		merge(low,mid,high,num);
	}
}

int merge(int low,int mid,int high,int num[])
{
	int h,i,j,k;
	h=low;
	i=low;
	j=mid+1;
	while((h<=mid)&&(j<=high))
	{
		if(num[h]<=num[j])
		{
			num2[i]=num[h];
			h++;
		}
		else{
			num2[i]=num[j];
			j++;
		}
		i++;
	}
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			num2[i]=num[k];
			i++;
		}
	}
	else{
		for(k=h;k<=mid;k++)
		{
			num2[i]=num[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
	{
		num[k]=num2[k];
	}
	return;
}

int main()
{
	int num[max],i,n;
	printf("\nEnter Total No. of Elements :");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter Element :");
		scanf("%d",&num[i]);
	}
	
	printf("\nEntered Elements :\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d\t",num[i]);
	}
	
	printf("\n\nPerforming Merge Sort...\n");
	mergesort(0,n,num);
	printf("\n\nSorted Elements :\n");
	
	for(i=1;i<=n;i++)
	{
		printf("%d\t",num[i]);
	}
	
	return 0;
}
