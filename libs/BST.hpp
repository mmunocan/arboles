#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include "NodeBT.hpp"
using namespace std;

class BST{
	private:
		NodeBT * root;
		int nodes;
		void printTree(const NodeBT * r, unsigned int level);
		void printNode(const NodeBT * node);
	public:
		BST();
		~BST();
		void insert(int x);
		bool isInserted(int x);
		void printTree();
};

#endif