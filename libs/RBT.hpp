#ifndef RBT_HPP
#define RBT_HPP
#include <iostream>
#include "RBT_Node.hpp"
using namespace std;

class RBT{
	private:
		RBT_node * root;
		int nodes; // Cantidad de nodos no nulos
		unsigned int treeBlackHeight;
		void printTree(const NodeBT * r, unsigned int level);
		void insertFixup(RBT_node * node);
		RBT_node* getUncle(const RBT_node* node);
	public:
		RBT();
		~RBT();
		void insert(int x);
		bool isInserted(int x);
		void printTree();
		bool leftRotation(int x);
		bool rightRotation(int y);
		int altura();
};

#endif