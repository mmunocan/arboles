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
	public:
		RBT();
		~RBT();
		void insert(int x);
		bool isInserted(int x);
		void printTree();
		bool leftRotation(int x);
		bool rightRotation(int y);
};

#endif