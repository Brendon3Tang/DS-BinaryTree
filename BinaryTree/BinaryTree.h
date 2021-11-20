#pragma once
#include <iostream>
using namespace std;

struct BinaryNode {
	char data;
	BinaryNode* leftChild, * rightChild;
};

struct pNode {
	int parent;
	char data;
};

class BinaryTree
{
private:
	BinaryNode* root;
public:
	
	int depth, leavesNum;

	BinaryTree() { this->root = Create(root); depth = 0; leavesNum = 0; }

	~BinaryTree() { Release(root); }

	void PreOrder() { PreOrder(root); }

	void InOrder() { InOrder(root); }

	void PostOrder() { PostOrder(root); }

	void LevelOrder(BinaryNode* bNode);

	BinaryNode* getRoot();

	int getDepth(BinaryNode* bNode);

	int getLeavesNum(BinaryNode* bNode);

	void setArr(pNode arr[]);

private:
	BinaryNode* Create(BinaryNode*bTree);

	void Release(BinaryNode* bTree);

	void PreOrder(BinaryNode* bTree);

	void InOrder(BinaryNode* bTree);

	void PostOrder(BinaryNode* bTree);
};