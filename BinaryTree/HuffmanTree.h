#include<iostream>
#include"HuffmanTreeNode.h"
#include"minHeap.h"
using namespace std;

template<class dataType>
class HuffmanTree{
public:
	HuffmanTreeNode<dataType> *root;
	void MergeTree(HuffmanTreeNode<dataType> *ht1, 
		HuffmanTreeNode<dataType> *ht2, 
		HuffmanTreeNode<dataType>* parent);
	void DeleteTree(HuffmanTreeNode<dataType> *root);
	HuffmanTree(dataType *weight, int n);
	void preFirst(HuffmanTreeNode<dataType>*);
	virtual ~HuffmanTree() { DeleteTree(root); }
};

template<class dataType>
void HuffmanTree<dataType>::MergeTree(HuffmanTreeNode<dataType> *ht1,
	HuffmanTreeNode<dataType> *ht2,
	HuffmanTreeNode<dataType>* parent) {
	parent->element = ht1->element + ht2->element;
	parent->left_child = ht1;
	parent->right_child = ht2;
}

template<class dataType>
void HuffmanTree<dataType>::DeleteTree(HuffmanTreeNode<dataType> *root) {
	if (root)
	{
		DeleteTree(root->left_child);
		DeleteTree(root->right_child);
		delete root;
	}
}
template<class dataType>
HuffmanTree<dataType>::HuffmanTree(dataType *weight, int n) {
	minHeap<HuffmanTreeNode<dataType>*> heap(n);
	HuffmanTreeNode<dataType> *parent, *first_child, *second_child;
	HuffmanTreeNode<dataType> *nodeList = new HuffmanTreeNode<dataType>[n];

	HuffmanTreeNode<dataType> *temp;
	for (int i = 0; i < n; i++)
	{
		nodeList[i].element = weight[i];
		nodeList[i].parent = nodeList[i].left_child = nodeList[i].right_child = NULL;
		heap.Insert(nodeList + i);
	}
	heap.initiate();
	for (int i = 0; i < n - 1; i++)
	{
		parent = new HuffmanTreeNode<dataType>;
		/*if (temp.element == 270)
		cout << 1;
		if (temp.element == 546)
		cout << 2;*/
		MergeTree(heap.removeMin(), heap.removeMin(), parent);
		heap.Insert(parent);
	}
	temp = heap.removeMin();
	this->root = new HuffmanTreeNode<dataType>(temp);
	//delete[] node;
}

template<class dataType>
void HuffmanTree<dataType>::preFirst(HuffmanTreeNode<dataType>* nd) {
	if (nd)
	{
		cout << *nd;
		this->preFirst(nd->left_child);
		this->preFirst(nd->right_child);
	}
}
#pragma once