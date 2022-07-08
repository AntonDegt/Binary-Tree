#pragma once

template <typename T>
class BinaryTree
{
public:
	struct Node;

private:
	Node* root;
	int size = 0;

	void Delete(Node* node);
	void Print(Node* node);

public:
	BinaryTree() = default;
	BinaryTree(T rootData);
	~BinaryTree();

	void Add(T data);
	void Delete(T data);
	bool inTree(T data);
	bool isEmpty();
	int getSize();

	void Print();
};
