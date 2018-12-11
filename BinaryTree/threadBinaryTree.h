#include<iostream>
#include"threadBinaryTreeNode.h"
using namespace std;

template<class dataType>
class threadBinaryTree {
private:
	threadBinaryTreeNode<dataType> *root;
public:
	threadBinaryTree();
	threadBinaryTree(threadBinaryTreeNode<dataType>*r);
	~threadBinaryTree();
	threadBinaryTreeNode* getRoot();
	void midThred(threadBinaryTreeNode<dataType>*root, 
							 threadBinaryTreeNode<dataType>* pre);
	void midOrder(threadBinaryTreeNode<dataType>* root);
};
#pragma once
