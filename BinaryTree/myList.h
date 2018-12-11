#include"listStack.h"

template<class dataType>
class myList : public myListQueue<dataType> 
{
public:
	myList();
	bool deleteItem(dataType);
	bool deleteIndex(int);
	int getIndex(dataType);
	dataType operator [](int id);
};

template<class dataType>
myList<dataType>::myList() {

}

template<class dataType>
bool myList<dataType>::deleteItem(dataType dt) {
	listNode<dataType> * temp,*temp2;
	temp = this->front_p;
	if (*(temp->node_data) == dt)
	{
		this->DeQueue(dt);
		return true;
	}
	while (temp->next_node_point!= NULL)
	{
		if (*(temp->next_node_point->node_data) == dt)
		{
			if (temp->next_node_point == this->rear_p)
			{
				this->rear_p = temp;
				delete temp->next_node_point;
				this->rear_p->next_node_point = NULL;
			}
			else
			{
				temp2 = temp->next_node_point->next_node_point;
				delete temp->next_node_point;
				temp->next_node_point = temp2;
			}
			this->node_sum--;
			return true;
		}
		temp = temp->next_node_point;
	}
	return false;
}
template<class dataType>
bool myList<dataType>::deleteIndex(int id){
	int counter = 0;
	dataType temp = 0;
	listNode<dataType> *temp = this->front_p, *temp2;
	if (id == 0)
	{
		this->DeQueue(temp);
		return true;
	}
	counter++;
	while (temp->next_node_point!=NULL)
	{
		if (counter == id)
		{
			if (temp->next_node_point == this->rear_p)
			{
				this->rear_p = temp;
				delete temp->next_node_point;
				this->rear_p->next_node_point = NULL;
			}
			else
			{
				temp2 = temp->next_node_point->next_node_point;
				delete temp->next_node_point;
				temp->next_node_point = temp2;
			}
		}
		counter++;
	}
	return false;
}
template<class dataType>
int myList<dataType>::getIndex(dataType dt){
	listNode<dataType> * temp = this->front_p;
	int counter = 0;
	while (temp != NULL)
	{
		if(*(temp->node_data) == dt)
		return counter;
		counter++;
		temp = temp->next_node_point;
	}
	return -1;
}

template<class dataType>
dataType myList<dataType>::operator [](int id){
	listNode<dataType> *temp = this->front_p;
	int counter = 0;
	if (id > this->node_sum-1 || id <0)
	{
		cout << "Index Out of Boundary" << endl;
		return *(this->rear_p->node_data);
	}
	while (temp->next_node_point)
	{
		if (counter == id)
		{
			return *(temp->node_data);
		}
		temp = temp->next_node_point;
		counter++;
	}
	return *(this->rear_p->node_data);
}

#pragma once
