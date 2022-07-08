#include <iostream>
#include "Header.h"
using namespace std;

template<typename T>
struct BinaryTree<T>::Node
{
	T data;

	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
};
template<typename T>
BinaryTree<T>::BinaryTree(T rootData)
{
	Node* temp = new Node();
	temp->data = rootData;
	root = temp;
	size++;
}
template<typename T>
void BinaryTree<T>::Print(Node* node)
{
	cout << node->data << " ";
	if (node->left)
		Print(node->left);
	if (node->right)
		Print(node->right);
}
template<typename T>
void BinaryTree<T>::Delete(Node* node)
{
	if (node->left)
		Delete(node->left);
	if (node->right)
		Delete(node->right);
	delete node;
}
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	Delete(root);
}
template<typename T>
void BinaryTree<T>::Add(T data)
{
	Node* temp = new Node();
	temp->data = data;
	if (!root)
		root = temp;
	else
	{
		Node* parent = root;
		while (true)
			if (temp->data > parent->data)
				if (parent->right) parent = parent->right;
				else break;
			else if (temp->data < parent->data)
				if (parent->left) parent = parent->left;
				else break;
			else return;
		if (temp->data > parent->data)
		{
			temp->parent = parent; 
			parent->right = temp;
		}
		else if (temp->data < parent->data)
		{
			temp->parent = parent; 
			parent->left = temp;
		}
	}
	size++;
}
template<typename T>
void BinaryTree<T>::Delete(T data)
{
	Node* temp = root;
	while (true)
		if (data > temp->data)
			if (temp->right) temp = root->right;
			else return;
		else if (data < temp->data)
			if (temp->left) temp = root->left;
			else return;
		else break;

	if (!temp->right && !temp->left)
	{
		if (temp->data < temp->parent->data)
			temp->parent->left = nullptr;
		else
			temp->parent->right = nullptr;
		delete temp;
	}
	else if (temp->right && temp->left)
	{
		if (temp->right->data - temp->data < temp->data - temp->left->data)
		{
			if (temp->data < temp->parent->data)
				temp->parent->left = temp->right;
			else
				temp->parent->right = temp->right;

			Node* t = temp->right;
			while (t->left)
				t = t->left;

			t->left = temp->left;
			temp->left->parent = t;
		}
		else
		{
			if (temp->data < temp->parent->data)
				temp->parent->left = temp->left;
			else
				temp->parent->right = temp->left;

			Node* t = temp->left;
			while (t->right)
				t = t->right;

			t->right = temp->right;
			temp->right->parent = t;
		}
		delete temp;
	}
	else if (temp->right)
	{
		if (temp->data < temp->parent->data)
			temp->parent->left = temp->right;
		else
			temp->parent->right = temp->right;
		delete temp;
	}
	else
	{
		if (temp->data < temp->parent->data)
			temp->parent->left = temp->left;
		else
			temp->parent->right = temp->left;
		delete temp;
	}
	size--;
}
template<typename T>
bool BinaryTree<T>::inTree(T data)
{
	Node* temp = root;
	while (true)
		if (temp->data = data)
			return true;
		else if (data > temp->data)
			if (temp->right) temp = root->right;
			else return false;
		else
			if (temp->left) temp = root->left;
			else return false;
}
template<typename T>
bool BinaryTree<T>::isEmpty()
{
	return size == 0;
}
template<typename T>
int BinaryTree<T>::getSize()
{
	return size;
}
template<typename T>
void BinaryTree<T>::Print()
{
	if (root)
		Print(root);
	cout << endl;
}


int main()
{
	BinaryTree<int> bt;
	bt.Add(100);
	bt.Add(110);
	bt.Add(90);
	for (int i = 0; i < 20; i++)
		bt.Add(50 + rand() % 100);

	bt.Delete(90);
	bt.Print();

	return 0;
}