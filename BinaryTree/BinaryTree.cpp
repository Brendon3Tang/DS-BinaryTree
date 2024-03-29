#include "BinaryTree.h"
#include <queue>

//void input(char& paraData)
//{
//	cout << "请输入该节点储存的数据：" << endl;
//	cin >> paraData;
//}


BinaryNode* BinaryTree::Create(BinaryNode* bt)
{
	char ch;
	cout << "请输入该节点储存的数据：" << endl;
	cin >> ch;
	if (ch == '#')
		return NULL;
	else
	{
		bt = new BinaryNode();
		bt->data = ch;
		bt->leftChild = Create(bt->leftChild); //参数只能传入不能传出，所以要使bt->leftChild = Create(bt->leftChild)
		bt->rightChild = Create(bt->rightChild);
	}
	return bt;


}

//使用postOrder的逻辑析构二叉树
void BinaryTree::Release(BinaryNode*& bt)
{
	/*假设树A, 只有一个子节点B。那么析构该树时会直接运行line45；然后进入递归，删除节点B；然后返回继续运行line46, 但是由于树A只有一个节点，
因此bt->rightChild = NULL，如果不设置Release(NULL)的情况递归将无法继续进行。*/
	if (bt == NULL)
		return;

	//如果二叉树中只有root节点，或者在递归中抵达了叶子节点时，删除该节点，并返回上一层递归
	//if (bt->leftChild == NULL && bt->rightChild == NULL)
	//{
	//	cout << "到达叶节点/目前只有根节点: " << bt->data << "。已删除！" << endl;
	//	delete bt;
	//	bt = NULL;
	//	return;
	//}


	//使用PostOrder的逻辑删除节点
	else
	{
		Release(bt->leftChild);
		Release(bt->rightChild);
		if (this->root->leftChild != NULL)
		{
			if (this->root->leftChild->leftChild != NULL)
			{
				cout << "置空前root左左孩子：" << this->root->leftChild->leftChild << endl;
			}
			if (this->root->leftChild->rightChild != NULL)
			{
				cout << "置空前root左右孩子：" << this->root->leftChild->rightChild << endl;
			}


		}

		cout << "置空前bt：" << bt << endl;
		cout << "已释放节点：" << bt->data << endl;
		delete bt;
		bt = NULL;
		cout << "置空后：" << bt << endl;
		//cout << "root的左左孩子的值：" << this->root->leftChild->leftChild->data << endl;
		if (this->root != NULL && this->root->leftChild != NULL)
		{
			cout << "root的左孩子：" << this->root->leftChild << endl;
			if (this->root->leftChild->leftChild != NULL)
			{
				cout << "置空后root左左孩子：" << this->root->leftChild->leftChild << endl;
			}
			if (this->root->leftChild->rightChild != NULL)
			{
				cout << "置空后root左右孩子：" << this->root->leftChild->rightChild << endl;
			}


		}
		cout << endl;
		return;
	}
}

void visit(char paraData)
{
	cout << paraData << " ";
}

void BinaryTree::PreOrder(BinaryNode* bt)
{
	if (bt == NULL)
		return;
	else
	{
		//cout << "ROOT是：" << bt->data << endl;
		//cout << "root的地址：" << bt << endl;
		visit(bt->data);
		PreOrder(bt->leftChild);
		PreOrder(bt->rightChild);
	}
}

void BinaryTree::InOrder(BinaryNode* bt)
{
	if (bt == NULL)
		return;
	else
	{
		InOrder(bt->leftChild);
		visit(bt->data);
		InOrder(bt->rightChild);
	}
}

void BinaryTree::PostOrder(BinaryNode* bt)
{
	if (bt == NULL)
		return;
	else
	{
		PostOrder(bt->leftChild);
		PostOrder(bt->rightChild);
		visit(bt->data);
	}
}

void BinaryTree::LevelOrder(BinaryNode* bNode)
{
	queue<BinaryNode*> myQueue;
	//char result;

	if (bNode == NULL)
		return;
	else
	{
		myQueue.push(bNode);
		while (!myQueue.empty())
		{

			visit(myQueue.front()->data);
			if (myQueue.front()->leftChild != NULL)
				myQueue.push(myQueue.front()->leftChild);
			if (myQueue.front()->rightChild != NULL)
				myQueue.push(myQueue.front()->rightChild);
			myQueue.pop();

		}
	}
}

BinaryNode* BinaryTree::getRoot()
{
	return this->root;
}

int BinaryTree::getDepth(BinaryNode* bNode)
{
	if (bNode != NULL)
	{
		depth = max(getDepth(bNode->leftChild), getDepth(bNode->rightChild)) + 1;
		return depth;
	}
	else
		return 0;
}

int BinaryTree::getLeavesNum(BinaryNode* bNode)
{
	//如果reach到叶子节点的子节点或者树为空树，leave的数量为0，返回0
	if (bNode == NULL)
		return 0;
	//否则继续递归，在递归过程中如果遇到叶子节点，leavesNum++。当层递归完成后返回当前的leavesNum值
	else
	{
		getLeavesNum(bNode->leftChild);
		getLeavesNum(bNode->rightChild);
		if (bNode->leftChild == NULL && bNode->rightChild == NULL)
		{
			leavesNum++;
			//cout << "leavesNUM is: " << leavesNum << endl;
		}
		return leavesNum;
	}
}

BinaryNode* BinaryTree::search(BinaryNode* bNode, char item)
{

	if (bNode == NULL)
		return bNode;

	if (bNode->data == item)
	{
		cout << "bNode是：" << bNode->data << endl;
		subRoot = bNode;
		cout << "result是：" << subRoot->data << endl;

	}
	search(bNode->leftChild, item);
	search(bNode->rightChild, item);

	return subRoot;
}

//找到子树根节点的上一个节点X，并保存该节点，然后将X节点的左/右子节点置空，以免产生野指针
void BinaryTree::findRoot(BinaryNode* bTree, BinaryNode* find)
{
	if (bTree == NULL || this->saveRoot != NULL)
	{
		return;
	}
	if (bTree->leftChild == find)
	{
		this->leftOrRight = 0;
		this->saveRoot = bTree;
		return;
	}
	if (bTree->rightChild == find)
	{
		this->leftOrRight = 1;
		this->saveRoot = bTree;
		return;
	}
	findRoot(bTree->leftChild, find);
	findRoot(bTree->rightChild, find);
}

void BinaryTree::deleteSubTree(BinaryNode*& bNode)
{
	//用find函数找到子树根节点的上一个节点，并保存该节点
	findRoot(this->root, bNode);

	Release(bNode);

	/*Release bNode之后，bNode被置空，但是指向bNode的xxx->child指针不会被置空。
	此时就需要把xxx保存给saveRoot,并将saveRoot->L/Rchild置空来将xxx->child置空，以免出现野指针*/
	if (saveRoot != NULL)
	{
		if (leftOrRight == 0)
		{
			saveRoot->leftChild = NULL;
		}
		else
		{
			saveRoot->rightChild = NULL;
		}
	}
	/*if (bNode == NULL)
		return;


	deleteSubTree(bNode->leftChild);
	deleteSubTree(bNode->rightChild);
	cout << "删除子树的节点：" << bNode->data << endl;
	delete bNode;
	bNode = NULL;

	return;*/

}

//void BinaryTree::setArr(pNode arr[])
//{
//	arr[0].data = this->root->data;
//}

int main()
{
	BinaryTree myBT;
	BinaryNode* subRoot = NULL;
	cout << "空指针地址：" << subRoot << endl;

	cout << "PreOrder: " << endl;
	myBT.PreOrder();
	cout << endl;

	cout << "InOrder: " << endl;
	myBT.InOrder();
	cout << endl;

	cout << "PostOrder: " << endl;
	myBT.PostOrder();
	cout << endl;

	cout << "LevelOrder: " << endl;
	myBT.LevelOrder(myBT.getRoot());
	cout << endl;

	cout << "叶子节点个数：" << myBT.getLeavesNum(myBT.getRoot()) << endl;

	cout << "树的深度：" << myBT.getDepth(myBT.getRoot()) << endl;

	subRoot = myBT.search(myBT.getRoot(), 'B');
	//cout << "subRoot是：" << subRoot->data << endl;

	cout << "删除节点B的子树: " << endl;
	myBT.deleteSubTree(subRoot);
	cout << "删除完成" << endl;

	cout << "删除后PreOrder: " << endl;
	myBT.PreOrder();
	cout << endl;

	//pNode arr[10]; 

	return 0;
}