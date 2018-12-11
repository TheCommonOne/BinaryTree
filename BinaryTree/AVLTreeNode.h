#include<iostream>
using namespace std;

template<class dataType>
class AVLTreeNode {
public:
	dataType data;
	AVLTreeNode<dataType> *left_child;
	AVLTreeNode<dataType> *right_child;
	AVLTreeNode<dataType> *parent;
	AVLTreeNode();
	AVLTreeNode(AVLTreeNode<dataType> &nd);
	AVLTreeNode(const dataType dt);
	AVLTreeNode(const dataType &dt,
		AVLTreeNode<dataType> *l,
		AVLTreeNode<dataType>*r);
	AVLTreeNode(const dataType &dt,
		AVLTreeNode<dataType> *l,
		AVLTreeNode<dataType>*r,
		AVLTreeNode<dataType> *p);
	AVLTreeNode<dataType>* getLeftChild() const;
	AVLTreeNode<dataType>* getRightChild() const;
	void setLeftChild(AVLTreeNode<dataType> *l);
	void setRightChild(AVLTreeNode<dataType> *r);
	dataType getData()const;
	dataType getData(dataType &dt);
	void setData(const dataType);
	bool isLeaf() const;
	template<dataType>
	friend ostream& operator << (ostream&, AVLTreeNode<dataType>&);
};

template<class dataType>
AVLTreeNode<dataType>::AVLTreeNode() {
	parent = left_child = right_child = NULL;
}

//¿½±´
template<class dataType>
AVLTreeNode<dataType>::AVLTreeNode(AVLTreeNode<dataType> &nd) {
	left_child = nd.left_child;
	right_child = nd.right_child;
	data = nd.data;
	parent = nd.parent;
}
template<class dataType>
AVLTreeNode<dataType>::AVLTreeNode(const dataType dt) {
	left_child = right_child = parent = NULL;
	data = dt;
}
template<class dataType>
AVLTreeNode<dataType>::AVLTreeNode(const dataType &dt, AVLTreeNode<dataType> *l, AVLTreeNode<dataType>*r) {
	left_child = l;
	right_child = r;
	parent = NULL;
	data = dt;
}
template<class dataType>
AVLTreeNode<dataType>::AVLTreeNode(const dataType &dt, AVLTreeNode<dataType> *l, AVLTreeNode<dataType>*r, AVLTreeNode<dataType> *p) {
	left_child = l;
	right_child = r;
	parent = p;
	data = dt;
}

template<class dataType>
AVLTreeNode<dataType>* AVLTreeNode<dataType>::getLeftChild() const {
	if (this->left_child != NULL)
		return this->left_child;
	return NULL;
}
template<class dataType>
AVLTreeNode<dataType>* AVLTreeNode<dataType>::getRightChild() const {
	if (this->right_child != NULL)
		return this->right_child;
	return NULL;
}

template<class dataType>
void AVLTreeNode<dataType>::setLeftChild(AVLTreeNode<dataType> *l) {
	this->left_child = l;
}
template<class dataType>
void AVLTreeNode<dataType>::setRightChild(AVLTreeNode<dataType> *r) {
	this->right_child = r;
}
template<class dataType>
dataType AVLTreeNode<dataType>::getData()const {
	return this->data;
}
template<class dataType>
dataType AVLTreeNode<dataType>::getData(dataType &dt) {
	dt = this->data;
	return dt;
}
template<class dataType>
void AVLTreeNode<dataType>::setData(const dataType dt) {
	this->data = dt;
}
template<class dataType>
bool AVLTreeNode<dataType>::isLeaf() const {
	if (this->left_child == NULL && this->right_child == NULL)
		return true;
	return false;
}
template<class dataType>
ostream& operator << (ostream& out, AVLTreeNode<dataType> &nd) {
	cout << nd.data;
	return out;
}
#pragma once
#pragma once
