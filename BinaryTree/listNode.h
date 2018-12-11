#pragma once
#include<iostream>

using namespace std;

template<class dataType>
class listNode {
public:
	listNode<dataType>* next_node_point;
	dataType * node_data;
	int identification;
	listNode();
	listNode(dataType &);
	listNode(dataType *);
	~listNode();
	listNode(listNode &);
	const listNode<dataType>& operator = (listNode<dataType>&);
	template<class dataType>
	friend ostream& operator << (ostream &, listNode<dataType> &);
};

template<class dataType>
listNode<dataType>::listNode()
{
	this->next_node_point = NULL;
	this->node_data = new dataType;
}
template<class dataType>
listNode<dataType>::listNode(dataType * dtp) {
	this->node_data = new dataType(*dtp);
}
template<class dataType>
listNode<dataType>::listNode(dataType& dt) {
	this->node_data = new dataType;
	this->next_node_point = NULL;
	*(this->node_data) = dt;
}
template<class dataType>
listNode<dataType>::listNode(listNode<dataType> &ln) {
	this->identification = ln.identification;
	this->next_node_point = ln.next_node_point;
	if (this->node_data != NULL)
	{
		*(this->node_data) = *(ln.node_data);
	}
	else
	{
		this->node_data = new dataType(*(ln.node_data));
	}
}
template<class dataType>
listNode<dataType>::~listNode() {
	if (node_data != NULL)
	delete node_data;
}

template<class dataType>
const listNode<dataType>& listNode<dataType>::operator =(listNode<dataType> &ln) {
	this->identification = ln.identification;
	this->next_node_point = ln.next_node_point;
	if (this->node_data != NULL)
	{
		*(this->node_data) = *(ln.node_data);
	}
	else
	{
		this->node_data = new dataType(*(ln.node_data));
	}
	return *this;
}
template<class dataType>
ostream& operator << (ostream & out, listNode<dataType> &node) {
	cout << *(node.node_data);
	return out;
}
#pragma once