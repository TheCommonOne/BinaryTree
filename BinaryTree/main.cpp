#include "binarytree.h"
#include"binarySearchTree.h"
#include"maxHeap.h"
#include"minHeap.h"
#include"AVLTree.h"
#include"HuffmanTree.h"
 //五六题
/*
int main() {
	binaryTree<int>  tr1(10);
	int i = 0;
	//                     0
	//            1                 2
	//     3          4       5         6
	//   7  8     9 
	cout << "One: "<<tr1.countOneNode(tr1.root, i);
	i = 0;
	cout << endl<<"Two: "<<tr1.countTwoNode(tr1.root, i);
	i = 0;
	cout << endl << "Leaf: "<<tr1.countLeaf(tr1.root, i);
	cout << endl;

	cout << "No Change" << endl;
	tr1.preFirst();
	tr1.changeLF(tr1.root);
	cout << "Change L F" << endl;
	tr1.preFirst();

	i = 0;
	binaryTree<char> tr;
	tr.preMidTran();
	tr.countDepth(tr.root, 0, i);
	cout << "Depth: " << i << endl;
	//                A
	//         B           F
	//    E      C                G
	//               D         H      j      
	//                              I
	//
	cout << "Width: " << tr.countWidth(tr.root)<<endl;
	cout << "Width(No Rec): " << tr.countWidthNRec(tr.root) << endl;

	cout << "Delete Leaf (10) : " << endl;
	tr.breadthFirst();
	tr.deleteLeaf(tr.root);
	tr.breadthFirst();

	cout << "Delete Leaf (1) : " << endl;
	binaryTree<int> t(1);
	t.breadthFirst();
	t.deleteLeaf(t.root);
	t.breadthFirst();

	cout << tr.isComplete(tr.root);
	cout<<tr1.isComplete(tr1.root);
	cout << t.isComplete(t.root);
	binaryTree<int> tr3(3);
	cout << tr3.isComplete(tr3.root);
	binaryTree<int> tr4(4);
	cout << tr4.isComplete(tr4.root);
	system("pause");
}
*/

//优先队列，堆
/*int main()
{
	minHeap<int> mh(10);
	//注意添加BuildHeap；
	mh.removeMin();
	cout << mh;
	system("pause");
	return 0;
}*/

//搜索树
/*int main() {
	//insert 函数
	binarySearchTree<int> sctr;
	sctr.insert(13);
	sctr.insert(8);
	sctr.insert(23);
	sctr.insert(5);
	sctr.insert(18);
	sctr.insert(37);
	int i = 0;
	int data;
	sctr.breadthFirst();
	cout<<*sctr.search(18);
	cout << endl;
	sctr.deleteBinaryTree();

	//Merge Delete 1
	sctr.insert(15);
	sctr.insert(10);
	sctr.insert(5);
	sctr.insert(11);
	sctr.insert(12);
	sctr.insert(30);
	sctr.insert(20);
	sctr.insert(40);
	sctr.breadthFirst();
	sctr.mergeDelete(sctr.search(15));
	sctr.breadthFirst();
	cout << endl;
	sctr.deleteBinaryTree();

	//Merge delete 2
	sctr.insert(15);
	sctr.insert(10);
	sctr.insert(5);
	sctr.insert(2);
	sctr.insert(6);
	sctr.insert(30);
	sctr.insert(20);
	sctr.insert(40);
	sctr.breadthFirst();
	sctr.mergeDelete(sctr.search(15));
	sctr.breadthFirst();
	sctr.deleteBinaryTree();

	// Copy Delete 1
	sctr.insert(400);
	sctr.insert(122);
	sctr.insert(450);
	sctr.insert(99);
	sctr.insert(250);
	sctr.insert(500);
	sctr.insert(110);
	sctr.insert(200);
	sctr.insert(300);
	sctr.insert(105);
	sctr.insert(330);
	sctr.breadthFirst();
	sctr.copyDelete(sctr.search(300));
	sctr.breadthFirst();
	sctr.preFirst();
	sctr.deleteBinaryTree();

	//Copy delete 2
	sctr.insert(400);
	sctr.insert(122);
	sctr.insert(450);
	sctr.insert(99);
	sctr.insert(250);
	sctr.insert(500);
	sctr.insert(110);
	sctr.insert(200);
	sctr.insert(300);
	sctr.insert(105);
	sctr.insert(330);
	sctr.breadthFirst();
	sctr.copyDelete(sctr.search(122));
	sctr.breadthFirst();
	sctr.preFirst();
	sctr.deleteBinaryTree();

	sctr.insert(20);
	sctr.insert(9);
	sctr.insert(2);
	sctr.insert(11);
	sctr.insert(13);
	sctr.insert(30);
	sctr.insert(22);
	sctr.insert(16);
	sctr.insert(17);
	sctr.insert(15);
	sctr.insert(18);
	sctr.insert(10);
	sctr.breadthFirst();
	sctr.preFirst();
	system("pause");
	return 0;
}*/

//AVL树
/*
int main() {
	AVLTree<int> at;
	at.insert(20);
	at.preFirst();
	at.insert(9);
	at.preFirst();
	at.insert(2);
	at.preFirst();
	at.insert(11);
	at.preFirst();
	at.insert(13);
	at.preFirst();
	at.insert(30);
	at.preFirst();
	at.insert(22);
	at.preFirst();
	at.insert(16);
	at.preFirst();
	at.insert(17);
	at.preFirst();
	at.insert(15);
	at.preFirst();
	at.insert(18);
	at.preFirst();
	at.insert(10);
	at.preFirst();
	at.dltItem(22);
	at.preFirst();
	at.dltItem(2);
	at.preFirst();
	at.dltItem(10);
	at.preFirst();
	at.dltItem(9);
	at.preFirst();
	at.breadthFirst();
	system("pause");
}
*/

//堆
/*
int main() {
	maxHeap<int> mhp(20);
	mhp.Insert(46);
	mhp.Insert(79);
	mhp.Insert(56);
	mhp.Insert(38);
	mhp.Insert(40);
	mhp.Insert(84);
	mhp.Insert(50);
	mhp.Insert(42);
	cout << mhp;
	system("pause");
}
*/

int main() {
	int *a = new int[10];
	a[0] = 2;
	a[1] = 3;
	a[2] = 4;
	HuffmanTree<int> ht(a,3);
	ht.preFirst(ht.root);
	system("pause");
	return 0;
}

