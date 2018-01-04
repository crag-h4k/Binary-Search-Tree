#include "BST.h"
#include <iostream>
#include <iomanip>

using namespace std;

BST::BST(){
	root = nullptr;
}


BST::~BST(){
	destroyTree(root);
}

void BST::destroyTree(Node *&leaf){
	if (leaf != nullptr){
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}
int BST::size(Node *leaf){
	int left;
	int right;
	int current = 1;
	if (leaf == nullptr){
		return 0;
	}
	else{
		left = size(leaf->left);
		right = size(leaf->right);
		return (right + left + current);
	}
}

int BST::size(){
	return size(root);
}

void BST::print(){
	print(root, 0);
}

void BST::print(Node *leaf, int depth){
	cout << setw(4 * depth) << "";
	if (leaf == nullptr){
		cout << "[empty]" << endl;
	}
	else if ((leaf->right==nullptr) && (leaf->left==nullptr)){
		cout << leaf->value << " [leaf]" << endl;
	}
	else{
		cout << leaf->value << endl;
		print(leaf->right, depth + 1);
		print(leaf->left, depth + 1);
	}
}

BST::Node* BST::findMinimun(Node* leaf){
	while (leaf->left != nullptr){
		leaf = leaf->left;
	}
	return leaf;
}


void BST::erase(Node *&leaf, int value){
	if (value < leaf->value){
		 erase(leaf->left, value);
	}
	else if (value > leaf->value){
		erase(leaf->right, value);
	}
	else{
		if (leaf->left == nullptr && leaf->right == nullptr){
			delete leaf;
			leaf = nullptr;
		}
		else if (leaf->left == nullptr){
			Node *temp = leaf;
			leaf = leaf->right;
			delete temp;
		}
		else if (leaf->right == nullptr){
			Node *temp = leaf;
			leaf = leaf->left;
			delete temp;
		}
		else{
			Node *temp = findMinimun(root->right);
			leaf->value = temp->value;
			erase(leaf->right, temp->value);
		}
	}
}

void BST::erase(int val){
	erase(root, val);
}

void BST::insert(int val){
	insert(val, root);
}

void BST::insert(int val, Node *&leaf){
	if (leaf != nullptr){
		if (val < leaf->value){
			insert(val, leaf->left);
		}
		else{
			insert(val, leaf->right);
		}
	}
	else {
		leaf = new Node(val);
	}
}

void BST::inOrder(){
	inOrder(root);
}
void BST::postOrder(){
	postOrder(root);
}
void BST::preOrder(){
	preOrder(root);
}
void BST::inOrder(Node *leaf){
	if (leaf != nullptr){
		inOrder(leaf->left);
		cout << leaf->value << endl;
		inOrder(leaf->right);
	}
}
void BST::postOrder(Node *leaf){
	if (leaf != nullptr){
		postOrder(leaf->left);
		postOrder(leaf->right);
		cout << leaf->value << endl;
	}
}
void BST::preOrder(Node *leaf){
	if (leaf != nullptr){
		cout << leaf->value << endl;
		preOrder(leaf->left);
		preOrder(leaf->right);
	}
}