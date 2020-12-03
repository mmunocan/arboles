#ifndef RBT_HPP
#define RBT_HPP
#include <iostream>
#include "NodeBT.hpp"
using namespace std;

class RBT_node : public NodeBT{
	public:
		bool isBlack; // false = red, true = black
		unsigned int blackHeight;
		RBT_node(int x);
		~RBT_node();
		// Agregar otras variables de ser necesario
};

class RBT{
	private:
		RBT_node * root;
		int nodes; // Cantidad de nodos no nulos
		void printTree(const NodeBT * r, unsigned int level);
		void printNode(const NodeBT * node);
		// Extraido del libro de Cormen pg 312-316
		void insertFixup(const RBT_node * node);
		void leftRotate(const RBT_node * x, const RBT_node * y);
		void rightRotate(const RBT_node * x, const RBT_node * y);
	public:
		RBT();
		~RBT();
		void insert(int x);
		bool isInserted(int x);
		void printTree();
};

#endif