// Petia Nikolova
// July 7, 2017

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <cstdio>
#include <algorithm>



using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;	

} root;

struct Node* newNode(int data)
{

	struct Node* node = (struct Node*)
	malloc(sizeof(struct Node));
	
	node->data = data;
	node->left = NULL;
	node->right= NULL;
	return(node);

}


int height(struct Node* temp)
{
	int h=0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int diff(struct Node* temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}


int max(int l, int r)
{
	if (l < r)
		return r;
	else
		return l;
}

struct Node* min(struct Node* t)
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return min(t->left);
}

struct Node* rot_l(struct Node *parent)
{
	struct Node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

struct Node* rot_r(struct Node *parent)
{
	struct Node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;

} 

struct Node* rot_lr(struct Node* parent)
{
	struct Node *temp;
	temp= parent->left;
	parent->left = rot_r(temp);
	return rot_l(parent);
}

struct Node* rot_rl(struct Node* parent)
{
	struct Node *temp;
	temp = parent->right;
	parent->right = rot_l(temp);
	return rot_r(parent);
}

struct Node* getBalance(struct Node* temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff (temp->left) > 0)
			temp = rot_l(temp);
		else
			temp = rot_lr(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff (temp->right) > 0)
			temp = rot_rl(temp);
		else
			temp = rot_r(temp);
	}
	return temp;
}

struct Node* insert(struct Node* &node, int data)
{
	if (node == NULL)
		return(newNode(data));
	if (data <= node->data)
	{
		node->left = insert(node->left, data);
	}
	else if (data > node->data)
		node->right = insert(node->right, data);
    
     	node = getBalance(node);
	
	return node;
} 

void postOrder(struct Node *root)
{
    if(root != NULL)
    {
        postOrder(root ->left);
        postOrder(root ->right);
        printf("%d", root->data);
    	cout << " ";
    }
}
void inOrder(struct Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d", root->data);
	cout << " ";
        inOrder(root->right);
    }
}
void preOrder(struct Node *root)
{
	if(root != NULL)
	{	
		printf("%d", root->data);
		cout << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void display(struct Node *ptr, int data)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, data + 1);
        printf("\n");
        if (ptr == &root)
            cout<<"\t\t\t";
        for (i = 0; i < data && ptr != &root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, data + 1);
    }
}


bool search(struct Node* root, int num_search)
{
	if(root == NULL)
	{
		cout << "Searched: Node " << num_search << " not found!!";
		return false;
	}
	if (num_search < root->data)
	{
		return search(root->left, num_search);
	}
	if (num_search > root->data)
	{
		return search(root->right, num_search);
	}
	cout << "Searched: Node " << num_search << " found!!\n";
	return true;
}


struct Node* destroy(struct Node* root, int delete_num)
{
	struct Node *temp = NULL;
	if(root == NULL)
	{
		cout << "Attempted to delete: Node " << delete_num << " not found/not deleted.\n";
		return NULL;
	}
	else if (delete_num < root->data)
	{
		root->left = destroy(root->left, delete_num);	
	}
	else if (delete_num > root->data)
	{
		root->right = destroy(root->right, delete_num);
	}
    	else if(root->left && root->right)
    	{
        	temp = min(root->right);
       	 	root->data = temp->data;
        	root->right = destroy(root->right, root->data);
    	}
    	else
    	{
        	temp = root;
        	if(root->left == NULL)
    		    	root = root->right;
        	else if(root->right == NULL)
            		root = root->left;
        	delete temp;
    	}
    	if(root == NULL)
        	return root;
		root = getBalance(root); 
		cout << "Attempted to delete: Node " << delete_num << ". Success!\n";
		return root; 

}

int main()
{

struct Node *root = NULL;

root = insert(root, 70);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);

cout << "Pre order sequence: ";
preOrder(root);
cout << endl;
cout << "Post order sequence: ";
postOrder(root);
cout << endl;
cout << "In order sequence: ";
inOrder(root);
cout << endl;
cout << endl;

display(root, 1);
cout << endl;

search(root, 80);
cout << endl;
search(root, 20);
cout << endl;

destroy(root, 15);
cout << endl;

destroy(root, 20);
cout << endl;

display(root, 1);
cout << endl;

return 0;
}
