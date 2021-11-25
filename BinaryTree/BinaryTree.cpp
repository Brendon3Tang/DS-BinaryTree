#include "BinaryTree.h"
#include <queue>

//void input(char& paraData)
//{
//	cout << "������ýڵ㴢������ݣ�" << endl;
//	cin >> paraData;
//}


BinaryNode* BinaryTree::Create(BinaryNode* bt)
{
	char ch;
	cout << "������ýڵ㴢������ݣ�" << endl;
	cin >> ch;
	if (ch == '#')
		return NULL;
	else
	{
		bt = new BinaryNode();
		bt->data = ch;
		bt->leftChild = Create(bt->leftChild); //����ֻ�ܴ��벻�ܴ���������Ҫʹbt->leftChild = Create(bt->leftChild)
		bt->rightChild = Create(bt->rightChild);
	}
	return bt;


}

//ʹ��postOrder���߼�����������
void BinaryTree::Release(BinaryNode*& bt)
{
	/*������A, ֻ��һ���ӽڵ�B����ô��������ʱ��ֱ������line45��Ȼ�����ݹ飬ɾ���ڵ�B��Ȼ�󷵻ؼ�������line46, ����������Aֻ��һ���ڵ㣬
���bt->rightChild = NULL�����������Release(NULL)������ݹ齫�޷��������С�*/
	if (bt == NULL)
		return;

	//�����������ֻ��root�ڵ㣬�����ڵݹ��еִ���Ҷ�ӽڵ�ʱ��ɾ���ýڵ㣬��������һ��ݹ�
	//if (bt->leftChild == NULL && bt->rightChild == NULL)
	//{
	//	cout << "����Ҷ�ڵ�/Ŀǰֻ�и��ڵ�: " << bt->data << "����ɾ����" << endl;
	//	delete bt;
	//	bt = NULL;
	//	return;
	//}


	//ʹ��PostOrder���߼�ɾ���ڵ�
	else
	{
		Release(bt->leftChild);
		Release(bt->rightChild);
		if (this->root->leftChild != NULL)
		{
			if (this->root->leftChild->leftChild != NULL)
			{
				cout << "�ÿ�ǰroot�����ӣ�" << this->root->leftChild->leftChild << endl;
			}
			if (this->root->leftChild->rightChild != NULL)
			{
				cout << "�ÿ�ǰroot���Һ��ӣ�" << this->root->leftChild->rightChild << endl;
			}


		}

		cout << "�ÿ�ǰbt��" << bt << endl;
		cout << "���ͷŽڵ㣺" << bt->data << endl;
		delete bt;
		bt = NULL;
		cout << "�ÿպ�" << bt << endl;
		//cout << "root�������ӵ�ֵ��" << this->root->leftChild->leftChild->data << endl;
		if (this->root != NULL && this->root->leftChild != NULL)
		{
			cout << "root�����ӣ�" << this->root->leftChild << endl;
			if (this->root->leftChild->leftChild != NULL)
			{
				cout << "�ÿպ�root�����ӣ�" << this->root->leftChild->leftChild << endl;
			}
			if (this->root->leftChild->rightChild != NULL)
			{
				cout << "�ÿպ�root���Һ��ӣ�" << this->root->leftChild->rightChild << endl;
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
		//cout << "ROOT�ǣ�" << bt->data << endl;
		//cout << "root�ĵ�ַ��" << bt << endl;
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
	//���reach��Ҷ�ӽڵ���ӽڵ������Ϊ������leave������Ϊ0������0
	if (bNode == NULL)
		return 0;
	//��������ݹ飬�ڵݹ�������������Ҷ�ӽڵ㣬leavesNum++������ݹ���ɺ󷵻ص�ǰ��leavesNumֵ
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
		cout << "bNode�ǣ�" << bNode->data << endl;
		subRoot = bNode;
		cout << "result�ǣ�" << subRoot->data << endl;

	}
	search(bNode->leftChild, item);
	search(bNode->rightChild, item);

	return subRoot;
}

//�ҵ��������ڵ����һ���ڵ�X��������ýڵ㣬Ȼ��X�ڵ����/���ӽڵ��ÿգ��������Ұָ��
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
	//��find�����ҵ��������ڵ����һ���ڵ㣬������ýڵ�
	findRoot(this->root, bNode);

	Release(bNode);

	/*Release bNode֮��bNode���ÿգ�����ָ��bNode��xxx->childָ�벻�ᱻ�ÿա�
	��ʱ����Ҫ��xxx�����saveRoot,����saveRoot->L/Rchild�ÿ�����xxx->child�ÿգ��������Ұָ��*/
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
	cout << "ɾ�������Ľڵ㣺" << bNode->data << endl;
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
	cout << "��ָ���ַ��" << subRoot << endl;

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

	cout << "Ҷ�ӽڵ������" << myBT.getLeavesNum(myBT.getRoot()) << endl;

	cout << "������ȣ�" << myBT.getDepth(myBT.getRoot()) << endl;

	subRoot = myBT.search(myBT.getRoot(), 'B');
	//cout << "subRoot�ǣ�" << subRoot->data << endl;

	cout << "ɾ���ڵ�B������: " << endl;
	myBT.deleteSubTree(subRoot);
	cout << "ɾ�����" << endl;

	cout << "ɾ����PreOrder: " << endl;
	myBT.PreOrder();
	cout << endl;

	//pNode arr[10]; 

	return 0;
}