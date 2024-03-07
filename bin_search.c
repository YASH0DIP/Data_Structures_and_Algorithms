#include<stdio.h>
#include<conio.h>

typedef struct student{
	int rollno;
	char name[10];
	float per;
}student;

void binsearch(student *stud,int roll,int cnt)
{
	int low=0, high=cnt, mid,found=0;
	do{
		mid = (low+high)/2;
		if(roll==stud[mid].rollno)
		{
			printf("\nRecord Found at %dth position",mid);
			printf("\nName: %s",stud[mid].name);
			printf("\nPercentage: %f\n",stud[mid].per);
			found=1;
			break;
		}
		else if(roll<stud[mid].rollno)
		{
			high = mid-1;
		}
		else{
			low = mid+1;
		}	
	}while(low<=high);
	
	if(found==0){
		printf("\nRecord Not Found\n");
		return;
	}
}

int main()
{
	int i=1,cnt=1,roll;
	student *stud = (student*)malloc(sizeof(student));
	char ch,ch1;
	do{
		printf("\nEnter Student Name :");
		scanf("%s",&stud[i].name);
		printf("\nEnter Student Roll No. :");
		scanf("%d",&stud[i].rollno);
		printf("\nEnter Student Percentage :");
		scanf("%f",&stud[i].per);
		i++;
		printf("\n\nWant to enter next student data(y/n) :");
		scanf("%s",&ch);
		if(ch=='y')
			cnt++;
	}while(ch=='y');
	
	printf("\nName\tRoll No.\tPercentage");
	printf("\n------------------------------------");
	for(i=1;i<=cnt;i++)
	{
		printf("\n%s\t%d\t\t%f",stud[i].name,stud[i].rollno,stud[i].per);
	}
	
	printf("\n");
	
	do{
		printf("\nEnter Roll No. To Be Search :");
		scanf("%d",&roll);
		printf("\nPerforming Binary Search...\n");
		binsearch(stud,roll,cnt);
		
		printf("\nWant to search again(y/n) :");
		scanf("%s",&ch1);
	}while(ch1=='y');
	return 0;
}
