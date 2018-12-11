#include<iostream>
using namespace std;

template<class dataType>
class binaryTreeNode {
public:
	dataType data;
	binaryTreeNode<dataType> *left_child;
	binaryTreeNode<dataType> *right_child;
	binaryTreeNode<dataType> *parent;
	binaryTreeNode();
	binaryTreeNode(binaryTreeNode<dataType> &nd);
	binaryTreeNode(const dataType dt);
	binaryTreeNode(const dataType &dt, 
		binaryTreeNode<dataType> *l, 
		binaryTreeNode<dataType>*r);
	binaryTreeNode(const dataType &dt, 
		binaryTreeNode<dataType> *l, 
		binaryTreeNode<dataType>*r, 
		binaryTreeNode<dataType> *p);
	binaryTreeNode<dataType>* getLeftChild() const;
	binaryTreeNode<dataType>* getRightChild() const;
	void setLeftChild(binaryTreeNode<dataType> *l);
	void setRightChild(binaryTreeNode<dataType> *r);
	dataType getData()const;
	dataType getData(dataType &dt);
	void setData(const dataType);
	bool isLeaf() const;
	template<dataType>
	friend ostream& operator << (ostream&, binaryTreeNode<dataType>&);
};

template<class dataType>
binaryTreeNode<dataType>::binaryTreeNode() {
	parent = left_child = right_child = NULL;
}
template<class dataType>
binaryTreeNode<dataType>::binaryTreeNode(binaryTreeNode<dataType> &nd) {
	left_child = nd.left_child;
	right_child = nd.right_child;
	data = nd.data;
	parent = nd.parent;
}
template<class dataType>
binaryTreeNode<dataType>::binaryTreeNode(const dataType dt) {
	left_child = right_child = parent = NULL;
	data = dt;
}
template<class dataType>
binaryTreeNode<dataType>::binaryTreeNode(const dataType &dt, binaryTreeNode<dataType> *l, binaryTreeNode<dataType>*r) {
	left_child = l;
	right_child = r;
	parent = NULL;
	data = dt;
}
template<class dataType>
binaryTreeNode<dataType>::binaryTreeNode(const dataType &dt, binaryTreeNode<dataType> *l, binaryTreeNode<dataType>*r, binaryTreeNode<dataType> *p) {
	left_child = l;
	right_child = r;
	parent = p;
	data = dt;
}

template<class dataType>
binaryTreeNode<dataType>* binaryTreeNode<dataType>::getLeftChild() const {
	if(this->left_child != NULL)
	return this->left_child;
	return NULL;
}
template<class dataType>
binaryTreeNode<dataType>* binaryTreeNode<dataType>::getRightChild() const {
	if(this->right_child!= NULL)
	return this->right_child;
	return NULL;
}

template<class dataType>
void binaryTreeNode<dataType>::setLeftChild(binaryTreeNode<dataType> *l) {
	this->left_child = l;
}
template<class dataType>
void binaryTreeNode<dataType>::setRightChild(binaryTreeNode<dataType> *r) {
	this->right_child = r;
}
template<class dataType>
dataType binaryTreeNode<dataType>::getData()const {
	return this->data;
}
template<class dataType>
dataType binaryTreeNode<dataType>::getData(dataType &dt) {
	dt = this->data;
	return dt;
}
template<class dataType>
void binaryTreeNode<dataType>::setData(const dataType dt) {
	this->data = dt;
}
template<class dataType>
bool binaryTreeNode<dataType>::isLeaf() const {
	if (this->left_child ==NULL&& this->right_child == NULL)
		return true;
	return false;
}
template<class dataType>
ostream& operator << (ostream& out, binaryTreeNode<dataType> &nd) {
	cout << nd.data;
	return out;
}
#pragma once
