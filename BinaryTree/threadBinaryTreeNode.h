#include<iostream>

using namespace std;

template<class dataType>
class threadBinaryTreeNode {
	friend class threadBinaryTree<dataType>;
private:
	int leftTag, rightTag;
	threadBinaryTreeNode<dataType>* leftChild;
	threadBinaryTreeNode<dataType>*rightChild;
	dataType data;
public:
	threadBinaryTreeNode();
	threadBinaryTreeNode(const dataType & data);
	threadBinaryTreeNode(const dataType & data,
		threadBinaryTreeNode<dataType> *l,
		threadBinaryTreeNode<dataType>*r);
	threadBinaryTreeNode<dataType>* getLeftChild() const;
	threadBinaryTreeNode<dataType> * getRghtChild()const;
	dataType getData()const;
	void setValue(const dataType & dt);
};
#pragma once
