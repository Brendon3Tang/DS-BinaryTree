#pragma once
#include <iostream>
using namespace std;

struct BinaryNode {
	char data;
	BinaryNode* leftChild, * rightChild;
};


class BinaryTree
{
private:
	BinaryNode* root;
public:

	BinaryTree() { this->root = Create(root); }

	~BinaryTree() { Release(root); }

	void PreOrder() { PreOrder(root); }

	void InOrder() { InOrder(root); }

	void PostOrder() { PostOrder(root); }

	void LevelOrder(BinaryNode* bNode);

	BinaryNode* getRoot();

private:
	BinaryNode* Create(BinaryNode*bTree);

	void Release(BinaryNode* bTree);

	void PreOrder(BinaryNode* bTree);

	void InOrder(BinaryNode* bTree);

	void PostOrder(BinaryNode* bTree);
};