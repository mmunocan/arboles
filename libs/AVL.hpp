#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include "NodeBT.hpp"
using namespace std;

class AVL_node : public NodeBT{
	public:
		AVL_node * leftChild;
		AVL_node * rightChild;
		int value;
		unsigned int height;
		// Agregar otras variables de ser necesario
	private:
};

class AVL{
	public:
		AVL();
		~AVL();
		void insert(int x);
		bool isInserted(int x);
		void printTree();
	private:
		AVL_node * root;
		void printTree(const AVL_node * r, unsigned int level);
		void printNode(const AVL_node * node);
		void insertFixup(const AVL_node * node); // Rebalanceo
		// Rotaciones simples. Las rotaciones dobles se realizan combinando las simples
		void leftRotate(const AVL_node * x, const AVL_node * y);
		void rightRotate(const AVL_node * x, const AVL_node * y);
};

#endif