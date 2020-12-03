#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include "NodeBT.hpp"
using namespace std;

class AVL_node : public NodeBT{
	public:
		// Agregar otras variables de ser necesario
		unsigned int height;
		AVL_node(int x);
		~AVL_node();		
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
		int nodes;
		void printTree(const NodeBT * r, unsigned int level);
		void printNode(const NodeBT * no);
		void insertFixup(NodeBT * node); // Rebalanceo
		// Rotaciones simples. Las rotaciones dobles se realizan combinando las simples
		void leftRotate(const NodeBT * x, const NodeBT * y);
		void rightRotate(const NodeBT * x, const NodeBT * y);
};

#endif