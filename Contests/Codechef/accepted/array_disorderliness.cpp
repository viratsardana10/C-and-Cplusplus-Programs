/*
*	CODE: INSOMA3
*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct TreeNode {
	int right_count;
	int value;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) {
		right_count = 0;
		value = data;
		left = NULL;
		right = NULL;
	}
};

void insert( TreeNode *&root, int );


TreeNode *ptr = NULL;
bool flag = true;

int main()
{
	TreeNode *root = NULL;
	int count = 0;

	int n;
	fscanf(stdin, "%d", &n);

	for(int i = 0 ; i < n; ++i)
	{
		int data;
		fscanf(stdin, "%d", &data);
		insert(root, data);
		if( ptr != NULL )
		{
			count += ptr->right_count;
			++count;
		}
		ptr = NULL;
		flag = true;
	}
	fprintf(stdout, "%d\n", count);
	return 0;
}

void insert( TreeNode *&root, int data )
{
	if(root == NULL)
		root = new TreeNode(data);
	else if( data < root-> value)
	{
		if(flag) {
			ptr = root;
			flag = false;	
		}
		insert(root->left, data );
	}
	else
	{	
		root->right_count += 1;
		insert(root->right, data );
	}
	return;
}

