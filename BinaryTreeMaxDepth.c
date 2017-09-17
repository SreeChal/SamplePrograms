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

//allocate the tree with given data and NULL left and right pointers

struct node* newNode(int data)
{
	//allocate memory of the new node
	struct node* tempNode = (struct node*) malloc(sizeof(struct node));

	//enter the data
	tempNode->data = data;

	tempNode->left = NULL;
	tempNode->right = NULL;

	return(tempNode);
}



int main(void)
{
	//create the root node
	struct node *root = newNode(1);

	root->left =  newNode(2);
	root->right =  newNode(3);

	//creating branches and leaves
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	root->left->left->left = newNode(10);
	root->left->left->right = newNode(11);

	root->left->left->left->left = newNode(12);
	root->left->left->left->right = newNode(13);


	root->right->left = newNode(6);
	root->right->right = newNode(7);

	root->right->left->left = newNode(8);
	root->right->left->right = newNode(9);


	printf("Maximum depth of the binary tree is: %d",maxDepth(root));

	return EXIT_SUCCESS;
}
