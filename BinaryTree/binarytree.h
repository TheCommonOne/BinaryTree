#include<iostream>

#include"binaryTreeNode.h"
#include"listStack.h"
#include"listQueue.h"
#include"myList.h"
#include<string>

using namespace std;

template<class dataType>
class binaryTree {
public:
	binaryTreeNode<dataType> *root;

	//Construct Tree
	binaryTree();
	// Complete Binary Tree
	binaryTree(int);
	// Input
	void createTree(binaryTreeNode<dataType>*&);
	//Delete
	~binaryTree();
	void deleteBinaryTreeRec(binaryTreeNode<dataType>* &rt);
	void deleteBinaryTree(binaryTreeNode<dataType>* rt = NULL);
	void deleteLeaf(binaryTreeNode<dataType> *& rt);

	//Determine
	bool isEmpty(binaryTreeNode<dataType> *rt = NULL) const;
	bool isCompleteLong(binaryTreeNode<dataType> *rt);
	bool isComplete(binaryTreeNode<dataType> *rt);

	binaryTreeNode<dataType> * getRoot()const;
	binaryTreeNode<dataType> * getParent(binaryTreeNode<dataType>*current)const;
	binaryTreeNode<dataType>* getLeftSibling(binaryTreeNode<dataType>*current)const;
	binaryTreeNode<dataType>* getRightSibling(binaryTreeNode<dataType>*current)const;

	//traverse
	void breadthFirst(binaryTreeNode<dataType> *rt = NULL);
	void preFirst(binaryTreeNode<dataType>*rt = NULL);
	void midFirst(binaryTreeNode<dataType> *rt = NULL);
	void postFirst(binaryTreeNode<dataType> * rt = NULL);
	void levelFirst(binaryTreeNode<dataType> *rt = NULL);
	void preRec(binaryTreeNode<dataType>*rt = NULL);
	void midRec(binaryTreeNode<dataType> *rt = NULL);
	void postRec(binaryTreeNode<dataType> * rt = NULL);
	void levelRec(binaryTreeNode<dataType> *rt = NULL);

	//count
	int countLeaf( binaryTreeNode<dataType> *rt, int &count);
	int countDepth(binaryTreeNode<dataType> *rt, int level ,int &depth);
	int countWidth(binaryTreeNode<dataType> *rt);
	int countwidth(binaryTreeNode<dataType> *rt, int level, int *width);
	int countOneNode(binaryTreeNode<dataType> *rt, int &count);
	int countTwoNode(binaryTreeNode<dataType>*rt, int&count);
	int getMax(binaryTreeNode<dataType> *rt, int& max);
	int countWidthNRec(binaryTreeNode<dataType> *rt);

	//search
	bool searchRec(binaryTreeNode<dataType> *rt,int  value);
	bool searchLoop(int & value,binaryTreeNode<dataType> *rt = NULL);
	void changeLF(binaryTreeNode<dataType> *rt);

	void preMidTran();
	void postMidTran();

private:
	int getmax(binaryTreeNode<dataType> *rt, int& max);
	binaryTreeNode<dataType> * premidTran(string, string);
	binaryTreeNode<dataType>* postmidTran(string, string);
	void deleteleaf(binaryTreeNode<dataType> *& rt);
};

//Construct & Destory
template<class dataType>
binaryTree<dataType>::binaryTree()
{
	this->root = NULL;
}
template<class dataType>
binaryTree<dataType>::binaryTree(int num){
	int counter = 0;
	myListQueue<binaryTreeNode<dataType> *> node_queue;
	binaryTreeNode<dataType> * temp =this->root = new binaryTreeNode<dataType>(counter++);
	while (counter < num)
	{
			temp ->left_child = new binaryTreeNode<dataType>(counter++);
			temp->right_child = new binaryTreeNode<dataType>(counter++);
			node_queue.EnQueue(temp->left_child);
			node_queue.EnQueue(temp->right_child);
			temp->left_child->parent = temp->right_child->parent = temp;
			if (counter >= num)
			{
				delete temp->right_child;
				temp->right_child = NULL;
			}
			node_queue.DeQueue(temp);
	}
	if (num <= 0)
	{
		delete temp;
		this->root = NULL;
	}
	node_queue.Clear();
}
template<class dataType>
void binaryTree<dataType>::createTree(binaryTreeNode<dataType>*& nd) {
	int flag;
	dataType value;
	cout << "Input flag (0==Over) : ";
	cin >> flag;
	cout << endl;
	if (flag == 0)
		nd = NULL;
	else
	{
		if (!nd)
			nd = new binaryTreeNode<dataType>;
		cout << "Input Data ： ";
		cin >> value;
		nd->data = value;
		createTree(nd->left_child);
		createTree(nd->right_child);
	}
	return;
}
template<class dataType>
void binaryTree<dataType>::deleteBinaryTree(binaryTreeNode<dataType>* rt) {
	binaryTreeNode<dataType> *temp = rt;
	myListQueue<binaryTreeNode<dataType> *> node_queue;
	if (temp == NULL)
		temp = this->root;
	if (this->isEmpty(temp))
		return;
	while (!node_queue.Empty() || temp)
	{
		if (temp->left_child)
			node_queue.EnQueue(temp->left_child);
		if (temp->right_child)
			node_queue.EnQueue(temp->right_child);
		delete temp;
		temp = NULL;
		if (!node_queue.Empty())
			node_queue.DeQueue(temp);
		else
			temp = NULL;
	}
	this->root = NULL;
}
template<class dataType>
void binaryTree<dataType>::deleteBinaryTreeRec(binaryTreeNode<dataType>* &rt){
	if (rt)
	{
		deleteBinaryTreeRec(rt->left_child);
		deleteBinaryTreeRec(rt->right_child);
		delete rt;
		rt = NULL;
	}
	return;
}
template<class dataType>
void binaryTree<dataType>::deleteLeaf(binaryTreeNode<dataType> *& rt) {
	if (rt->isLeaf())
	{
		delete rt;
		rt = NULL;
		return;
	}
	deleteleaf(rt);
}
template<class dataType>
void binaryTree<dataType>::deleteleaf(binaryTreeNode<dataType> *& rt) {
	if (rt->left_child)
	{
		if (rt->left_child->isLeaf())
		{
			delete rt->left_child;
			rt->left_child = NULL;
		}
		else deleteleaf(rt->left_child);
	}
	if (rt->right_child)
	{
		if (rt->right_child->isLeaf())
		{
			delete rt->right_child;
			rt->right_child = NULL;
		}
		else deleteleaf(rt->right_child);
	}
}
template<class dataType>
binaryTree<dataType>::~binaryTree(){
	if(this->root)
	this->deleteBinaryTree();
}

//Determine
template<class dataType>
bool binaryTree<dataType>::isEmpty(binaryTreeNode<dataType> *rt) const {
	if (rt == NULL)
		return true;
	return false;
}
template<class dataType>
bool binaryTree<dataType>::isCompleteLong(binaryTreeNode<dataType> *rt) {
	int depth; this->countDepth(rt,0,depth);
	int length, level = 1;
	bool flag = 0;
	binaryTreeNode<dataType> *temp,*temp2;
	myListQueue<binaryTreeNode<dataType>*> node_queue[2];
	if (rt == NULL)
		return true;
	if (rt->isLeaf())
		return true;
	node_queue[flag].EnQueue(rt);
	while (level<=depth)
	{
		length = node_queue[flag].node_sum;
		while (length>0)
		{
			node_queue[flag].DeQueue(temp);
			node_queue[!flag].EnQueue(temp);
			if (temp->left_child)
				node_queue[flag].EnQueue(temp->left_child);
			else if (temp->right_child)
			{
				return false;
			}
			if (temp->right_child)
				node_queue[flag].EnQueue(temp->right_child);
			length--;
		}
		if (node_queue[flag].node_sum == 2*node_queue[!flag].node_sum)
		{
			if (level == depth)
				return true;
			else
			{
				node_queue[!flag].Clear();
			}
		}
		else if(level!=depth)
		{
			return false;
		}
		else if(level == depth)
		{
			while (node_queue[flag].node_sum!=0 && node_queue[!flag].node_sum!=0)
			{
					node_queue[flag].DeQueue(temp2);
					node_queue[!flag].DeQueue(temp);
					if (temp->left_child != temp2 && (node_queue[flag].Empty() || node_queue[!flag].Empty()))
						return false;
					else
					{
						if (!node_queue[flag].Empty())
						{
							node_queue[flag].DeQueue(temp2);
							if (temp2 != temp->right_child && (node_queue[flag].Empty() || node_queue[!flag].Empty()))
								return false;
						}
					}
			}
			return true;
		}
		level++;
	}
	return true;
}
template<class dataType>
bool binaryTree<dataType>::isComplete(binaryTreeNode<dataType> *rt) {
	if (rt == NULL)
		return false;
	myListQueue<binaryTreeNode<dataType> *> node_queue;
	node_queue.EnQueue(rt);
	bool mustHaveNoChild = false;
	bool result = true;
	while (!node_queue.Empty())
	{
		binaryTreeNode<dataType>* temp;
		node_queue.DeQueue(temp);
		if (mustHaveNoChild)//如果一个节点没有子节点;只要出现了空子树的节点，后面出现的必须为叶子节点（左字树右子树必须为空）
		{
			if (temp->left_child != NULL || temp->right_child != NULL)
			{
				result = false;
				break;
			}
		}
		else
		{
			if (temp->left_child != NULL && temp->right_child != NULL)
			{
				node_queue.EnQueue(temp->left_child);
				node_queue.EnQueue(temp->right_child);
			}
			else if (temp->left_child != NULL && temp->right_child == NULL)
			{
				mustHaveNoChild = true;
				node_queue.EnQueue(temp->left_child);
			}
			else if (temp->left_child == NULL && temp->right_child != NULL)
			{
				result = false;
				break;
			}
			else
			{
				mustHaveNoChild = true;
			}
		}
	}
	return result;
}

//Get method
template<class dataType>
binaryTreeNode<dataType>* binaryTree<dataType>::getRoot()const {
	return this->root;
}
template<class dataType>
binaryTreeNode<dataType>* binaryTree<dataType>::getParent(binaryTreeNode<dataType>*current)const {
	return current->parent;
}
template<class dataType>
binaryTreeNode<dataType>* binaryTree<dataType>::getLeftSibling(binaryTreeNode<dataType>*current)const {
	return current->parent->left_child;
}
template<class dataType>
binaryTreeNode<dataType>* binaryTree<dataType>::getRightSibling(binaryTreeNode<dataType>*current)const {
	return current->parent->right_child;
}

//Traverse
template<class dataType>
void binaryTree<dataType>::breadthFirst(binaryTreeNode<dataType> *rt) {
	myListQueue<binaryTreeNode<dataType> *> node_queue;
	binaryTreeNode<dataType> *temp = NULL;
	if (rt == NULL)
		rt = this->root;
	node_queue.EnQueue(rt);
	while (!node_queue.Empty() || temp)
	{
		node_queue.DeQueue(temp);
		if (temp != NULL)
		{
			node_queue.EnQueue(temp->left_child);
			node_queue.EnQueue(temp->right_child);
			cout << *temp;
			cout << ' ';
		}
	}
	cout << endl;
}
template<class dataType>
void binaryTree<dataType>::preFirst(binaryTreeNode<dataType>*rt ) {
	myListStack<binaryTreeNode<dataType> *> node_stack;
	binaryTreeNode<dataType> * temp=rt;
	if (temp == NULL)
		temp = this->root;
	if (this->isEmpty(temp))
		return;
	while (!node_stack.Empty() || temp)
	{
		if (temp)
		{
			cout << *temp;
			cout << ' ';
			if(temp->right_child!=NULL)
				node_stack.Push(temp->right_child);
			temp = temp->left_child;
		}
		else
		{
			node_stack.Top(temp);
			node_stack.Pop();
		}
	}
	cout << endl;
}
template<class dataType>
void binaryTree<dataType>::midFirst(binaryTreeNode<dataType> *rt) {
	myListStack<binaryTreeNode<dataType> *> node_stack;
	binaryTreeNode<dataType> * temp = NULL;
	if (rt == NULL)
		rt = this->root;
	if (rt == NULL)
		return;
	temp = rt;
	while (!node_stack.Empty() ||temp)
	{
		if (temp!=NULL)
		{
			node_stack.Push(temp);
			temp = temp->left_child;
		}
		else
		{
			node_stack.Top(temp);
			cout << *temp;
			cout << ' ';
			node_stack.Pop();
			temp = temp->right_child;
		}
	}
	cout << endl;
}
template<class dataType>
void binaryTree<dataType>::postFirst(binaryTreeNode<dataType> * rt) {
	myListStack<binaryTreeNode<dataType> *> node_stack;
	binaryTreeNode<dataType> * temp;
	binaryTreeNode<dataType> *pre = NULL;
	if (rt == NULL)
		rt = this->root;
	if (rt == NULL)
		return;
	temp = rt;
	while (temp != NULL)
	{
		while (temp->left_child != NULL)
		{
			node_stack.Push(temp);
			temp = temp->left_child;
		}
		while (temp != NULL && (temp->right_child == NULL || temp->right_child == pre))
		{
			cout << *temp;
			cout << ' ';
			pre = temp;
			if (!node_stack.Top(temp))
			{
				cout << endl;
				return;
			}
			node_stack.Pop();
		}
		if (temp)
		{
			node_stack.Push(temp);
			temp = temp->right_child;
		}
	}
}
template<class dataType>
void binaryTree<dataType>::levelFirst(binaryTreeNode<dataType> *rt) {
	myListStack<binaryTreeNode<dataType> *> node_stack;
	binaryTreeNode<dataType> * temp = rt;
	if (rt == NULL)
		rt = this->root;
	if (rt == NULL)
		return;
}

//Recursive Traverse
template<class dataType>
void binaryTree<dataType>::preRec(binaryTreeNode<dataType>*rt) {
	if (rt == NULL)
		return;
	cout << *rt;
	if (rt->left_child)
	this->preRec(rt->left_child);
	if (rt->right_child)
	this->preRec(rt->right_child);
}
template<class dataType>
void binaryTree<dataType>::midRec(binaryTreeNode<dataType> *rt) {
	if (rt == NULL)
		return;
	if(rt->left_child)
	this->midRec(rt->left_child);
	cout << *rt;
	if(rt->right_child)
	this->midRec(rt->right_child);
}
template<class dataType>
void binaryTree<dataType>::postRec(binaryTreeNode<dataType> * rt) {
	if (rt == NULL)
		return;
	if (rt->left_child)
	this->postRec(rt->left_child);
	if (rt->right_child)
	this->postRec(rt->right_child);
	cout << *rt;
}

//Count Method
template<class dataType>
int binaryTree<dataType>::countLeaf(binaryTreeNode<dataType> *rt, int & count) {
	if (rt)
	{
		if ((!rt->left_child) && (!rt->right_child)) count++;
		if (rt->left_child)
			countLeaf(rt->left_child, count);
		if (rt->right_child)
			countLeaf(rt->right_child, count);
		return count;
	}
}
template<class dataType>
int binaryTree<dataType>::countDepth(binaryTreeNode<dataType> *rt, int level,int&depth) {
	if (rt)
	{
		if (depth < level)
			depth = level;
		countDepth(rt->left_child, level + 1, depth);
		countDepth(rt->right_child, level + 1, depth);
		return depth;
	}
	return 0;
}
template<class dataType>
int binaryTree<dataType>::countOneNode(binaryTreeNode<dataType> *rt, int &count) {
	if (rt)
	{
		if (((rt->left_child) && (!rt->right_child)) || ((!rt->left_child) && (rt->right_child)))
		{
			count++;
		}
		if (rt->left_child)
			countOneNode(rt->left_child, count);
		if (rt->right_child)
			countOneNode(rt->right_child, count);
		return count;
	}
}
template<class dataType>
int binaryTree<dataType>::countTwoNode(binaryTreeNode<dataType>*rt, int&count) {
	if ((rt->left_child) && (rt->right_child))
	{
		count++;
	}
	if (rt->left_child)
		countTwoNode(rt->left_child, count);
	if (rt->right_child)
		countTwoNode(rt->right_child, count);
	return count;
}
template<class dataType>
int binaryTree<dataType>::getMax(binaryTreeNode<dataType> *rt, int& max) {
	if (root != NULL)
	{
		max = this->root->data;
		getmax(rt, max);
	}
	return max;
}
template<class dataType>
int binaryTree<dataType>::getmax(binaryTreeNode<dataType> *rt, int& max) {
	if (rt != NULL)
	{
		if (rt->data > max)
			max = rt->data;
		getmax(rt->left_child, max);
		getmax(rt->right_child, max);
	}
	return max;
}
template<class dataType>
int binaryTree<dataType>::countWidthNRec(binaryTreeNode<dataType> *rt) {
	myListQueue<binaryTreeNode<dataType>*> node_queue;
	binaryTreeNode<dataType>* temp;
	int length = 0;
	int max_length = 1;
	if (rt != NULL)
		node_queue.EnQueue(rt);
	while (true)
	{
		length = node_queue.node_sum;
		if (length == 0)
		{
			break;
		}
		if (length > max_length)
			max_length = length;
		while (length > 0)
		{
			node_queue.DeQueue(temp);
			if (temp->left_child)
				node_queue.EnQueue(temp->left_child);
			if (temp->right_child)
				node_queue.EnQueue(temp->right_child);
			length--;
		}
	}
	return max_length;
}
template<class dataType>
int binaryTree<dataType>::countWidth(binaryTreeNode<dataType> *rt) {
	int max = 0;
	int depth = 0;
	int counter;
	int *width = new int[this->countDepth(this->root, 1, depth)];
	for (counter = 0; counter < depth; counter++)
	{
		width[counter] = 0;
	}
	this->countwidth(this->root, 0, width);
	for (counter = 0; counter < depth; counter++)
	{
		if (max < width[counter])
			max = width[counter];
	}
	delete width;
	return max;
}
template<class dataType>
int binaryTree<dataType>::countwidth(binaryTreeNode<dataType> *rt, int level, int *width) {
	if (rt)
	{
		width[level] ++;
		countwidth(rt->left_child, level + 1, width);
		countwidth(rt->right_child, level + 1, width);
	}
	return 0;
}

//Search Method
template<class dataType>
bool binaryTree<dataType>::searchRec(binaryTreeNode<dataType> *rt, int value) {
	if (rt)
	{
		if (rt->data == value)
			return true;
		else
		{
			return searchRec(rt->left_child, value) || searchRec(rt->right_child, value);
		}
	}
}
template<class dataType>
bool binaryTree<dataType>::searchLoop(int & value, binaryTreeNode<dataType> *rt) {
	myListStack<binaryTreeNode<dataType> *> node_stack;
	if (rt == NULL)
	{
		rt = this->root;
	}
	if (rt == NULL)
		return false;
	while (rt || !node_stack.Empty())
	{
		if (rt == NULL)
		{
			node_stack.Top(rt);
			node_stack.Pop();
		}
		if (rt->data == value)
			return true;
		if (rt->right_child != NULL)
			node_stack.Push(rt->right_child);
		rt = rt->left_child;
	}
	return false;
}

template<class dataType>
void binaryTree<dataType>::changeLF(binaryTreeNode<dataType> *rt) {
	binaryTreeNode<dataType> *temp;
	if (rt)
	{
		temp = rt->left_child;
		rt->left_child = rt->right_child;
		rt->right_child= temp;
		if(rt->left_child)
		changeLF(rt->left_child);
		if(rt->right_child)
		changeLF(rt->right_child);
	}
}

template<class dataType>
void get_str(myList<dataType>& mlst) {
	dataType num = 0;
	int counter = 0, flag = 1;
	int temp;
	if (typeid(num) == typeid(char))
		flag = 0;
	temp = getchar();
	while (1)
	{
		while (temp != ' ' &&temp != '\n')
		{
			if (temp >= 48 && temp < 58 && flag)
			{
				num = num * 10 + temp - 48;
			}
			else
			{
				num = temp;
			}
			temp = cin.get();
		}
		mlst.EnQueue(num);
		num = 0;
		if (temp == '\n')
			break;
		temp = cin.get();
	}
	return;
}

//Transfer Str to Tree
template<class dataType>
void binaryTree<dataType>::preMidTran() {
	//                A
	//         B           F
	//    E      C               G
	//                D      H        j      
	//                            I
	/*pre: A B E C D F G H I J
E B C D A F H I G J*/
	string pre("ABECDFGHIJ");
	string mid("EBCDAFHIGJ");
	char temp = pre[0];
	this->root = new binaryTreeNode<dataType>(pre[0]);
	if(mid.find(temp))
		this->root->left_child = premidTran(pre.substr(1,mid.find(temp)),mid.substr(0,mid.find(temp)));
	if(mid.find(temp) != mid.size()-1)
		this->root->right_child =  premidTran(pre.substr(mid.find(temp)+1, pre.size()-1),mid.substr(mid.find(temp) + 1, pre.size() - 1));
}
template<class dataType>
binaryTreeNode<dataType> * binaryTree<dataType>::premidTran(string pre, string mid) {
	binaryTreeNode<dataType> * temp_p = NULL;
	if (!pre.empty() && !mid.empty())
	{
		char temp = pre[0];
		temp_p = new binaryTreeNode<dataType>(temp);
		if (mid.find(temp))
			temp_p->left_child = premidTran(pre.substr(1, mid.find(temp)), mid.substr(0, mid.find(temp)));
		if (mid.find(temp) != mid.size() - 1)
			temp_p->right_child = premidTran(pre.substr(mid.find(temp) + 1, pre.size() - 1), mid.substr(mid.find(temp) + 1, pre.size() - 1));
	}
		return temp_p;
}
template<class dataType>
void binaryTree<dataType>::postMidTran() {
	string post("EDCBIHJGFA");
	string mid("EBCDAFHIGJ");
	char temp = post[post.size() - 1];
	this->root = new binaryTreeNode <dataType>(temp);
	if (mid.find(temp) != mid.size() - 1)
		this->root->right_child = postmidTran(post.substr(mid.find(temp), post.size() - mid.find(temp)-1), mid.substr(mid.find(temp) + 1, mid.size() - 1));
	if (mid.find(temp))
		this->root->left_child = postmidTran(post.substr(0, mid.find(temp)), mid.substr(0, mid.find(temp)));

	//                A
	//         B           F
	//    E      C                G
	//               D         H      j      
	//                              I
	//
	/*post: E D C B I H J G F A
                E B C D A F H I G J*/
}
template<class dataType>
binaryTreeNode<dataType>* binaryTree<dataType>::postmidTran(string post, string mid) {
	binaryTreeNode<dataType> * temp_p = NULL;
	if (!post.empty() && !mid.empty())
	{
		char temp = post[post.size() - 1];
		temp_p = new binaryTreeNode <dataType>(temp);
		if (mid.find(temp) != mid.size() - 1)
		{
			temp_p->right_child = postmidTran(post.substr(mid.find(temp), post.size() - mid.find(temp) - 1), mid.substr(mid.find(temp) + 1, mid.size() - 1));
		}
		if (mid.find(temp))
			temp_p->left_child = postmidTran(post.substr(0, mid.find(temp) ), mid.substr(0, mid.find(temp)));
	}
	return temp_p;
}



#pragma once
