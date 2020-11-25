#ifndef BST_HPP
#define BST_HPP
#include <iostream>
using namespace std;

struct BST_node{
	BST_node * leftChild;
	BST_node * rightChild;
	int value;
};

class BST{
	private:
		BST_node * root;
		void printTree(const BST_node * r, unsigned int level);
		void printNode(const BST_node * node);
	public:
		BST();
		~BST();
		void insert(int x);
		bool isInserted(int x);
		void printTree();
};

#endif