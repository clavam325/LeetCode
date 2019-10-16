#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// A binary Tree node
struct node
{
	int data;
	struct node *left, *right;
};

/* Recursive function to print all the nodes at distance k in the
tree (or subtree) rooted with given root. See */
void printkdistanceNodeDown(node *root, int k)
{
	// Base Case
	if (root == NULL || k < 0) return;

	// If we reach a k distant node, print it
	if (k==0)
	{
		cout << root->data << endl;
		return;
	}

	// Recur for left and right subtrees
	printkdistanceNodeDown(root->left, k-1);
	printkdistanceNodeDown(root->right, k-1);
}

// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward. This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int printkdistanceNode(node* root, node* target , int k)
{
	// Base Case 1: If tree is empty, return -1
	if (root == NULL) return -1;

	// If target is same as root. Use the downward function
	// to print all nodes at distance k in subtree rooted with
	// target or root
	if (root == target)
	{
	    cout << "Reached Node" << root->data<<endl;
		printkdistanceNodeDown(root, k);
		return 0;
	}

	cout << "Curr Node is " << root->data << endl;

	// Recur for left subtree
	int dl = printkdistanceNode(root->left, target, k);

	// Check if target node was found in left subtree
	if (dl != -1)
	{
		// If root is at distance k from target, print root
		// Note that dl is Distance of root's left child from target
		if (dl + 1 == k)
			cout << root->data << endl;

		// Else go to right subtree and print all k-dl-2 distant nodes
		// Note that the right child is 2 edges away from left child
		else
			printkdistanceNodeDown(root->right, k-dl-2);

		// Add 1 to the distance and return value for parent calls
		return 1 + dl;
	}

	// MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
	// Note that we reach here only when node was not found in left subtree
	int dr = printkdistanceNode(root->right, target, k);
	if (dr != -1)
	{
		if (dr + 1 == k)
			cout << root->data << endl;
		else
			printkdistanceNodeDown(root->left, k-dr-2);
		return 1 + dr;
	}

	// If target was neither present in left nor in right subtree
	return -1;
}

// A utility function to create a new binary tree node
node *newnode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	/* Let us construct the tree shown in above diagram */
	vector<int>* vec;

	vec = new vector<int> (10,0);
    delete vec;

	node * root = newnode(3);
	root->left = newnode(5);
	root->right = newnode(1);
	root->left->left = newnode(6);
	root->left->right = newnode(2);
	root->left->right->left = newnode(7);
	root->left->right->right = newnode(4);
	root->right->left = newnode(0);
	root->right->right = newnode(8);
	node * target = root->right->right;
	//printkdistanceNode(root, target, 2);
	return 0;
}
