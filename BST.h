#pragma once

class BST
{
public:
	BST();
	~BST();
	struct Node{
		int value;
		Node *left;
		Node *right;

		Node(int val){
			value = val;
			left = nullptr;
			right = nullptr;
		}
	};
	int size();
	void print();
	void erase(int val);
	void insert(int val);
	void inOrder();
	void postOrder();
	void preOrder();

private:
	Node *root;
	void print(Node *leaf, int depth);
	void erase(Node *&leaf, int val);
	void insert(int val, Node *&leaf);
	void destroyTree(Node *&leaf);
	Node* findMinimun(Node *leaf);
	int size(Node *leaf);
	void inOrder(Node *leaf);
	void postOrder(Node *leaf);
	void preOrder(Node *leaf);
};