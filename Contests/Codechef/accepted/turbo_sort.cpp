/*
*	CODE: TSORT 
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
void preOrder( TreeNode *root);

int main()
{
	TreeNode* root = NULL;

	long T;
	cin >> T;

	while(T--)
	{
		long N;
		cin >> N;
		insert(root, N);
	}
	preOrder(root);
}

void insert( TreeNode *&root, int data )
{
	if(root == NULL)
		root = new TreeNode(data);
	else if( data <= root-> value)
		insert(root->left, data );
	else
		insert(root->right, data );
	return;
}

void preOrder(TreeNode* root)
{
	if(root != NULL)
	{
		preOrder(root->left);
		cout << root-> value << endl;
		preOrder(root->right);
	}
}
