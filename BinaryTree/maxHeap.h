#include<iostream>

using namespace  std;

template<class dataType>
class maxHeap {
public:
	dataType * heap_array;
	int current_size;
	int max_size;
	maxHeap(const int mx_sz);
	~maxHeap();
	void initiate();
	void buildHeap();

	bool isEmpty();
	bool isLeaf(int pos);

	int getLeft(int pos) const;	   		// 返回左孩子位置
	int getRight(int pos) const;		// 返回右孩子位置
	int getParent(int pos) const;			// 返回父结点位置
	bool Insert(const dataType& newNode);		// 向堆中插入新元素newNode

	dataType& removeMax();			// 从堆顶删除最小值
	bool remove(int pos, dataType& node); 		// 删除给定下标的元素

	void swap(int post_x, int post_y);
	void siftUp(int position);		 // 从position向上开始调整，使序列成为堆
	void siftDown(int left);         	// 向下筛选，参数left表示开始处理的数组下标

	template<dataType>
	friend ostream& operator <<(ostream& out, maxHeap<dataType>& mh);
};

template<class dataType>
maxHeap<dataType>::maxHeap(const int mx_sz) {
	if (mx_sz <= 0) 
	{ 
		heap_array = NULL; current_size = max_size = 0;
		return; 
	}
	current_size = 0;
	max_size = mx_sz;
	heap_array = new dataType[mx_sz];
}
template<class dataType>
maxHeap<dataType>::~maxHeap() {
	if (heap_array!=NULL)
	{
		delete[] heap_array;
	}
}
template<class dataType>
void maxHeap<dataType>::initiate() {
	int pos = getParent(current_size - 1);
	while (pos >= 0)
	{
		siftDown(pos);
		pos--;
	}
}
template<class dataType>
void maxHeap<dataType>::buildHeap() {
	dataType temp;
	for (int i = 0; i < max_size; i++)
	{
		cout << "Input " << max_size << " Value"<<endl;
		//cin >> temp;
		heap_array[i] = i;
		this->current_size++;
	}
	initiate();
}

template<class dataType>
bool maxHeap<dataType>::isEmpty() {
	return current_size == 0;
}
template<class dataType>
bool maxHeap<dataType>::isLeaf(int pos) {
	return (pos < current_size) && (pos >= current_size / 2);
}
template<class dataType>
int maxHeap<dataType>::getLeft(int pos) const {
	return 2 * pos + 1;
}

template<class dataType>// 返回左孩子位置
int maxHeap<dataType>::getRight(int pos) const {
	return 2 * pos + 2;
}
template<class dataType>// 返回右孩子位置
int maxHeap<dataType>::getParent(int pos) const {
	return (pos - 1) / 2;
}
template<class dataType>// 返回父结点位置
bool maxHeap<dataType>::Insert(const dataType& newNode) {
	if (current_size == max_size)
	{
		cout << "Max Heap Full" << endl;
		return false;
	}
	heap_array[current_size] = newNode;
	current_size++;
	siftUp(current_size-1);
	return true;
}
// 向堆中插入新元素newNode
template<class dataType>
dataType& maxHeap<dataType>::removeMax() {
	if (this->isEmpty())
	{
		cout << "Empty Max Heap" << endl;
		return heap_array[0];
	}
	dataType temp = heap_array[0];
	if (current_size == 0) {
		cout << "Can't Delete";		// 调用RemoveMin之前，需要判断堆非空
		exit(1);
	}
	else {
		swap(0, --current_size);	                 // 交换堆顶和最后一个元素
		if (current_size>1)        siftDown(0);          // 从堆顶开始筛选
		return temp;
	}

}			// 从堆顶删除最大值
template<class dataType>
bool maxHeap<dataType>::remove(int pos, dataType& node) {
	if (this->isEmpty())
	{
		cout << "Empty Max Heap" << endl;
		return flase;
	}
	if(pos>current_size||pos<0)
	return false;
	node = heap_array[pos];
	heap_array[pos] = heap_array[--current_size];	// 用最后的元素值替代删除位置的元素
	if (heap_array[getParent(pos)] < heap_array[pos])
		siftUp(pos);			// 当前元素小于父结点，需要上升调整
	else siftDown(pos);			// 当前元素大于父结点，向下筛
	return true;
} 		// 删除给定下标的元素
template<class dataType>
void maxHeap<dataType>::swap(int post_x, int post_y) {
	dataType temp = this->heap_array[post_x];
	this->heap_array[post_x] = this->heap_array[post_y];
	this->heap_array[post_y] = temp;
}

template<class dataType>
void maxHeap<dataType>::siftUp(int position) {
	dataType temp = heap_array[position];
	while ((position > 0) && (temp > heap_array[getParent(position)]))
	{
		heap_array[position] = heap_array[getParent(position)];
		position = getParent(position);
	}
	heap_array[position] = temp;
}
// 从position向上开始调整，使序列成为堆
template<class dataType>
void maxHeap<dataType>::siftDown(int pos) {
	int up = pos;
	int below = getLeft(pos);
	dataType temp = heap_array[pos];
	while (below < current_size)
	{
		if ((below < current_size - 1) && heap_array[below] < heap_array[below + 1])
		{
			below++;
		}
		if ((temp < heap_array[below]))
		{
			heap_array[up] = heap_array[below];
			up = below;
			below = getLeft(up);
		}
		else break;
	}
	heap_array[up] = temp;
}
// 向下筛选，参数left表示开始处理的数组下标

template<class dataType>
ostream & operator << (ostream & out, maxHeap<dataType>& mh) {
	for (int i = 0; i < mh.current_size; i++)
	{
		cout << mh.heap_array[i]<<' ';
	}
	return out;
}
#pragma once
