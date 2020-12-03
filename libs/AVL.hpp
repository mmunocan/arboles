#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include "AVL_Node.hpp"
using namespace std;

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
		void insertFixup(vector<AVL_node*> * path); // Rebalanceo
		// Rotaciones simples. Las rotaciones dobles se realizan combinando las simples
		void leftRotate(const NodeBT * x, const NodeBT * y);
		void rightRotate(const NodeBT * x, const NodeBT * y);
};

#endif