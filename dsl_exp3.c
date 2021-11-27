//ADITYA WAGH 65 IT   
//DSL Exp 3

#include<stdio.h>
#include<stdlib.h>    
#include<ctype.h>    
#include<string.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

/*operator defining*/
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

/*precendence to operator.*/
  int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
/*push operation*/
void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\n Stack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

/*pop operation*/
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow");
		getchar();
		/* underflow may occur for invalid expression */
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                  
	strcat(infix_exp,")");      

	i=0;
	j=0;
	item=infix_exp[i];         

	while(item != '\0')        
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;         
			j++;
		}
		else if(is_operator(item) == 1)    
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
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
			while(x != '(')                 
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{   /* if symbol is neither operand not '(' nor ')' and nor operator */
			printf("\nWrong infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; 
	} 
	if(top>0)
	{
		printf("\nWrong infix Expression.\n");  
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nWrong infix Expression.\n");        
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; 
}

/*main function begins*/
int main()
{
	char infix[SIZE], postfix[SIZE];  

	printf("\n Enter Infix expression : ");
	gets(infix);

	InfixToPostfix(infix,postfix);                   
	printf(" The Postfix Expression: ");
	puts(postfix);                     

	return 0;
}
