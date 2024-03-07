#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50
int top=-1,i;
int stack[SIZE];

//Defining the push operation
void push(int value)
{
	if(top>=SIZE)
	{
	  printf("Stak is Overflow!\n");
	  return;
	}
	else
	{
		top=top+1;
		stack[top]=value;
	}
}

//Defining the pop operation

int pop()
{
	int value;
	if(top<0)
	{
		printf("Stack is underflow!\n");
	}
	else
	{
		value=stack[top];
		top=top-1;
		return value;
	}
}

//Defining the evaluation function

int evaluate(char postfix[])
{
	int i,ch;
	int result;
	int obj1,obj2;
	
	for(i=0;postfix[i]!=')';i++)
	{
		ch=postfix[i];
		if(isdigit(ch))
		{
			push(ch -'0');
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		{
		  obj2=pop();
		  obj1=pop();
		  
		  switch(ch)
		  {
		    case '*':
			    result=obj2*obj1;
				break; 	
				
			case '/':
			    result=obj2*obj1;
				break;
				
			case '+':
			    result=obj2+obj1;
				break;
				
			case '-':
			    result=obj2-obj1;
				break;
		  }	
		  push(result);
		  
		}
	}
	printf(" \n Result of expression evaluation : %d \n", pop());
}

//checking input for any operator
int is_operator(char symbol)
{
	if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//defining priority according to operator
int priority(char symbol) 
{ 
	if(symbol=='^')
	{
		return 3;
	}
	else if(symbol=='*'||symbol=='/')
	{
		return 2;
	}
	else if(symbol=='+'||symbol=='-')
	{
		return 1;
	}
	else{
		return 0;
	}
} 

//converting infix expression to postfix expression
int convert(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;
	
	push('(');
	
	strcat(infix_exp,")");
	
	i = 0;
	j = 0;
	item = infix_exp[i];
	while(item != '\0')
	{
		if(item=='(')
		{
			push(item);
		}
		else if(isdigit(item)||isalpha(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if(is_operator(item)==1)
		{
			x = pop();
			while(is_operator(x)==1 && priority(x)>= priority(item))
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
			push(x);
			push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x!='(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else{
			printf("\nInvalid Infix Expression");
			getchar();
			exit(1);
		}
		i++;
		item = infix_exp[i];
	}
	
	if(top>0)
	{
		printf("\nInvalid Infix Expression");
		getchar();
		exit(1);
	}
	postfix_exp[j] = '\0';
}

int main()
{
	char infix[SIZE], postfix[SIZE];
	int i,ch;
	printf("\n1.Infix To Postfix \n2.Postfix Evaluation \n3.Exit");
	printf("\nEnter Your Choice :");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			printf("\nEnter Infix Expression :\t");
			scanf("%s",&infix);
			convert(infix,postfix);
			printf("\nPostfix Expression :\t");
			puts(postfix);
			break;
		case 2:
			printf(" \nEnter postfix expression (press '#' for end expression) : ");
			for(i = 0; i<=40; i++) {
		        scanf("%c", &postfix[i]);
		        if (postfix[i] == '#') 
		        {
		            break;
		        } 
		    }
			evaluate(postfix);
			break;
		case 3:
			break;
		default:
			printf("Enter Valid Choice");
			break;
	}

}
