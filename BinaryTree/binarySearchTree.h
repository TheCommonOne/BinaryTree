#include"binarytree.h"
template<class dataType>
class binarySearchTree:public binaryTree<dataType> {
public:
	binarySearchTree();
	binaryTreeNode<dataType>* search(dataType key,binaryTreeNode<dataType>* rt = NULL);
	bool insert(dataType value);
	void mergeDelete(binaryTreeNode<dataType>* node);
	binaryTreeNode<dataType>* copyDelete(binaryTreeNode<dataType>* node);
	binaryTreeNode<dataType>* searchLeft(binaryTreeNode<dataType> *node);
	binaryTreeNode<dataType>*searchRight(binaryTreeNode<dataType> *node);
};

template<class dataType>
binarySearchTree<dataType>::binarySearchTree():binaryTree<dataType>() {
	
	
}

template<class dataType>
binaryTreeNode<dataType>* binarySearchTree<dataType>::search(dataType key, binaryTreeNode<dataType>* rt) {
	binaryTreeNode<dataType> *temp = this->root;
	if (rt != NULL)
		temp = rt;
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			return temp;
		}
		else if (temp->data < key)
		{
			temp = temp->right_child;
		}
		else
		{
			temp = temp->left_child;
		}
	}
	return temp;
}
template<class dataType>
binaryTreeNode<dataType>* binarySearchTree<dataType>::searchLeft(binaryTreeNode<dataType> *node) {
	if (node == NULL)
		return NULL;
	while (node->left_child)
	{
		node = node->left_child;
	}
	return node;
}
template<class dataType>
binaryTreeNode<dataType>* binarySearchTree<dataType>::searchRight(binaryTreeNode<dataType> *node) {
	if (node == NULL)
	{
		return NULL;
	}
	while (node->right_child)
	{
		node = node->right_child;
	}
	return node;
}

template<class dataType>
bool binarySearchTree<dataType>::insert(dataType value) {
	binaryTreeNode<dataType>* new_node = new binaryTreeNode<dataType>;
	new_node->data = value;
	new_node->right_child = new_node->left_child = NULL;

	//节点为根
	if (this->root == NULL)
		this->root = new_node;
	else
	{
		binaryTreeNode<dataType> *back = NULL;
		binaryTreeNode<dataType> *current = this->root;
		while (current != NULL)
		{
			back = current;
			if (current->data > value)
			{
				current = current->left_child;
			}
			else
			{
				current = current->right_child;
			}
		}
		if (back->data > value)
		{
			back->left_child = new_node;
			back->left_child->parent = back;
		}
		else
		{
			back->right_child = new_node;
			back->right_child->parent = back;
		}
	}
	return true;
}
template<class dataType>
void binarySearchTree<dataType>::mergeDelete(binaryTreeNode<dataType>* node) {
	binaryTreeNode<dataType> *temp = this->root,*leftest = this->root;
	if (node == temp)// delete ROOT
	{
		if (node->left_child != NULL) // Root No Left
		{
			leftest = searchRight(node->left_child);
			leftest->right_child = temp->right_child;
			temp->right_child->parent = leftest;
			this->root = this->root->left_child;
			this->root->parent = NULL;
		}
		else  //Left No Right  || Root is Leaf
		{ 
			this->root = this->root->right_child;
			this->root->parent = NULL;
		}
	}
	else  // Not Root
	{
		if (node->left_child&&node->right_child)   // Node Has Left & Right
		{
			if (node->parent->left_child == node) // Parent ->Left?
			{
				node->parent->left_child = node->left_child;
				node->left_child->parent = node->parent;
				searchRight(node->left_child)->right_child = node->right_child;
			}
			else  //Parent ->Right！
			{
				node->parent->right_child = node->right_child;
				node->right_child->parent = node->parent;
				searchRight(node->right_child)->left_child = node->left_child;
			}
		}
		else if (node->isLeaf()) // Node is Leaf?
		{
			if (node->parent->left_child == node)
			{
				node->parent->left_child = NULL;
			}
			else
			{
				node->parent->right_child = NULL;
			}
		}
		else if (node->parent->left_child ==node)// Parent with One Empty  &  is node Parent->left?
		{
			if (node->left_child)
			{
				node->parent->left_child = node->left_child;
				node->left_child->parent = node->parent;
			}
			else
			{
				node->parent->left_child = node->right_child;
				node->right_child->parent = node->parent;
			}
		}
		else if(node->parent->right_child==node)//is node Parent->right ?
		{
			if (node->left_child)
			{
				node->parent->right_child = node->left_child;
				node->left_child->parent = node->parent;
			}
			else
			{
				node->parent->right_child = node->right_child;
				node->right_child->parent = node->parent;
			}
		}
	}
	delete node;
}
template<class dataType>
binaryTreeNode<dataType>* binarySearchTree<dataType>::copyDelete(binaryTreeNode<dataType>* node) {
	binaryTreeNode<dataType> *temp = this-> root,*substitute=NULL;
	if (node->isLeaf())
	{
		substitute = node->parent;
		if (node->parent->left_child == node)
		{
			node->parent->left_child = NULL;
		}
		else
		{
			node->parent->right_child = NULL;
		}
		delete node;
		return substitute;
	}
	else if (!node->right_child || !node->left_child)
	{
		substitute = node->right_child ? node->right_child : node->left_child;
		this->mergeDelete(node);
		return substitute;
	}
	else
	{
		if (node->parent->left_child == node)
		{
			node->parent->left_child =substitute = this->searchRight(node->left_child);
			if (substitute->parent->left_child == substitute)
			{
				if (substitute->isLeaf())
				{
					substitute->parent->left_child = NULL;
				}
				else if (substitute->left_child)
				{
					substitute->parent->left_child = substitute->left_child;
				}
				else
				{
					substitute->parent->left_child = substitute->right_child;
				}
			}
			else
			{
				if (substitute->isLeaf())
				{
					substitute->parent->right_child = NULL;
				}
				else if (substitute->left_child)
				{
					substitute->parent->right_child = substitute->left_child;
				}
				else
				{
					substitute->parent->right_child = substitute->right_child;
				}
			}
			substitute ->parent= node->parent;
		}
		else
		{
			node->parent->right_child = substitute = this->searchLeft(node->right_child);
			if (substitute->parent->left_child == substitute)
			{
				if (substitute->isLeaf())
				{
					substitute->parent->left_child = NULL;
				}
				else if (substitute->left_child)
				{
					substitute->parent->left_child = substitute->left_child;
				}
				else
				{
					substitute->parent->left_child = substitute->right_child;
				}
			}
			else
			{
				if (substitute->isLeaf())
				{
					substitute->parent->right_child = NULL;
				}
				else if (substitute->left_child)
				{
					substitute->parent->right_child = substitute->left_child;
				}
				else
				{
					substitute->parent->right_child = substitute->right_child;
				}
			}
			substitute->parent = node->parent;
		}
		substitute->left_child = node->left_child;
		if(substitute->left_child)
		substitute->left_child->parent = substitute;
		substitute->right_child = node->right_child;
		if(substitute->right_child)
		substitute->right_child->parent = substitute;
	}
	delete node;
	return substitute;
}

#pragma once
