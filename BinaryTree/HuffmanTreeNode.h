#include<iostream>

using namespace std;

template<class dataType>
class HuffmanTreeNode {
public:
	dataType element; //结点值，在huffman树中是权重或概率	  
	HuffmanTreeNode<dataType>* parent,*left_child,*right_child;
	HuffmanTreeNode();
	HuffmanTreeNode(HuffmanTreeNode<dataType>&);
	HuffmanTreeNode(HuffmanTreeNode<dataType>*, 
		HuffmanTreeNode<dataType>*, 
		HuffmanTreeNode<dataType>*);
	HuffmanTreeNode(HuffmanTreeNode<dataType> *nd);
	bool operator < (HuffmanTreeNode<dataType> &nd);
	bool operator > (HuffmanTreeNode<dataType> &nd);
	template<dataType>
	friend ostream& operator <<(ostream& out, HuffmanTreeNode<dataType> nd);
};

template<class dataType>
HuffmanTreeNode<dataType>::HuffmanTreeNode(HuffmanTreeNode<dataType>* lt,
	HuffmanTreeNode<dataType>* rt,
	HuffmanTreeNode<dataType>* pt) {
	this->parent = pt;
	this->right_child = rt;
	this->left_child = lt;
}

template<class dataType>
HuffmanTreeNode<dataType>::HuffmanTreeNode(HuffmanTreeNode<dataType> &nd) {
	this->element = nd.element;
	this->parent = nd.parent;
	this->left_child = nd.left_child;
	this->right_child = nd.right_child;
}

template<class dataType>
HuffmanTreeNode<dataType>::HuffmanTreeNode() {
	this->parent = this->right_child = this->left_child = NULL;
}

template<class dataType>
bool HuffmanTreeNode<dataType>::operator < (HuffmanTreeNode<dataType> &nd){
	if (this->element < nd.element)
		return true;
	return false;
}
template<class dataType>
bool HuffmanTreeNode<dataType>::operator > (HuffmanTreeNode<dataType> &nd) {
	if (this->element > nd.element)
		return true;
	return false;
}

template<class dataType>
ostream& operator <<(ostream& out, HuffmanTreeNode<dataType> nd) {
	cout << nd.element;
	return out;
}
template<class dataType>
HuffmanTreeNode<dataType>::HuffmanTreeNode(HuffmanTreeNode<dataType> *nd) {
	this->element = nd->element;
	this->left_child = nd->left_child;
	this->right_child = nd->right_child;
	this->parent = nd->parent;
}
#pragma once
