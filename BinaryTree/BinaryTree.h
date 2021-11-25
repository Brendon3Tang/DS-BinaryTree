#pragma once
#include <iostream>
using namespace std;

struct BinaryNode {
	char data;
	BinaryNode* leftChild, * rightChild;
};

//struct pNode {
//	int parent;
//	char data;
//};

class BinaryTree
{
private:
	BinaryNode* root, * subRoot, * saveRoot;
	int leftOrRight;
public:

	int depth, leavesNum;

	BinaryTree() { this->root = Create(root); depth = 0; leavesNum = 0; saveRoot = NULL; leftOrRight = 0; }

	~BinaryTree()
	{ Release(root); cout << "Îö¹¹Íê³É" << endl;}

	void PreOrder() { PreOrder(root); }

	void InOrder() { InOrder(root); }

	void PostOrder() { PostOrder(root); }

	void LevelOrder(BinaryNode* bNode);

	BinaryNode* getRoot();

	int getDepth(BinaryNode* bNode);

	int getLeavesNum(BinaryNode* bNode);

	BinaryNode* search(BinaryNode* bNode, char item);

	void deleteSubTree(BinaryNode*& bNode);

private:
	BinaryNode* Create(BinaryNode* bTree);

	void Release(BinaryNode*& bTree);

	void PreOrder(BinaryNode* bTree);

	void InOrder(BinaryNode* bTree);

	void PostOrder(BinaryNode* bTree);

	void findRoot(BinaryNode* bTree, BinaryNode* find);

	void cleanHelper(BinaryNode* bTree);
};