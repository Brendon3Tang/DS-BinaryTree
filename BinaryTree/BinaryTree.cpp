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
void BinaryTree::Release(BinaryNode* bt)
{
	/*������A, ֻ��һ���ӽڵ�B����ô��������ʱ��ֱ������line45��Ȼ�����ݹ飬ɾ���ڵ�B��Ȼ�󷵻ؼ�������line46, ����������Aֻ��һ���ڵ㣬
���bt->rightChild = NULL�����������Release(NULL)������ݹ齫�޷��������С�*/
	if (bt == NULL)
		return;
	
	//�����������ֻ��root�ڵ㣬�����ڵݹ��еִ���Ҷ�ӽڵ�ʱ��ɾ���ýڵ㣬��������һ��ݹ�
	if (bt->leftChild == NULL && bt->rightChild == NULL)
	{
		cout << "����Ҷ�ڵ�/Ŀǰֻ�и��ڵ�: " << bt->data << "����ɾ����" << endl;
		delete bt;
		bt = NULL;
		return;
	}
	//ʹ��PostOrder���߼�ɾ���ڵ�
	else
	{
		Release(bt->leftChild);
		Release(bt->rightChild);
		cout << "��ɾ���ڵ㣺" << bt->data << endl;
		delete bt;
		return;
	}
}

void visit(char paraData)
{
	cout<< paraData << " ";
}

void BinaryTree::PreOrder(BinaryNode* bt)
{
	if (bt == NULL)
		return;
	else
	{
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


int main()
{
	BinaryTree myBT;

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

	return 0;
}