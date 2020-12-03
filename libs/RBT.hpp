#ifndef RBT_HPP
#define RBT_HPP
#include <iostream>
#include "RBT_Node.hpp"
using namespace std;

class RBT{
	private:
		RBT_node * root;
		int nodes; // Cantidad de nodos no nulos
		void printTree(const NodeBT * r, unsigned int level);
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