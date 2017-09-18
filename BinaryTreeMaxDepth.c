/*
 ============================================================================
 Name        : BinaryTreeMaxDepth.c
 Author      : Sreedevi Challavari
 Version     :
 Copyright   : Your copyright notice
 Description : Program to find the maxdepth of a binary tree
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* Defining a node */
struct node
{
	int data;
	struct node* left;
	struct node *right;
};


struct node* GetNewNode(int data)
{
	//allocate memory of the new node
	struct node* tempNode = (struct node*) malloc(sizeof(struct node));

	//enter the data
	tempNode->data = data;

	tempNode->left = NULL;
	tempNode->right = NULL;

	return(tempNode);
}

//allocate the tree with given data and NULL left and right pointers
struct node* Insert(struct node* node, int data)
{
	//if tree is empty
	if (node == NULL)
	{
		node = GetNewNode(data);
	}
	//if given value is lesser, insert to the left subtree
	else if(data <= node->data)
	{
		node->left = Insert(node->left, data);
	}
	//if given value is greater, insert to the right subtree
	else if(data > node->data)
	{
		node->right = Insert(node->right, data);
	}

	return node;
}




/* Recursive function to find the maximum depth of a binary tree */
int maxDepth(struct node *root)
{
	if(root == NULL)
	{
		return -1;
	}
	else
	{
		int lDepth = maxDepth(root->left);
		int rDepth = maxDepth(root->right);
		if (lDepth>rDepth)
			return (lDepth+1);
		else
			return (rDepth+1);
	}
}



int main(void)
{
	
	struct node* rootPtr = NULL;

	rootPtr = Insert(rootPtr,7);
	Insert(rootPtr,2);
	Insert(rootPtr,4);
	Insert(rootPtr,3);
	Insert(rootPtr,5);
	Insert(rootPtr,1);
	Insert(rootPtr,10);
	Insert(rootPtr,8);
	Insert(rootPtr,9);
	Insert(rootPtr,11);
	Insert(rootPtr,12);
	Insert(rootPtr,13);

	printf("Maximum depth of the binary tree is: %d \n",maxDepth(rootPtr));

	return EXIT_SUCCESS;
}
