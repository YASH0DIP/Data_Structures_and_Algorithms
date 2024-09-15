#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct student{
	int rollno;
	char name[10];
	float per;
}student;

int n;
student *stud, *temp;

void bubble()
{
	int last = n;
	int exchs,i,j,temp_roll;
	char temp_name[10];
	float temp_per;
	for(i=1;i<n;i++)
	{
		exchs = 0;
		for(j=1;j<last;j++)
		{
			if(stud[j].per<stud[j+1].per)
			{
				//swap name
				strcpy(temp_name,stud[j].name);
				strcpy(stud[j].name,stud[j+1].name);
				strcpy(stud[j+1].name,temp_name);
				
				//swap rollno
				temp_roll = stud[j].rollno;
				stud[j].rollno = stud[j+1].rollno;
				stud[j+1].rollno = temp_roll;
				
				//swap percentage
				temp_per = stud[j].per;
				stud[j].per = stud[j+1].per;
				stud[j+1].per = temp_per;
				
				exchs++;
			}
		}
		if(exchs==0)
		{
			return;
		}
		else{
			last = last-1;
		}
	}
}

int main()
{
	int i=1,toppers;
	stud = (student*)malloc(sizeof(student));
	char ch,ch1;
	printf("\nTotal No. of Students :");
	scanf("%d",&n);
	printf("----------------------------------------\n");
	do{
		printf("\nEnter Student Name :");
		scanf("%s",&stud[i].name);
		printf("\nEnter Student Roll No. :");
		scanf("%d",&stud[i].rollno);
		printf("\nEnter Student Percentage :");
		scanf("%f",&stud[i].per);
		printf("----------------------------------------\n");
		i++;
	}while(i<=n);
	
	printf("\nName\tRoll No.\tPercentage");
	printf("\n------------------------------------");
	for(i=1;i<=n;i++)
	{
		printf("\n%s\t%d\t\t%f",stud[i].name,stud[i].rollno,stud[i].per);
	}
	printf("\n");
	printf("\nPerforming Bubble Sorting...\n");
	
	bubble();
	
	printf("\nNumber of Toppers :");
	scanf("%d",&toppers);
	printf("\nName\tRoll No.\tPercentage");
	printf("\n------------------------------------");
	for(i=1;i<=toppers;i++)
	{
		printf("\n%s\t%d\t\t%f",stud[i].name,stud[i].rollno,stud[i].per);
	}
	
	return 0;
}
