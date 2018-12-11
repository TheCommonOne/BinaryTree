#include"binarySearchTree.h"

using namespace std;

template<class dataType>
class AVLTree:public binarySearchTree<dataType> {
public:
	binaryTreeNode<dataType>* singleSpiral(binaryTreeNode<dataType>*lower, 
																			binaryTreeNode<dataType>*upper);
	binaryTreeNode<dataType>* doubleSpiral(binaryTreeNode<dataType>*lower, 
																			binaryTreeNode<dataType>*mid, 
																			binaryTreeNode<dataType>*upper);
	bool insert(dataType value);
	int countBalanceFactor(binaryTreeNode<dataType>*lower);
	void determineSpiral(binaryTreeNode<dataType>* rt, int lower, int upper);
	bool dltItem(dataType value);
};

template<class dataType>
binaryTreeNode<dataType>* AVLTree<dataType>::singleSpiral(binaryTreeNode<dataType>*lower, binaryTreeNode<dataType>*upper) {
	if (this->root == upper)
	{
		this->root = lower;	
	}
	if (upper->left_child == lower)
	{
		lower->parent = upper->parent;
		if (lower->parent)
			if (lower->parent->left_child == upper)
				lower->parent->left_child = lower;
			else
				lower->parent->right_child = lower;

		upper->left_child = lower->right_child;
		if (lower->right_child)
			upper->left_child->parent = upper;

		lower->right_child = upper;
		upper->parent = lower;
	}
	else if (upper->right_child == lower)
	{
		lower->parent = upper->parent;
		if (lower->parent)
			if (lower->parent->right_child == upper)
				lower->parent->right_child = lower;
			else
				lower->parent->left_child = lower;

		upper->right_child = lower->left_child;
		if (lower->left_child)
			upper->right_child->parent = upper;

		lower->left_child = upper;
		upper->parent = lower;
	}
	return lower;
}

template<class dataType>
binaryTreeNode<dataType>* AVLTree<dataType>::doubleSpiral(binaryTreeNode<dataType>*lower,
	binaryTreeNode<dataType>*mid,
	binaryTreeNode<dataType>*upper) {
	this->singleSpiral(lower, mid);
	this->singleSpiral(lower, upper);
	return lower;
}

template<class dataType>
int  AVLTree<dataType> ::countBalanceFactor(binaryTreeNode<dataType>*lower) {
	int depth1=1,depth2 =1;
	if (!lower)
		return 0;
	return (this->countDepth(lower->right_child, 1, depth1)- this->countDepth(lower->left_child, 1, depth2));
}

template<class dataType>
bool AVLTree<dataType>::insert(dataType value) {
	binaryTreeNode<dataType>* temp_node = new binaryTreeNode<dataType>;
	int factor = 1,before_factor;
	temp_node->data = value;
	temp_node->right_child = temp_node->left_child = NULL;

	//节点为根
	if (this->root == NULL)
		this->root = temp_node;
	else
	{
		binaryTreeNode<dataType> *back = NULL;
		binaryTreeNode<dataType> *current = this->root;
		while (current != NULL)
		{
			back = current;
			if (current->data == value)
				return false;
			if (current->data > value)
				current = current->left_child;
			else
				current = current->right_child;
		}
		if (back->data > value)
		{
			back->left_child = temp_node;
			back->left_child->parent = back;
		}
		else
		{
			back->right_child = temp_node;
			back->right_child->parent = back;
		}
		before_factor = this->countBalanceFactor(back);
		temp_node = back->parent;
		while (temp_node)
		{
			factor = this->countBalanceFactor(temp_node);
			if (factor % 2 == 0 &&factor)
			{
				determineSpiral(temp_node, before_factor, factor);
				break;
			}
			temp_node = temp_node->parent;
			before_factor = factor;
		}
	}
	return true;
}

template<class dataType>
void  AVLTree<dataType>::determineSpiral(binaryTreeNode<dataType>* rt, int lower,int upper) {
	if (lower*upper >= 0)
	{
		if(lower<0)
			this->singleSpiral(rt->left_child, rt);
		else if (lower == 0)
		{
			if (this->countBalanceFactor(rt->left_child) == 0)
				this->singleSpiral(rt->right_child, rt);
			if(this->countBalanceFactor(rt->right_child) == 0)
				this->singleSpiral(rt->left_child, rt);
		}
		else
			this->singleSpiral(rt->right_child, rt);
	}
	else
	{
		if (lower < 0)
			this->doubleSpiral(rt->right_child->left_child,rt->right_child,rt);
		else
			this->doubleSpiral(rt->left_child->right_child,rt->left_child,rt);
	}
}

template<class dataType>
bool AVLTree<dataType>::dltItem(dataType value) {
	binaryTreeNode<dataType> *temp_node,*next;
	int factor = 1, after_factor;
	if (!(temp_node = this->search(value)))
		return false;
	temp_node = this->copyDelete(temp_node);
	if (!temp_node)
		temp_node = this->root;
	if (!temp_node)
		return true;
	next = temp_node->left_child;
	while (temp_node)
	{
		factor = this->countBalanceFactor(temp_node);
		if (factor % 2 == 0 && factor)
		{
			if(next == temp_node->left_child)
				after_factor = this->countBalanceFactor(temp_node->right_child);
			else
				after_factor = this->countBalanceFactor(temp_node->left_child);
			determineSpiral(temp_node, after_factor, factor);
		}
		next = temp_node;
		temp_node = temp_node->parent;
	}
	return true;
}