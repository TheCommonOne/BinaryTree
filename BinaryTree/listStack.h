#include"listNode.h"

template<class dataType>
class myListStack {
public:
	int node_sum;
	listNode<dataType> * head;
	myListStack();
	myListStack(int);
	~myListStack();
	bool Empty();
	void Clear();
	bool Push(dataType &);
	bool Pop();
	bool Top(dataType&);
	template<class dataType>
	friend ostream & operator<<(ostream &, myListStack<dataType> &);
};

template<class dataType>
myListStack<dataType>::myListStack() {
	this->node_sum = 0;
	this->head = NULL;
}
template<class dataType>
myListStack<dataType>::myListStack(int max) {
	listNode<dataType> * temp = this->head;
	this->maxSize = max;
	this->node_sum = -1;
	for (int i = 0; i < max; i++)
	{
		if (i == 0)
		{
			this->head = new listNode<dataType>;
			temp = head;
			this->head->next_node_point = NULL;
		}
		else
		{
			this->head = new listNode<dataType>;
			this->head->next_node_point = temp;
			temp = this->head;
		}
	}
	this->head = temp;
}
template<class dataType>
myListStack<dataType>::~myListStack() {
	if (this->Empty())
		return;
	listNode<dataType> *temp = this->head->next_node_point;
	for (;temp != NULL;)
	{
		delete this->head;
		this->head = temp;
		temp = temp->next_node_point;
	}
	delete this->head;
}

template<class dataType>
bool myListStack<dataType>::Empty() {
	if (this->node_sum == 0)  
		return true;
	return false;
}
template<class dataType>
void myListStack<dataType>::Clear() {
	this->node_sum = 0;
	listNode<dataType> *temp = this->head;
	while (temp != NULL)
	{
		this->head = temp->next_node_point;
		delete temp;
		temp = this->head;
		this->head = this->head->next_node_point;
	}
}

template<class dataType>
bool myListStack<dataType>::Push(dataType & item) {
	listNode<dataType> * temp = this->head;
	this->head = new listNode<dataType>;
	this->head->node_data = new dataType(item);
	this->head->next_node_point = temp;
	this->node_sum++;
	return true;
}
template<class dataType>
bool myListStack<dataType>::Pop() {
	listNode<dataType> * temp;
	if (this->Empty())
	{
		cout << "Stack is Empty. Pop ERR" << endl;
		return false;
	}
	else
	{
		temp = this->head->next_node_point;
		delete this->head;
		this->head = temp;
		this->node_sum--;
		if (this->node_sum == 0)
			this->head = NULL;
		return true;
	}
}
template<class dataType>
bool myListStack<dataType>::Top(dataType& item) {
	if (this->Empty())
	{
		item = 0;
		return false;
	}
	else
	{
		item = *((this->head)->node_data);
		return true;
	}
}

template<class dataType>
ostream & operator<<(ostream &out, myListStack<dataType> &item)
{
	listNode<dataType> *temp; int i = 0;
	if (item.Empty())
	{
		cout << "Stack is Empty. Output ERR" << endl;
		return out;
	}
	else
	{
		for (temp = item.head; i < item.node_sum; i++)
		{
			cout << *temp<< " ";
			temp = temp->next_node_point;
		}
		cout << endl;
	}
	return out;
}
#pragma once
