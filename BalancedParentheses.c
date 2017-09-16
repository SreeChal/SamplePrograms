/*
 ============================================================================
 Name        : PracticeBalancedParentheses.c
 Author      : Sreedevi Challavari
 Version     :
 Copyright   : Your copyright notice
 Description : Program to check Balanced Parentheses in a given expression
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
	char data;
	struct node *next;
};

struct node *top = NULL;

#define MAX_SIZE 100
char A[MAX_SIZE];


void push(char c)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = c;
	temp->next = top;
	top = temp;
}

void pop()
{
	if(top == NULL)
	{
		printf("\n Stack is Empty\n");
		return;
	}
	struct node *temp = top;
	top = temp->next;
	free(temp);
	return;
}

char Top()
{
	return top->data;
}

int IsEmpty()
{
	if (top == NULL)
		return 1;
	return 0;
}

void display()
{
	printf("\n The Stack is: ");

	struct node* temp = top;

	while(temp != NULL)
	{
		printf("%c ", temp->data);
		temp=temp->next;
	}

	printf("\n");
}

bool checkmatch(char x)
{
	if (x == ')' && top->data == '(')
		return true;
	else if (x == ']' && top->data == '[')
		return true;
	else if (x == '}' && top->data == '{')
		return true;
	return false;
}


//bool checkBalParentheses(char A[], int n)
bool checkBalParentheses(char A[])
{
	int i,n;
	n = strlen(A);
//	printf ("\n Size of string in function : %d ", n);
/*
	for(i=0; A[i] != '\0'; i++)
	{
		push(A[i]);
	}
	*/


	for(i=0; i<n; i++)
	{
		if(A[i] == '(' || A[i] == '[' || A[i] == '{')
		{
			push(A[i]);
		}
		else if ((A[i] == ')' || A[i] == ']' || A[i] == '}'))
		{
			if((top == NULL) || (!checkmatch(A[i])))
				return false;
			pop();
		}
	}





	if (top == NULL)
			return true;
		return false;
}



int main(void)
{

//	printf("\n Checking Balanced Parentheses \n");

	printf("Enter an expression with parentheses: ");
	fflush(stdout);
	gets(A);

//	char B [10] = {'(','{','}','[',']',')'} ;
//	printf ("Size: %d ", strlen(B));


//	if(checkBalParentheses(B, strlen(B)))
	if(checkBalParentheses(A))
	{
		printf("\n Parentheses is balanced \n");
	}
	else
		printf("\n Parentheses is unbalanced \n");

	return EXIT_SUCCESS;
}
